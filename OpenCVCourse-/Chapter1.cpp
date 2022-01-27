#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


////////////// Images

//void main() {
//
//	string pathName("Resources/test.png"); // Grabbing image path 
//	Mat img = imread(pathName); // Setting image to Mat object used for images in openCV
//	imshow("Image", img); // Displaying our image using openCV
//	waitKey(0); // Freezing program to view our image
//
//
//}

////////////// Video

//void main() {
//
//	string pathName("Resources/test_video.mp4"); 
//	VideoCapture cap(pathName);
//	Mat img;
//
//	while ( true ) {
//
//
//		cap.read(img);
//		 
//		
//		imshow("Image", img); // Displaying our image using openCV
//		waitKey(20); // Freezing program to view our image
//
//	}
//}


////////////// Webcam

void main() {

	VideoCapture cap(0); // Selecting Camera  
	Mat img;

	while ( true ) {


		cap.read(img);


		imshow("Image", img); // Displaying our image using openCV
		waitKey(1); // Freezing program to view our image

	}
}