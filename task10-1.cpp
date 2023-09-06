#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat src;
Mat dst, detected_edges;
Mat thresdst;
int lowThreshold = 50, highThreshold = 150, kernel_size = 3;

static void CannyThreshold(int, void*) {
	GaussianBlur(src, detected_edges, Size(3, 3), 0, 0); //����þ� ���͸�
	Canny(detected_edges, detected_edges, lowThreshold, highThreshold, kernel_size); //ĳ�� ���� ����

	dst = Scalar::all(0); //dst �ʱ�ȭ
	src.copyTo(dst, detected_edges); //����
	
	imshow("Image", src); //�Է� ���� ���
	imshow("Canny", dst); //���� ���� ���
}

int main() {
	double canny_sum = 0, thres_sum = 0;
	src = imread("coins.jpg", IMREAD_GRAYSCALE); //���� �Է�

	dst.create(src.size(), src.type()); //dst ��ü �ʱ�ȭ
	namedWindow("Canny", WINDOW_AUTOSIZE); //������ ����

	CannyThreshold(0, 0); //���� ���� �Լ� ȣ��

	threshold(dst, thresdst, 100, 255, THRESH_BINARY); //����ȭ

	imshow("threshold", thresdst); //����ȭ ���� ���

	canny_sum = dst.rows * dst.cols;
	thres_sum = thresdst.rows * thresdst.cols;
	
	cout << "ĳ�� ���� ���� ���� �ȼ� ���� : " << canny_sum << '\n';
	cout << "����ȭ ���� �ȼ� ���� : " << thres_sum;

	waitKey(0);
	return 0;
}

/*
	Mat input = imread("coins.jpg", IMREAD_GRAYSCALE);
	Mat output;
	GaussianBlur(input, output, Size(5, 5), 0, 0); //����þ� ���͸�
	Canny(output, output, lowThreshold, highThreshold, kernel_size);
	imshow("image", input); //�Է� ���� ���
	imshow("canny edge", output); //���� ���� ���
*/


//11��
/*
	Mat src = imread("noise.jpg"); //�Է� ���� ���� ��ü
	Mat mean; //��հ� ���͸� ���� ���� ��ü
	Mat gaussian;
	double gaussian_sum = 0, mean_sum = 0;

	blur(src, mean, Size(7, 7)); //��հ� ���͸�

	GaussianBlur(src, gaussian, Size(7, 7), 0, 0); //����þ� ���͸�

	for (int i = 0; i < mean.rows; i++) {	//��հ� ���͸� ������ ��ü �ȼ����� ��
		for (int j = 0; j < mean.cols; j++) {
			mean_sum += mean.at<uchar>(i, j);
		}
	}
	for (int i = 0; i < gaussian.rows; i++) {	//����þ� ���͸� ������ ��ü �ȼ����� ��
		for (int j = 0; j < gaussian.cols; j++) {
			gaussian_sum += gaussian.at<uchar>(i, j);
		}
	}

	double mean_avg = mean_sum / (mean.rows * mean.cols);	//��հ� ���͸� ���� ��� �ȼ���
	double gaussian_avg = gaussian_sum / (gaussian.rows * gaussian.cols);	//����þ� ���͸� ���� ��� �ȼ���

	cout << "��հ� ���͸� ������ ��� �ȼ��� : " << mean_avg << '\n';
	cout << "����þ� ���͸� ������ ��� �ȼ��� : " << gaussian_avg << '\n';

	imshow("src", src); //���� ���� ���
	imshow("mean Blur", mean); // ��հ� ���͸� ���� ���� ���
	imshow("gaussian Blur", gaussian); // ����þ� ���͸� ���� ���� ���

*/

//21��
/*
Mat src = imread("plane.jpg");
	Mat mask = Mat::zeros(11, 11, CV_32F);
	Mat dst;

	mask(Range(5, 6), Range(0, 11)) = Mat::ones(Size(11, 1), CV_32F);
	mask /= 11;

	filter2D(src, dst, -1, mask);

	imshow("imgae", src);
	imshow("motion blur", dst);

	waitKey(0);
	return 0;
*/