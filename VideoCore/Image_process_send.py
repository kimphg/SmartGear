import cv2
from cv2 import TrackerKCF
# import torch
import socket
# import struct
# import pickle
import time 
from ultralytics import YOLO
from vidstab import VidStab
# Tải mô hình YOLOv10
# model = YOLO('best.pt')
model = YOLO("yolov10s.pt")
tracker = TrackerKCF.create()
model.to("cuda")
udp_ip = "127.0.0.1"
udp_port = 12345
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
MAX_PACKET_SIZE = 65450  
import socket
# import pickle
# import struct
import cv2
def send_frame(frame,frame_counter, address):
    ret, buffer = cv2.imencode('.jpeg', frame,[cv2.IMWRITE_JPEG_QUALITY, 90])
    if not ret:
        print("Failed to encode image")
        return

    data = buffer.tobytes()
 
    num_chunks = (len(data) // MAX_PACKET_SIZE) + 1
    if(num_chunks>10):
        return #frame too big
    for i in range(num_chunks):
        rList = [i,frame_counter]
        chunk_header = bytes(rList)
        chunk = data[i * MAX_PACKET_SIZE:(i + 1) * MAX_PACKET_SIZE]
        sock.sendto(chunk_header + chunk, address)
    

    print(f"Sent frame with size {len(data)} bytes")

# stabilizer = VidStab()
# cap = cv2.VideoCapture(0)
# cap = cv2.VideoCapture("D:/VIDEO/rec_03.12_07.05.34.avi")
cap = cv2.VideoCapture("D:/VIDEO/rec_03.10_01.00.19.avi")

# cap = cv2.VideoCapture("tracking compilation.mp4")
frame_width = int(cap.get(3)) 
frame_height = int(cap.get(4)) *2
   
size = (frame_width, frame_height) 
frame_counter=0
prev_frame_time =0
# print(model.names)
# result = cv2.VideoWriter('filename.mp4',  
#                          cv2.VideoWriter_fourcc(*'MP4V'), 
#                          20, size) 
# class trackObject
import numpy as np
import math
count =0
ret,oldframe = cap.read()
# cv2.imshow('Original', oldframe)
oldframe =oldframe.astype(float)
tracker_running = False

while cap.isOpened():
    ret, frame = cap.read()
    cv2.imshow('Original', frame)
    
    # print(oldframe)
    
    if not ret:
        break
    if(tracker_running):
        ok, roi = tracker.update(frame)
        
    # frame =frame.astype(float)
    # cv2.accumulate(oldframe,frame)
    # frame = frame*0.5
    # oldframe = frame
    # # frame = stabilizer.stabilize_frame(input_frame=frame,smoothing_window=30)
    # # frame = cv2.equalizeHist(frame)
    # frame =frame.astype(np.uint8)
    img_y_cr_cb = cv2.cvtColor(frame, cv2.COLOR_BGR2YCrCb)
    y, cr, cb = cv2.split(img_y_cr_cb)

    # Applying equalize Hist operation on Y channel.
    y = cv2.equalizeHist(y)
    # kernel = np.array([[0, 0,0.2,0,0],[0, 0,0.2,0,0], [0, 0,0.2,0,0],[0, 0,0.2,0,0],[0, 0,0.2,0,0]]) 
    #Sharpen the image
    # y = cv2.filter2D(y, -1, kernel) 
    # y = denoise_lines(y)
    # cr = denoise_lines(cr)
    # cb = denoise_lines(cb)
    # y = cv2.Laplacian(y, cv2.CV_8U) 
    img_y_cr_cb_eq = cv2.merge((y, cr, cb))
    frame = cv2.cvtColor(img_y_cr_cb_eq, cv2.COLOR_YCR_CB2BGR)
    results = model(frame)
    detections = results[0].boxes
    # print(model.names)
    list_classes = {0,2,3,4,8}
    
    for box in detections:
        x1, y1, x2, y2 = map(int, box.xyxy[0])
        conf = box.conf[0]
        cls = int(box.cls[0])
        if(abs(x1-x2)>20):
            cv2.rectangle   (frame, (x1, y1), (x2, y2), (255, 0, 0), 2)
            cv2.putText     (frame, model.names[cls], (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)
    # font which we will be using to display FPS 
    # #  
    if(tracker_running):
        cv2.rectangle( frame, roi, ( 255, 0, 0 ), 2 )
    font = cv2.FONT_HERSHEY_SIMPLEX 
    new_frame_time = time.time() 
    if(new_frame_time==prev_frame_time):
        continue
    fps = 1/(new_frame_time-prev_frame_time) 
    prev_frame_time = new_frame_time 
  
    # converting the fps into integer 
    fps = int(fps) 
  
    # converting the fps to string so that we can display it on frame 
    # by using putText function 
    fps = str(fps) 
  
    # putting the FPS count on the frame 
    cv2.putText(frame, fps, (7, 70), font, 1, (30, 70, 0), 1, cv2.LINE_AA)
    # im_v = cv2.vconcat([inframe, frame]) 
    # cv2.imshow('Detection', frame)
    # result.write(im_v)
    send_frame(frame,frame_counter, (udp_ip, udp_port))
    frame_counter=frame_counter+1
    if(frame_counter>=255):
        frame_counter=0
    if cv2.waitKey(10) & 0xFF == ord('q'):
        break
    if cv2.waitKey(10) & 0xFF == ord('t'):
        roi = cv2.selectROI('Original', frame)
        print(roi)
        tracker.init(frame,roi)
        tracker_running = True

# result.release() 
cap.release()
cv2.destroyAllWindows()
