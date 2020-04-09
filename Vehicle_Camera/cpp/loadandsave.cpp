/*****************************************************
**		第二讲 图像读取、显示、保存等基本操作
*****************************************************/
 
// #include "cv.h"
// #include "highgui.h"
#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
// #include <opencv2/imgproc.hpp>



 #include <opencv2/imgproc/imgproc.hpp>
 
using namespace std;
using namespace cv;
 
int main(int argc, char * argv[])
{
	Mat image;		//定义一个图像对象
	image = imread("/home/shanchuan/project/cpp/pic.jpg");	//读取图像
 
	if (!image.data)		//判断图像载入是否成功
	{
		cout << "Fail to load image!!" << endl;
		system("pause");
		return 0;
	}
 
	Mat src1;
	image.copyTo(src1);		//将图像image深拷贝到src1中
	flip(src1, src1, 1);	//对图像进行翻转
	namedWindow("src1");	//创建窗口src1
	imshow("src1", src1);	//在窗口src1中显示翻转后的图像
 
 
	namedWindow("my");		//创建窗口My
	imshow("my", image);	//在窗口my中显示image图像
	int key=waitKey(0);		//等待按键的输入
 
	imwrite("my.jpg", image);	//	将image图像保存为my.jpg
	
 
	cout << "Size of image is: " << image.size().height << ", " //获得图像的高，宽等尺寸
		<< image.size().width << endl;
	cout << "ASCII of the key is: " << key << endl;
 
	/******************自己定义图像对象***********************/
	//Mat image(200, 100, CV_8UC1, Scalar(100));
	//Mat src;
	//src = image;	//浅拷贝，src和image共用同一片内存
	////image.copyTo(src);//深拷贝，各自占用一块内存区域，对src的操作不会影响image
 
	system("pause");
	return 0;
}
