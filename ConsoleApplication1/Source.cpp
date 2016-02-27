#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include"iostream"
#include"conio.h"

using namespace std;
using namespace cv;

int WinMain()
{
	Mat img = imread("E:/Study_Material/Semester_6/MinorProject/Car_Dataset/10.jpg", CV_LOAD_IMAGE_COLOR);
	Mat dst;
	Mat can;
	Mat afterCan;
	//Mat bluCan;
	namedWindow("Display");
	Size size(700, 500);
	resize(img, dst, size);
	//blur(InputArray(can), OutputArray(bluCan), Size(5, 5));
	Canny(InputArray(dst), OutputArray(can), double(600), double(700));
	//Mat img_threshold;
	//threshold(bluCan, img_threshold, 0, 255, THRESH_OTSU + THRESH_BINARY);
	Mat element = getStructuringElement(MORPH_RECT, Size(50, 10));
	morphologyEx(can, afterCan, CV_MOP_CLOSE, element);
	imshow("Display", afterCan);
	waitKey(0);
	_getch();
	return 0;
}