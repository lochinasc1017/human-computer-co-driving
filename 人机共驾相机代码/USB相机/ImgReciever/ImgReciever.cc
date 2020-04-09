#include "ImgReciever.hh"
#include <math.h>
#include "opencv2/opencv.hpp"
#include <fstream>
#include "_timer.h"
#include <time.h>
#include <sys/time.h>
#include "stdio.h"
#include <opencv/cv.h>

void RADARRECIEVER_MODULE::PRE_PROCESS()
{
    img_msg = new COLORIMAGE_MSG();
    INITIALIZE_NML();
//    std::cout<<"here3"<<std::endl;
    cv::VideoCapture capture;
    capture.open(0);
    if (!capture.isOpened())
    {
        std::cout << "Read video Failed !" << std::endl;
        exit(1) ;
    }

    capture.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
//    capture.set(CV_CAP_PROP_FPS, 30);
    int img_width,img_height;
     img_width= capture.get(CV_CAP_PROP_FRAME_WIDTH);
     img_height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
     std::cout<<"width="<<img_width<<std::endl;
     std::cout<<"height="<<img_height<<std::endl;


     cv::Mat Image_flip;
     cv::Mat Image_mat;
     cv::namedWindow("Video Front");
     img_msg->MessageSeqNum = 0;
     long int ti;
     timeval curT;
    while (1)
    {
        capture >> Image_mat;
        cv::flip(Image_flip, Image_mat, -1);
        if(!Image_mat.empty())
        {
            cv::imshow("Video Front", Image_mat);
        }
        cv::waitKey(20);

        gettimeofday(&curT,NULL);
        ti = curT.tv_sec*1000 + curT.tv_usec/1000;
        img_msg->local_PC_time= ti;
        img_msg->MessageSeqNum++;
        memcpy(img_msg->ImageBuffer,Image_mat.data,
               sizeof(unsigned char) * Image_mat.cols * Image_mat.rows * Image_mat.channels());

       int write_ret = COLORIMAGE_CHANNEL->write(img_msg);
       std::cout<<"write_ret="<<write_ret<<std::endl;

    }

}


void RADARRECIEVER_MODULE::POST_PROCESS()
{

}

void RADARRECIEVER_MODULE::INITIALIZE_NML()
{
    COLORIMAGE_CHANNEL = new NML(ColorImageFormat, "ColorImage", "ImgReciever", "/home/shanchuan/UGV_302_img/bin/UGVAuto.nml");
}

void RADARRECIEVER_MODULE::displayCamData()
{

}




