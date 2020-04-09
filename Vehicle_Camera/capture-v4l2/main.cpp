#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#include "videoCapture.h"

int main(){
	hl::VideoCapture cap;
        unsigned char *ptrf_cam_frame;
        int bytes_used;
	cv::Mat rgb_frame;
	cv::Mat rgb_tl;
	
	
	
	cap.init_cam(0, 2560, 800, V4L2_PIX_FMT_UYVY, IO_METHOD_USERPTR);
	cv::Mat uyvy_frame(800, 2560, CV_8UC2);

	while(1){
		cap.get_cam_frame(&ptr_cam_frame, &bytes_used);
		uyvy_frame.data = ptr_cam_frame;

		cv::cvtColor(uyvy_frame, rgb_frame, CV_YUV2BGRA_UYVY);
		cv::namedWindow( "Display window", CV_WINDOW_AUTOSIZE);
		flip(rgb_frame,rgb_frame,1) //沿y轴旋转，０为沿x轴
		cv::imshow( "Display window",rgb_frame);
		
		//左图像裁剪
		cv::Rect rect(0, 0, 1280, 800);
		rgb_tl = rgb_frame(rect);
		
		
		//保存图像
		
		                  
		cv::waitKey(1);
		
    		cap.release_cam_frame();
	}

	return 0;
}
