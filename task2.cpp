#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main() {
	Mat src= imread("../../images/Lenna.jpg", IMREAD_GRAYSCALE); //이미지 영상 저장
	
	
	float weights[] = {
		1/9.0F,1 / 9.0F,1 / 9.0F,
		1 / 9.0F,1 / 9.0F,1 / 9.0F,
		1 / 9.0F,1 / 9.0F,1 / 9.0F

	};

	Mat mask(3, 3, CV_32F, weights); //2차원 배열값을 가지고 Mat 객체 생성
	Mat blur; //결과 저장용

	filter2D(src, blur, -1, mask, Point(-1, -1), (0,0), BORDER_REPLICATE); //컨볼루션 연산
  //filter2D(입력영상, 컨볼루션 결과 영상, 영상깊이, 사용 마스크, 중심점 위치, 
	//컨볼루션 후에 모든 화소에 추가되는 값, 영상 가장자리 화소 처리)

	blur.convertTo(blur, CV_8U); //행렬 타입 변환
	imshow("image", src); //원본 영상 출력
	imshow("blur", blur); //필터링된 영상 출력

	waitKey(0);
	return 0;
}
//int main()
//{
//	Mat src = Mat_<uchar>({ 3, 3 }, { 3, 6, 1, 2, 1, 1, 4, 0, 3 });
//	Mat dst(src.size(), CV_8U, Scalar(0));
//	cout << src << endl << endl;
//
//	// (1, 1)부터 (rows-1, cols-1) 까지의 화소만 처리
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