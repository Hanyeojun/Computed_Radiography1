/*
//6번 문제
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat orgimg = imread("Lenna.jpg", IMREAD_COLOR);
	imshow("Original Image", orgimg);

	Mat table(1, 256, CV_8U);

	uchar* p = table.ptr();
	for (int i = 0; i < 256; ++i) {
		if (i >= 100 && i < 192) {
			p[i] = 0;
		}
		else
			p[i] = i;
	}
	Mat resimg;
	LUT(orgimg, table, resimg);
	imshow("New Image", resimg);
	waitKey(0);
	return 0;
}
*/

//10번 문제
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int startx, starty, endx, endy;
double alpha = 2.0; //대비값 
int beta = 50; //밝기값

void onMouse(int event, int x, int y, int flags, void* param) {
	Mat& img = *(Mat*)param; //Mat 참조자

	if (event == EVENT_LBUTTONDOWN) { //왼쪽 마우스 버튼 누르면
		startx = x;
		starty = y;
	}
	else if (event == EVENT_LBUTTONUP) { //왼쪽 마우스 버튼 떼면
		endx = x;
		endy = y;
		Rect r(Point(startx,starty), Point(endx, endy)); //관심영역 지정
		Mat tmp = img(r); //드래그한 사각형 범위

		for (int i = startx; i < endx; i++) {
			for (int j = starty; j < endy; j++) {
				for (int c = 0; c < 3; c++) {
					img.at<Vec3b>(j, i)[c] = saturate_cast<uchar>(alpha * (img.at < Vec3b>(j, i)[c]) + beta); //밝기 조절
				}
			}
		}
		imshow("New image", tmp);
	}
}

int main()
{
	Mat image = imread("Lenna.jpg", 1); //컬러 영상 저장
	if (image.empty()) {
		cout << "ERROR\n";
		return -1;
	}
	imshow("Image", image); //영상 출력

	
	setMouseCallback("Image", onMouse, &image); //마우스 이벤트
	
	waitKey(0);
	return 0;
}