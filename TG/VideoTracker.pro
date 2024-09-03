#-------------------------------------------------
#
# Project created by QtCreator 2021-05-05T18:54:09
#
#-------------------------------------------------

QT       += core gui network serialport serialbus printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoGrab
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    c_gimbal_control.cpp \
    c_aver_capture.cpp \
    c_config.cpp \
    kcf/gradientMex.cpp \
    kcf/kcf.cpp \
    dialogconfig.cpp \
    qcgaugewidget.cpp \
    c_lowpass.cpp \
    UsbDevice.cpp \
    qcustombutton.cpp \
    videostab.cpp
#LIBS += "AVerCapAPI.lib"
LIBS += "AVerCapAPI_x64.lib"
#LIBS += -L$$PWD/AverCap/ -lAVerCapAPI
LIBS += -L$$PWD/AverCap/ -lAVerCapAPI_x64

HEADERS  += \
    mainwindow.h \
    c_gimbal_control.h \
    c_aver_capture.h \
    c_config.h \
    kcf/fhog.hpp \
    kcf/gradientMex.h \
    kcf/kcf.hpp \
    kcf/sse.hpp \
    kcf/wrappers.hpp \
    dialogconfig.h \
    qcgaugewidget.h \
    c_lowpass.h \
    UsbDevice.h \
    qcustombutton.h \
    videostab.h

FORMS    += mainwindow.ui \
    dialogconfig.ui
INCLUDEPATH += "C:/opencv/opencv2411/build/include"
win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_core2411d
win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_highgui2411d
win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_imgproc2411d
win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_calib3d2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_contrib2411d
win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_core2411d
win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_features2d2411d
win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_flann2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_gpu2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_legacy2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_ml2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_nonfree2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_objdetect2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_ocl2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_photo2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_stitching2411d
#win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_superres2411d
win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_video2411d
win32:CONFIG(debug, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_videostab2411d
#release:
#win32:CONFIG(release, debug|release):LIBS += -L$$PWD/../opencv/build/x64/vc10/lib/ -lopencv_core2411
win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_core2411
win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_highgui2411
win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_imgproc2411
win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_calib3d2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_contrib2411
win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_core2411
win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_features2d2411
win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_flann2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_gpu2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_legacy2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_ml2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_nonfree2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_objdetect2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_ocl2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_photo2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_stitching2411
#win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_superres2411
win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_video2411
win32:CONFIG(release, debug|release):LIBS += -L"C:/opencv/opencv2411/build/x64/vc12/lib/" -lopencv_videostab2411
#win32:LIBS += ws2_32.lib
RC_ICONS = icon.ico
win32 {
DESTDIR = $$PWD/bin
QMAKE_POST_LINK =  "C:/Qt/Qt5.14.2/5.14.2/msvc2017_64/bin/windeployqt.exe" $$shell_path($$DESTDIR/$${TARGET}.exe)
}
