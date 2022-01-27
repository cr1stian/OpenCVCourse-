#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


////////////// Resize/Crop Images

void main() {

	string pathName("Resources/test.jpg"); // Grabbing image path 
	Mat img = imread(pathName); // Setting image to Mat object used for images in openCV
	Mat imgResize, imgCrop;


	//cout << img.size() << endl;

	resize(img, imgResize, Size(), 0.5,0.5); // Using the 4th paramter will keep the image integrity 

	Rect roi(200, 200, 325, 425); // Modeling the size to crop. Using rectangle as the measurements
								// The 3rd & 4th Parameters outline how far to go using the x & y from 1st/2nd Parameters	

	imgCrop = img(roi);


	imshow("Image", img); // Displaying our image using openCV
	imshow("New Size", imgResize);
	imshow("Crop", imgCrop);

	waitKey(0); // Freezing program to view our image


}

