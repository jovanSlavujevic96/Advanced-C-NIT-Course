#include "imageProcessing.h"
#include "bmp.h"

static const uint_least8_t bwTreshold = 80;
const int_least16_t brightnessMinimum = 20;
const int_least16_t brightnessMaximum = 220;


void adjustImageBrightness(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight,
		bool brighten, uint_least8_t adjustmentValue)
{
	uint_least32_t i;
	int_least16_t newValue;

	for (i=0; i<iWidth*iHeight*3; i++)
	{
		newValue = iData[i];
		if(brighten)
		{
			newValue += adjustmentValue;
		}
		else
		{
			newValue -= adjustmentValue;
		}

		if(newValue < brightnessMinimum)
		{
			newValue = brightnessMinimum;
		}
		else if(newValue > brightnessMaximum)
		{
			newValue = brightnessMaximum;
		}

		iData[i] = newValue;
	}
}

void bwImage(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight)
{
	int_least32_t i;
	int_least32_t j;
	int_least32_t k;
	
	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			uint_least16_t sum = 0;
			for (k=0; k<3; k++)
			{
				sum += iData[i * iWidth * 3 + j * 3 + k];
			}
			sum = sum / 3;

			sum = (sum > bwTreshold)? 255 : 0;

			for (k=0; k<3; k++)
			{
				iData[i * iWidth * 3 + j * 3 + k] = sum;
			}
		}
	}
}

void effect(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight)
{
	int_least32_t i;
	int_least32_t j;
	uint_least8_t* ptr = iData;
	
	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			if(*ptr > *(ptr+1) && *ptr > *(ptr+2))
			{
				*ptr = 255;
				ptr++;
				*ptr = 0; 
				ptr++;
				*ptr = 0;
				ptr++;
			}
			else
			{
				*ptr = 0;
				ptr++;
				if(*ptr > *(ptr+1))
				{
					*ptr = 255;
					ptr++;
					*ptr = 0; 
					ptr++;
				}
				else
				{
					*ptr = 0;
					ptr++;
					*ptr = 255; 
					ptr++;
				}
			}
		}
	}
}
