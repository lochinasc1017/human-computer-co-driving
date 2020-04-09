#include "stdafx.h"
#include <highgui.h>  
#include <cxcore.h>  
#include "math.h"
#include <cv.h>  
#include "iostream"
using namespace std;
const char* filename1 = "C:\\Users\\Administrator\\Desktop\\hu\\English.tif";
int main(int argc, char** argv)
{    
    IplImage    *img;
    IplImage    *img1;
    img = cvLoadImage(filename1, CV_LOAD_IMAGE_COLOR);
    cvNamedWindow("img", CV_WINDOW_AUTOSIZE);
    cvShowImage("img", img);
    CvRect rectInImage;
    rectInImage = cvRect(0, 0, img->width, img->height*0.2);
    CvSize size;
    size.width = rectInImage.width;
    size.height = rectInImage.height;
    img1 = cvCreateImage(size, img->depth, img->nChannels);
    cvSetImageROI(img, rectInImage);//基于给定的矩形设置图像的ROI
    cvCopy(img, img1);
    cvNamedWindow("img1", CV_WINDOW_AUTOSIZE);
    cvShowImage("img1", img1);
    cvResetImageROI(img);
    cvWaitKey(0);
    return 0;
}
