/*
//6�� ����
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

//10�� ����
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int startx, starty, endx, endy;
double alpha = 2.0; //��� 
int beta = 50; //��Ⱚ

void onMouse(int event, int x, int y, int flags, void* param) {
	Mat& img = *(Mat*)param; //Mat ������

	if (event == EVENT_LBUTTONDOWN) { //���� ���콺 ��ư ������
		startx = x;
		starty = y;
	}
	else if (event == EVENT_LBUTTONUP) { //���� ���콺 ��ư ����
		endx = x;
		endy = y;
		Rect r(Point(startx,starty), Point(endx, endy)); //���ɿ��� ����
		Mat tmp = img(r); //�巡���� �簢�� ����

		for (int i = startx; i < endx; i++) {
			for (int j = starty; j < endy; j++) {
				for (int c = 0; c < 3; c++) {
					img.at<Vec3b>(j, i)[c] = saturate_cast<uchar>(alpha * (img.at < Vec3b>(j, i)[c]) + beta); //��� ����
				}
			}
		}
		imshow("New image", tmp);
	}
}

int main()
{
	Mat image = imread("Lenna.jpg", 1); //�÷� ���� ����
	if (image.empty()) {
		cout << "ERROR\n";
		return -1;
	}
	imshow("Image", image); //���� ���

	
	setMouseCallback("Image", onMouse, &image); //���콺 �̺�Ʈ
	
	waitKey(0);
	return 0;
}