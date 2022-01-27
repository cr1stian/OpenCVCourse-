#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


////////////// Basic Functions

void main() {

	string pathName("Resources/test.jpg"); // Grabbing image path 
	Mat img = imread(pathName); // Setting image to Mat object used for images in openCV
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;


	cvtColor(img, imgGray , COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3,3), 5, 0);
	Canny(imgBlur, imgCanny, 50, 100);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);

	imshow("Image", img); // Displaying our image using openCV
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Imgae Dilation", imgDil);

	waitKey(0); // Freezing program to view our image


}

