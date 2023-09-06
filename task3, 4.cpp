#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//¿­¸², ´ÝÈû ¿¬»ê
int main() {
	Mat src, dst, open, close, opening, closing;
	src = imread("../../images/letterb.png", IMREAD_GRAYSCALE);

	Mat saltpepper_noise = Mat::zeros(src.rows, src.cols, CV_8U);
	randu(saltpepper_noise, 0, 255);

	Mat black = saltpepper_noise < 30;
	Mat white = saltpepper_noise > 225;
	Mat saltpepper_img = src.clone();

	saltpepper_img.setTo(255, white);
	saltpepper_img.setTo(0, black);
	imshow("Test", saltpepper_img);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));

	morphologyEx(saltpepper_img, open, MORPH_OPEN, element);
	imshow("Open", open);

	erode(saltpepper_img, opening, element);
	dilate(opening, opening, element);
	imshow("Opening", opening);

	morphologyEx(saltpepper_img, close, MORPH_CLOSE, element);
	imshow("Close", close);

	dilate(saltpepper_img, closing, element);
	erode(closing, closing, element);
	imshow("Closing", closing);

	waitKey(0);
	return 0;
}


//Ä§½Ä, ÆØÃ¢ ¿¬»ê
/*
int main() {
	Mat src, dst, erosion_dst, dilation_dst;
	src = imread("testimg.jpg", IMREAD_GRAYSCALE);

	threshold(src, dst, 127, 255, THRESH_BINARY);
	imshow("Threshold", dst);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	erode(dst, erosion_dst, element);
	imshow("Erode 1st", erosion_dst);

	erode(erosion_dst, erosion_dst, element);
	imshow("Erode 2ed", erosion_dst);

	dilate(dst, dilation_dst, element);
	imshow("Dilate 1st", dilation_dst);

	dilate(dilation_dst, dilation_dst, element);
	imshow("Dilate 2ed", dilation_dst);

	waitKey(0);
	return 0;
}
*/