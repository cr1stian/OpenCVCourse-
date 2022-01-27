#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


////////////// Images

void getContours(Mat imgDil, Mat imgDst ) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;



	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	
	for (int i(0); i < contours.size(); i++) {
		int area = contourArea(contours[i]);

		cout << area << endl;

		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect;

		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(imgDst, conPoly, i, Scalar(255, 0, 255), 2);
			cout << conPoly[i].size() << endl;
			//boundRect[i] = boundingRect(conPoly[i]);
			//rectangle(imgDst, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5 );

			int objCor = (int)conPoly[i].size();

		}
	}

};

void main() {

	string pathName("Resources/shapes.png"); // Grabbing image path 
	Mat img = imread(pathName); // Setting image to Mat object used for images in openCV

	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// Preprocessing 
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); 
	dilate(imgCanny, imgDil, kernel);
		
	getContours(imgDil, img);

	imshow("Image", img); // Displaying our image using openCV

	waitKey(0); // Freezing program to view our image


}
