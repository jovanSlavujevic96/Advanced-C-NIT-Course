/**
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "bmp.h"
#include "imageProcessing.h"

static const int ARG_NUM = 2;

static void calculateAverageRGB(const uint_least8_t* bitmapData, int_least32_t width, int_least32_t height,
	uint_least8_t* const red_out, uint_least8_t* const green_out, uint_least8_t* const blue_out)
{
	int_least32_t i = 0;
	uint_least32_t average_red = 0;
	uint_least32_t average_green = 0;
	uint_least32_t average_blue = 0;

	for (i = 0; i < width * height * 3; i += 3)
	{
		average_red   += bitmapData[i];
		average_green += bitmapData[i+1];
		average_blue  += bitmapData[i+2];
	}

	average_red   /= (width * height);
	average_green /= (width * height);
	average_blue  /= (width * height);

	*red_out = average_red;
	*green_out = average_green;
	*blue_out = average_blue;
}

static void mean_filter(const uint_least8_t* bitmapData, uint_least8_t* outData, int_least32_t width, int_least32_t height)
{
	int_least32_t i,j,k,l,m;
	uint_least16_t sum = 0; // max values 255 * 9 > 2^8 && < 2^16

	for (i=1; i<height-1; i++)
	{
		for (j=1; j<width-1; j++)
		{
			for (k=0; k<3; k++)
			{
				for (l=-1; l <= 1; l++)
				{
					for (m=-1; m <= 1; m++)
					{
						sum += bitmapData[(i+l) * width * 3 + (j+m) * 3 + k];
					}
				}
				outData[i*width*3 + j*3 + k] = sum/9;
				sum = 0;
			}
		}
	}
}


int main(int argc, char* argv[])
{
	int_fast32_t err = 0;
	BITMAPFILEHEADER bitmapFileHeader;
	BITMAPINFOHEADER bitmapInfoHeader;
	uint_least8_t* bitmapData = NULL;
	uint_least8_t* meanData = NULL;

	uint_least8_t red_average = 0;
	uint_least8_t green_average = 0;
	uint_least8_t blue_average = 0;


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
	/// TASK 1
	bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	calculateAverageRGB(bitmapData, bitmapInfoHeader.biWidth, bitmapInfoHeader.biHeight, &red_average, &green_average, &blue_average);

	printf("RED AVERAGE   = %" SCNuLEAST8 "\n", red_average);
	printf("GREEN AVERAGE = %" SCNuLEAST8 "\n", green_average);
	printf("BLUE AVERAGE  = %" SCNuLEAST8 "\n", blue_average);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/// TASK 1

	meanData = (uint_least8_t*)malloc(bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight * 3);
	mean_filter(bitmapData, meanData, bitmapInfoHeader.biWidth, bitmapInfoHeader.biHeight);

	err = SaveBitmapFile("mean_filetered.bmp", &bitmapFileHeader, &bitmapInfoHeader, meanData);
	if (err)
	{
		printf("Error trying to save bitmap\n");
	}


	// Free image data
	free(meanData);
	free(bitmapData);

	return EXIT_SUCCESS;
}
