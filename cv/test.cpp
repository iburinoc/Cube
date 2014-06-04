#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


int main( int argc, const char** argv )
{
	CvCapture* capture = 0;
	Mat frame, frameCopy, image;

	for(int i = 1; i < 100; i++) {

		capture = cvCaptureFromCAM( i ); //0=default, -1=any camera, 1..99=your camera
		if( capture )
		{
			goto found;
		}
	}
	found:

	cvNamedWindow( "result", CV_WINDOW_AUTOSIZE );

	if( capture )
	{
		cout << "In capture ..." << endl;
		for(;;)
		{
			IplImage* iplImg = cvQueryFrame( capture );
			frame = iplImg;

			if( frame.empty() )
				break;
			if( iplImg->origin == IPL_ORIGIN_TL )
				frame.copyTo( frameCopy );
			else
				flip( frame, frameCopy, 0 );

			cvShowImage( "result", iplImg );

			if( waitKey( 1 ) >= 0 )
				break;
		}
		// waitKey(0);
	}

	cvReleaseCapture( &capture );
	cvDestroyWindow( "result" );

	return 0;
}
