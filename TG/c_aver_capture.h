#ifndef C_AVER_CAPTURE_H
#define C_AVER_CAPTURE_H

#include "Windows.h"

#include "AVerCapAPI_Pro.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
class c_aver_capture
{
public:
    c_aver_capture();
    bool getFrame(cv::Mat *frame);
};

#endif // C_AVER_CAPTURE_H
