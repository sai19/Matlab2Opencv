/*
stdfilt(opencv implementation of matlab standard deviation filter function) function is defined here
*/

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <stdarg.h>

using namespace cv;
using namespace std;
/* if you want to use your own kernel(neighborhood) for filtering refer to matlab documentation of stdfilt(if you want certain location to be used as neighborhood place 1 otherwise 0)
for e.g
[0 1 0
 1 0 1 
 0 1 0]
here diagonal entries are not considered as neighborhood
standard deviation is computed using the formula std = (input-mean)^2;
hence for image
stdimage = (image-meanimage)^2
*/
Mat stdfilt(Mat src,Mat NHOOD)
{
    // define the output matrix
    Mat out;
    Point anchor;
    // normalizing the neighborhood matrix
    NHOOD = NHOOD/(float)countNonZero(NHOOD);
    double delta = 0; 		
    anchor = Point( -1, -1 );	
    out = src.clone();
    // filter2D gives the man image with specified neighborhood
    // extrapolation at border is mirror extrapolation same as in matlab	
    filter2D(src,out,-1,NHOOD,anchor,delta,BORDER_REFLECT_101);
    // mean image substraction
    absdiff(out,src,out);
    // squaring of the difference to get std matrix
    pow(out,2.0,out);
    // returning the std Matrix			    
    return out;
}
// else default kernel of size i is used
Mat stdfilt(Mat src,int i)
{   // define the output matrix
    Mat out;
    out = src.clone();
    // find out the mean image
    blur(src, out, Size(i,i));
    // substract mean image
    absdiff(out,src,out);
    // square to get std matrix
    pow(out,2.0,out);
    // return the std matrix			    
    return out;
}
