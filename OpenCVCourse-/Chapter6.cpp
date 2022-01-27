#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//////////// Color Dectetion

Mat imgHSV, mask;
int hmin(0), smin(0), vmin(0);
int hmax(179), smax(255), vmax(255);


void main() {



	string pathName("Resources/shapes.png"); // Grabbing image path 
	Mat img = imread(pathName); 
	
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (600, 800));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img); // Displaying our image using openCV
		imshow("HSV", imgHSV);
		imshow("Mask", mask);

		waitKey(1); // Freezing program to view our image
	}

}
