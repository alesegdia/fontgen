
#include "cvutil.h"

void display( const cv::Mat& img, const char* winname )
{
	if( !winname ) winname = "default";
	cv::namedWindow( winname, cv::WINDOW_AUTOSIZE );
	cv::imshow( winname, img );
	cv::waitKey( 0 );
}
