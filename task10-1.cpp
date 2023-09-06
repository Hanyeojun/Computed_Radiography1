#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat src;
Mat dst, detected_edges;
Mat thresdst;
int lowThreshold = 50, highThreshold = 150, kernel_size = 3;

static void CannyThreshold(int, void*) {
	GaussianBlur(src, detected_edges, Size(3, 3), 0, 0); //가우시안 필터링
	Canny(detected_edges, detected_edges, lowThreshold, highThreshold, kernel_size); //캐니 에지 검출

	dst = Scalar::all(0); //dst 초기화
	src.copyTo(dst, detected_edges); //복사
	
	imshow("Image", src); //입력 영상 출력
	imshow("Canny", dst); //에지 영상 출력
}

int main() {
	double canny_sum = 0, thres_sum = 0;
	src = imread("coins.jpg", IMREAD_GRAYSCALE); //영상 입력

	dst.create(src.size(), src.type()); //dst 객체 초기화
	namedWindow("Canny", WINDOW_AUTOSIZE); //윈도우 생성

	CannyThreshold(0, 0); //에지 검출 함수 호출

	threshold(dst, thresdst, 100, 255, THRESH_BINARY); //이진화

	imshow("threshold", thresdst); //이진화 영상 출력

	canny_sum = dst.rows * dst.cols;
	thres_sum = thresdst.rows * thresdst.cols;
	
	cout << "캐니 에지 검출 영상 픽셀 개수 : " << canny_sum << '\n';
	cout << "이진화 영상 픽셀 개수 : " << thres_sum;

	waitKey(0);
	return 0;
}

/*
	Mat input = imread("coins.jpg", IMREAD_GRAYSCALE);
	Mat output;
	GaussianBlur(input, output, Size(5, 5), 0, 0); //가우시안 필터링
	Canny(output, output, lowThreshold, highThreshold, kernel_size);
	imshow("image", input); //입력 영상 출력
	imshow("canny edge", output); //에지 영상 출력
*/


//11번
/*
	Mat src = imread("noise.jpg"); //입력 영상 저장 객체
	Mat mean; //평균값 필터링 영상 저장 객체
	Mat gaussian;
	double gaussian_sum = 0, mean_sum = 0;

	blur(src, mean, Size(7, 7)); //평균값 필터링

	GaussianBlur(src, gaussian, Size(7, 7), 0, 0); //가우시안 필터링

	for (int i = 0; i < mean.rows; i++) {	//평균값 필터링 영상의 전체 픽셀값의 합
		for (int j = 0; j < mean.cols; j++) {
			mean_sum += mean.at<uchar>(i, j);
		}
	}
	for (int i = 0; i < gaussian.rows; i++) {	//가우시안 필터링 영상의 전체 픽셀값의 합
		for (int j = 0; j < gaussian.cols; j++) {
			gaussian_sum += gaussian.at<uchar>(i, j);
		}
	}

	double mean_avg = mean_sum / (mean.rows * mean.cols);	//평균값 필터링 영상 평균 픽셀값
	double gaussian_avg = gaussian_sum / (gaussian.rows * gaussian.cols);	//가우시안 필터링 영상 평균 픽셀값

	cout << "평균값 필터링 영상의 평균 픽셀값 : " << mean_avg << '\n';
	cout << "가우시안 필터링 영상의 평균 픽셀값 : " << gaussian_avg << '\n';

	imshow("src", src); //원본 영상 출력
	imshow("mean Blur", mean); // 평균값 필터링 적용 영상 출력
	imshow("gaussian Blur", gaussian); // 가우시안 필터링 적용 영상 출력

*/

//21번
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