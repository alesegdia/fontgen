
#include "common.h"
#include <exception>
#include "cvutil.h"

#define NUM_LETTERS 		26

int main( int argc, char** argv )
{
	if( argc != 5 )
	{
		printf("usage: fontgen <font-image> <out-file> <text> <scale>\n");
		exit(1);
	}

	const char* fontstr = argv[1];
	const char* outfile = argv[2];
	const char* outtext = argv[3];
	float scale = atof( argv[4] );

	cv::Mat font = cv::imread( fontstr, CV_LOAD_IMAGE_UNCHANGED );
	int fontw = font.cols / NUM_LETTERS;
	int fonth = font.rows;
	cv::Mat out( fonth, fontw * strlen( outtext ), font.type() );

	for( int i = 0; i < strlen( outtext ); i++ )
	{
		cv::Mat fontptr = out.colRange( i * fontw, (i+1) * fontw ).rowRange( 0, fonth );
		cv::Mat letter;
		if( outtext[i] == ' ' )
		{
			letter = font( cv::Rect( 26 * fontw, 0, fontw , fonth ) );
		}
		else
		{
			char c = outtext[i] - 'a';
			letter = font( cv::Rect( c * fontw, 0, fontw , fonth ) );
		}
		letter.copyTo( fontptr );
	}

	cv::Mat ret;
	cv::resize( out, ret, cv::Size(), scale, scale, cv::INTER_NEAREST );
	display( ret );
	imwrite( outfile, ret );

	return 0;
}


