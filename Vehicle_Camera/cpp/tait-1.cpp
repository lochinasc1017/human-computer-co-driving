include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/ml/ml.hpp>
#include <iostream>
#include <windows.h>  
#include <stdio.h>
using namespace cv;
using namespace std;
 
int main()
{
	namedWindow("src",1);
	namedWindow("dst", 1);
	namedWindow("sfMat", 1);
	namedWindow("dstImage", 1);
 
	//原图
	Mat src = imread("325.jpg", IMREAD_COLOR);
	imshow("src", src);
 
	//图像裁剪
	int nX = 200;
	int nY = 330;
	int nW = 100;
	int nH = 100;
	cv::Rect rect(nX, nY, nW, nH);
	Mat dst = src(rect);
	imshow("dst", dst);
 
	//图像缩放
	Mat sfMat;
	cv::resize(src, sfMat, cv::Size((src.cols*0.5), (src.rows*0.5)), 0, 0, cv::INTER_NEAREST);
	imshow("sfMat", sfMat);
 
	//图像特定区域裁剪
	Mat dstImage = Mat::zeros(src.rows+100, src.cols+100, CV_8UC3);   //创建一个的图像
	cv::Rect roi_rect0 = cv::Rect(0, 0, src.cols, src.rows);
	src.copyTo(dstImage(roi_rect0));
	imshow("dstImage", dstImage);
 
	waitKey(0);
	return 0;
}
