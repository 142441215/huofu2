#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("c://project//smt.png");
	Mat dstMat;
	Canny(srcMat, dstMat, 50, 200, 3);
	vector<Vec4i> lines;
	HoughLinesP(dstMat, lines, 1, CV_PI / 180, 40, 50, 10);
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(srcMat, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,255,0), 1, LINE_AA);
	}
	imshow("src", srcMat);
	waitKey(0);
	return 0;
}
