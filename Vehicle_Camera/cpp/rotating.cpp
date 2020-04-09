#include <highgui.h>  
#include <cxcore.h>  
#include "math.h"
#include <cv.h>  
#include "iostream"
using namespace std;
const char* filename1 = "C:\\Users\\Administrator\\Desktop\\hu\\lenna.jpg";
int main(int argc, char** argv)
{
    IplImage    *img;
    IplImage    *img1;
    img = cvLoadImage(filename1, CV_LOAD_IMAGE_COLOR);
    cvNamedWindow("img", CV_WINDOW_AUTOSIZE);
    cvShowImage("img", img);
    CvSize size;
    size.width = img->width;
    size.height = img->height;
    img1 = cvCreateImage(size, img->depth, img->nChannels);
    //旋转中心为图像中心
    CvPoint2D32f center;
    center.x = float(img->width / 2.0 + 0.5);
    center.y = float(img->height / 2.0 + 0.5);
    //计算二维旋转的仿射变换矩阵  
    float m[6];
    CvMat M = cvMat(2, 3, CV_32F, m);
    cv2DRotationMatrix(center, 180, 1, &M);
    cvWarpAffine(img, img1, &M, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll(0));
    cvNamedWindow("img1", CV_WINDOW_AUTOSIZE);
    cvShowImage("img1", img1);
    cvWaitKey(0);
    return 0;
}
