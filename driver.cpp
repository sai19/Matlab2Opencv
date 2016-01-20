/*
Author : Saiprasad Koturwar (IIT Bombay,Dept.Electrical Engineering)
Email-id : s.koturwar@gmail.com
This is the driver function for stdfilt(opencv implementation of matlab standard deviation filter function)
*/





#include <stdio.h>
#include <opencv2/opencv.hpp>
// include the stdfilt.cpp file (input the appropriate path)
#include </home/sai/scilab/stdfilt/stdfilt.cpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
//define new image matrices
Mat src;
Mat dst;
// if you want to give your own kernel for filtering similar to NHOOD in matlab stdfilt function
Mat ker;
int i;
// take input from command line
// command line input is char type so convert to int
// i is used to determine the size of the filter
i = atoi(argv[2]);
int kernel_size=i;
// define your own kernel, here i defined all one filter for average filtering
ker = Mat::ones( kernel_size, kernel_size, CV_32F );
// read the image
// image path is taken through command line
src = imread(argv[1],1);
// apply stdfilt on image
dst = stdfilt(src,ker);
// output the image
namedWindow("Display Image", WINDOW_AUTOSIZE );
imshow("Display Image", dst);
waitKey(0);
return(0);		
}
