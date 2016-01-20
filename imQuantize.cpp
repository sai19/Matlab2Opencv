/*
Author : Saiprasad Koturwar (IIT Bombay,Dept.Electrical Engineering)
Email-id : s.koturwar@gmail.com
imQuantize(opencv implementation of matlab imQuantize function) function is defined here
*/


#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <stdarg.h>

using namespace cv;
using namespace std;
Mat imQuantize(Mat src,int levels[],int length, int type)
{
    // define the output matrix and temporary matrix 
    Mat out;
    Mat tmp;
    double min,max;
    // initialize both the matrices to zero
    int rows = src.rows;
    int cols = src.cols;
    int sizes[] = {rows,cols};
    // standard opencv initialization of matrix(here initializing to zero)
    out = Mat::zeros(2,sizes,src.type());
    // find out the min max values (useful for quantizing extreme valus)
    minMaxLoc(src, &min, &max);
    // now run through all the values given for quantizing the image
    for (int i=0;i<=length;i++){
    // initialize tmp to zero after each iteration as we need to take "or" of the tmps to get output image
    tmp = Mat::zeros(2,sizes,src.type());
    // assign the pixel values lying in o to levels[0] 1;
    if(i==0){
    // inrange assigns value 1 to the pixels lying in given range else 0(inRange is opencv function)
    //  here range is [0,levels[0]]			
    inRange(src, cv::Scalar(0), cv::Scalar(levels[0]), tmp);
    // in matlab there are two options for quantization, i.e replace pixel values with i(that is in which level they lie) or replace by actual 
    // quantization values(i.e levels[i]) this is handled using "type"
    if(type==1){
    // replace the value 255 in matrix by 1;	 		
    tmp = tmp/255;}
    if(type==0){tmp = (levels[i])*tmp/255;}	
}
    else if (i<length){
    // here range is [levels[i-1],levels[i]];
    inRange(src, cv::Scalar(levels[i-1]), cv::Scalar(levels[i]), tmp);
    // type handling as discussed above
    if(type==1){tmp = (tmp/255)*(i);}
    if(type==0){tmp = (levels[i])*tmp/255;}}
    if(i==length){
    // here range is [levels[length-1],max];
    inRange(src, cv::Scalar(levels[i-1]), cv::Scalar(max), tmp);
    if(type==1){tmp = (tmp/255)*(i);}
    if(type==0){tmp = (levels[i])*tmp/255;}}
}
    //take or consecutively to get the output image	
    bitwise_or(tmp,out,out);
    // return output		   	   		    
    return out;
}
