#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "imageProcessing.h"

static const int ARG_NUM = 2;

int main(int argc, char* argv[])
{
	int_fast32_t err = 0;
	BITMAPFILEHEADER bitmapFileHeader;
	BITMAPINFOHEADER bitmapInfoHeader;
	uint_least8_t* bitmapData;

	// Check the input arguments
	if ( argc != ARG_NUM )
	{
		printf("Enter input file path \n");
		return EXIT_FAILURE;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// Example #1 - Apply brightness effect
	printf("Applying brightness\n");
	
	// Load image
	bitmapData = LoadBitmapFile(argv[1],&bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	// Invoke processing function
	adjustImageBrightness(bitmapData, bitmapInfoHeader.biWidth, bitmapInfoHeader.biHeight, false, 70);
	
	// Save the result
	err = SaveBitmapFile("out_brightness.bmp", &bitmapFileHeader, &bitmapInfoHeader, bitmapData);
	if (err) 
	{
		printf("Error trying to save bitmap\n");
	}
	
	// Free image data
	free(bitmapData);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// Example #2 - Apply black and white effect
	printf("Applying BW image\n");
	
	// Load image
	bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	// Invoke processing function
	bwImage(bitmapData, bitmapInfoHeader.biWidth, bitmapInfoHeader.biHeight);
	
	// Save the result
	err = SaveBitmapFile("out_bw.bmp", &bitmapFileHeader, &bitmapInfoHeader, bitmapData);
	if (err)
	{
		printf("Error trying to save bitmap\n");
	}
	
	// Free image data
	free(bitmapData);
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// Example #3 - Apply color effect
	printf("Applying effect\n");
	
	// Load image
	bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	// Invoke processing function
	effect(bitmapData, bitmapInfoHeader.biWidth, bitmapInfoHeader.biHeight);
	
	// Save the result
	err = SaveBitmapFile("out_effect.bmp", &bitmapFileHeader, &bitmapInfoHeader, bitmapData);
	if (err) 
	{
		printf("Error trying to save bitmap\n");
	}
	
	// Free image data
	free(bitmapData);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	return EXIT_SUCCESS;
}
