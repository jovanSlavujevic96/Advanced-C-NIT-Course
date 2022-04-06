#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_

#include <stdint.h>
#include <stdbool.h>


void adjustImageBrightness(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight,
		bool brighten, uint_least8_t adjustmentValue);

void bwImage(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight);

void effect(uint_least8_t* iData, int_least32_t iWidth, int_least32_t iHeight);

#endif /* IMAGEPROCESSING_H_ */
