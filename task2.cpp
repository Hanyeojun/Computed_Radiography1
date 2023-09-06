#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main() {
	Mat src= imread("../../images/Lenna.jpg", IMREAD_GRAYSCALE); //�̹��� ���� ����
	
	
	float weights[] = {
		1/9.0F,1 / 9.0F,1 / 9.0F,
		1 / 9.0F,1 / 9.0F,1 / 9.0F,
		1 / 9.0F,1 / 9.0F,1 / 9.0F

	};

	Mat mask(3, 3, CV_32F, weights); //2���� �迭���� ������ Mat ��ü ����
	Mat blur; //��� �����

	filter2D(src, blur, -1, mask, Point(-1, -1), (0,0), BORDER_REPLICATE); //������� ����
  //filter2D(�Է¿���, ������� ��� ����, �������, ��� ����ũ, �߽��� ��ġ, 
	//������� �Ŀ� ��� ȭ�ҿ� �߰��Ǵ� ��, ���� �����ڸ� ȭ�� ó��)

	blur.convertTo(blur, CV_8U); //��� Ÿ�� ��ȯ
	imshow("image", src); //���� ���� ���
	imshow("blur", blur); //���͸��� ���� ���

	waitKey(0);
	return 0;
}
//int main()
//{
//	Mat src = Mat_<uchar>({ 3, 3 }, { 3, 6, 1, 2, 1, 1, 4, 0, 3 });
//	Mat dst(src.size(), CV_8U, Scalar(0));
//	cout << src << endl << endl;
//
//	// (1, 1)���� (rows-1, cols-1) ������ ȭ�Ҹ� ó��
//	for (int y = 1; y < src.rows - 1; y++) {
//		for (int x = 1; x < src.cols - 1; x++) {
//			int sum = 0;
//			sum += src.at<uchar>(y - 1, x - 1); sum += src.at<uchar>(y, x - 1); sum += src.at<uchar>(y + 1, x - 1); sum += src.at<uchar>(y - 1, x); sum += src.at<uchar>(y, x);
//			sum += src.at<uchar>(y + 1, x); sum += src.at<uchar>(y - 1, x + 1); sum += src.at<uchar>(y, x + 1); sum += src.at<uchar>(y + 1, x + 1); dst.at<uchar>(y, x) = sum / 9;
//		}
//	}
//
//	cout << dst;
//
//	waitKey(0);
//}