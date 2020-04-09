#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
// #include <opencv2/imgproc.hpp>
#include <iostream>

#include "videoCapture.h"

int main(){
	
	//Mat rgb_frame;		//定义一个图像对象
	cv::Mat rgb_frame = imread("/home/shanchuan/project/cpp/pic.jpg");	//读取图像
	
	
	
	
	//cap.init_cam(0, 2560, 800, V4L2_PIX_FMT_UYVY, IO_METHOD_USERPTR);
	//cv::Mat uyvy_frame(800, 2560, CV_8UC2);

	cv::namedWindow( "Display window", CV_WINDOW_AUTOSIZE);
	//flip(rgb_frame,rgb_frame,1) //沿y轴旋转，０为沿x轴
	cv::imshow( "Display window",rgb_frame);
		
		//左图像裁剪
	//cv::Rect rect(0, 0, 1280, 800);
	//Mat rgb_tl = rgb_frame(rect);
	//imshow("dst", dst);
		
		
		                  
	cv::waitKey(1);
		
    		
	}

	return 0;
}
