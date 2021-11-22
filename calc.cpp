//
// Created by John Parkhurst on 11/16/21.
//
#include "rasterImage.h"
#include <iostream>
#include <string>
const int windowSize = 5;

typedef struct
{
	pthread_t threadID;
	unsigned int index;
	unsigned int startRow, endRow;
	ImageStruct* imageIn;
	ImageStruct* imageOut;
} ThreadInfo;

void printValue(unsigned short a, unsigned short b, std::string word){
    std::cout << a;
    std::cout << '\n';
    std::cout << b;
    std::cout << '\n';
    std::cout << word;
    std::cout << '\n';
    return;
}
unsigned char ucmax(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned char maxVal = b;
	
	if (r > maxVal){
		if (g> r){
			maxVal = g;
		}
		else{
			maxVal = r;
		}
	}
	else if (g > maxVal){
		maxVal = g;
	}
	
	return maxVal;
}

unsigned char toGrayMax_(unsigned char* rgba)
{
	return ucmax(rgba[0], rgba[1], rgba[2]);
}
//FROM LAB 6

//THIS IS FROM LAB 6 SOLUTION ON GRAY 
void* threadFunc(void* arg)
{
	ThreadInfo* info = (ThreadInfo*) arg;
		
	//	Here we are looping over the entire range of rows.  You want to
	//	move this code into a function where it will only run over a range
	//	of row indices, and then call this function multiple times from here,
	//	for all the row ranges required.
	int** rasterIn = (int**)(info->imageIn->raster2D);
	unsigned char** rasterOut = (unsigned char**)(info->imageOut->raster2D);
	for (unsigned short i=info->startRow; i<=info->endRow; i++)
	{
		for (unsigned short j=0; j<info->imageIn->width; j++)
		{
			unsigned char* rgba = (unsigned char*)(rasterIn[i] + j);
			//	access pixel at column j on row i
			rasterOut[i][j] = toGrayMax_((unsigned char*)rgba);
		}
	}

	return NULL;
}
void* testFunc(void* arg){
	ThreadInfo* info = (ThreadInfo*) arg;
	int** rasterIn = (int**)(info->imageIn->raster2D);
	unsigned char** rasterOut = (unsigned char**)(info->imageOut->raster2D);
    int count = 0;
    printValue(info->startRow,info->endRow, " ");
	//i = 1500 and i is already greater than endrow so it never happens
	for (unsigned short i=info->startRow; i<=info->endRow; i++){
		for (unsigned short j=0; j<info->imageIn->width; j++){
            unsigned char* rgba = (unsigned char*)(rasterIn[i] + j);
            //	access pixel at column j on row i
            std::cout << rgba;
			rasterOut[i][j] = toGrayMax_((unsigned char*)rgba);
        }
    }
    return NULL;
}
int computeDelta(ImageStruct* img, int row, int col){
    //@Param:
    //
    //return: the change in rgb values
    //printValue(img->width,img->height," ");
    //threadFunc(img->raster);
    testFunc(img);
    return 0;
}
