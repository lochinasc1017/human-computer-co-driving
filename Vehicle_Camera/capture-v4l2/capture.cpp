#include <opencv2/opencv.hpp>  
#include <iostream>  
#include <stdio.h>
  
int main()  
{ 
    char file_name[128];	
    cv::VideoCapture capture; 
    char t_str[32];
    struct timespec ts;

    capture.open(0);
    if (!capture.isOpened())  
    {  
        std::cout << "Read video Failed !" << std::endl;  
        return 0;  
    }  
  
    cv::Mat frame;  
    cv::namedWindow("video test");  
  
    while(1)
    {  
        capture >> frame;  
        //capture.read(frame);
        imshow("video test", frame);  
        if (cv::waitKey(30) == 'q')  
        {  
            break;  
        }  
        if (cv::waitKey(30) == 's')  
        {  
            clock_gettime(CLOCK_REALTIME, &ts);
	    strftime(t_str, sizeof(t_str), "%Y%m%d_%H%M%S", localtime(&ts.tv_sec));
	    sprintf(file_name, "%s_%06ld.jpg", t_str, ts.tv_nsec/1000);
            cv::imwrite(file_name, frame); 
        }  
    }  
  
    cv::destroyWindow("video test");  
    capture.release();  
    return 0;  
}
