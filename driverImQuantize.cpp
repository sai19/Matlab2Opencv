/*
Author : Saiprasad Koturwar (IIT Bombay,Dept.Electrical Engineering)
Email-id : s.koturwar@gmail.com
This is the driver function for stdfilt(opencv implementation of matlab standard deviation filter function)
*/



#include <stdio.h>
#include <opencv2/opencv.hpp>
// include the imQuantize.cpp file (input the appropriate path)
#include </home/sai/scilab/imQuantize/imQuantize.cpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
//define new image matrices
Mat src;
Mat dst;
// read the image (path is given through command line)
src = imread(argv[1],1);
// testcase for levels
int L[] = {123,150,198};
// convert the image to graylevel 
cvtColor( src,src, CV_BGR2GRAY );
// apply imquantize on the image and store in dst
dst = imQuantize(src,L,sizeof(L)/sizeof(*L),1);
// output/display the image
namedWindow("Display Image", WINDOW_AUTOSIZE );
imshow("Display Image", dst);
waitKey(0);
return(0);		
}
