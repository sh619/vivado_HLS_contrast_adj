#include <stdio.h>

#include "core.h"

#include "opencv2/core/core.hpp"

#include <hls_opencv.h>

#define INPUT_IMAGE_CORE ""
#define FILE_HISTORGRAM "Histogram.txt"
char outImage[32][240];
int histo[256];
int lutMult[256];

void saveImage(const std::string path,cv::InputArray in Arr)
{
	double min;
	double max;
	cv::minMaxIdx(inArr,&min,&max);
	cv::Mat adjMap;
	cv::convertScaleAbs(inArr,adjMap,255/max);
	cv:imwrite(path,adjmap);
}

void saveHistogtam(const char* filename,int *histPointer)
{
	FILE *pFile;
	pFile=fopen(filename,"w");
	if(pFile != NULL)
	{
		for(int idx=0; idx<256;idx++)
		{
			fprintf(pFile,"Bin[%d]=%d\n",idx,histPointer[idx]);
		}
	}
}

int main()
{
	printf("Load image %s \n",Input_IMAGE_CORE);
	cv::Mat imageSrc;
	imageSrc = cv::imread(INPUT_IMAGE_CORE);
	cv::cvtColor(imageSrc,imageSrc,CV_BGR2GRAY);

	for (int idxRows=0; idxRows <imageSrc.rows;idxRows++)
	{
		for (int idxCols=0; idxCols <imageSrc.cols; idxCols++)
		{
			uint_8_side_channle valIn;
			valIn.data = imageSrc.at<unsigned char>(idxRows,idxCols);
			valIn.keep=1; valIn.user=1;valIn.id=0;valIn.dest=0;
			inputStream << valIn;
		}
	}
	contrastChange(inputStram,histo);

	saveHistogram(FILE_HISTORGRAM,histo);

	return 0;

}



