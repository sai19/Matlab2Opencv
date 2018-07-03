/*
This is the driver function for stdfilt(opencv implementation of matlab standard deviation filter function)
*/



#include <stdio.h>
#include <opencv2/opencv.hpp>
// include the imQuantize.cpp file (input the appropriate path)
#include <path to imquantize>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
//define new image matrices
Mat src;
Mat dst;
int type;
// read the image (path is given through command line)
src = imread(argv[1],1);
// define your own quantization levels
int L[] = {123,150,198};
// convert the image to graylevel 
cvtColor( src,src, CV_BGR2GRAY );
// apply imquantize on the image and store in dst
// if type=1; pixel values are replaced by interval no. (i.e (for choosen case) [0,123]=1;[123,150]=2;[150,198]=3;[198 and above]=4;)
// if type=0; pixel values are replaced by actual quantization values
dst = imQuantize(src,L,sizeof(L)/sizeof(*L),type);
// output/display the image
// for output with type 1 image may look blank but it is not(you can confirm it by printing out the matrix) as the assigned values will be pretty small on the scale of 255   
namedWindow("Display Image", WINDOW_AUTOSIZE );
imshow("Display Image", dst);
waitKey(0);
return(0);		
}
