#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main() {
	Mat src = imread("hitmissinput.png", IMREAD_GRAYSCALE);
	threshold(src, src, 127, 255, THRESH_BINARY);
	//imshow("src", src);
	Mat img = imread("hitmissinput.png", IMREAD_COLOR);

	Mat b1 = imread("e.png", IMREAD_GRAYSCALE);
	threshold(b1, b1, 127, 255, THRESH_BINARY);
	//imshow("e", b1);

	Mat dst;

	for (int i = 0; i < b1.rows; i++) {
		for (int j = 0; j < b1.cols; j++) {
			if (b1.at<uchar>(i, j) > 0) {
				b1.at<uchar>(i, j) = 1;
			}
		}
	}

	morphologyEx(src, dst, MORPH_HITMISS, b1);
	//imshow("dst", dst);

	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			if (dst.at<uchar>(i, j) == 255) {
				circle(img, Point(j, i), 15, Scalar(0, 0, 255), 2);
			}
		}
	}
	imshow("Result", img);
	waitKey(0);
	return 0;
}