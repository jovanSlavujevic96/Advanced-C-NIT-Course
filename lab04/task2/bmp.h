#ifndef BMP_H_
#define BMP_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


typedef struct tagBITMAPFILEHEADER {
	uint16_t bfType; //specifies the file type
	uint32_t bfSize; //specifies the size in bytes of the bitmap file
	uint16_t bfReserved1; //reserved; must be 0
	uint16_t bfReserved2; //reserved; must be 0
	uint32_t bfOffBits; //species the offset in bytes from the bitmapfileheader to the bitmap bits
}__attribute__((packed)) BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
	uint32_t biSize; //specifies the number of bytes required by the struct
	int32_t biWidth; //specifies width in pixels
	int32_t biHeight; //species height in pixels
	uint16_t biPlanes; //specifies the number of color planes, must be 1
	uint16_t biBitCount; //specifies the number of bit per pixel
	uint32_t biCompression;//spcifies the type of compression
	uint32_t biSizeImage; //size of image in bytes
	int32_t biXPelsPerMeter; //number of pixels per meter in x axis
	int32_t biYPelsPerMeter; //number of pixels per meter in y axis
	uint32_t biClrUsed; //number of colors used by th ebitmap
	uint32_t biClrImportant; //number of colors that are important
}__attribute__((packed)) BITMAPINFOHEADER;


uint8_t* LoadBitmapFile(char* filename, BITMAPFILEHEADER* bitmapFileHeader,
		BITMAPINFOHEADER* bitmapInfoHeader);

int_fast8_t SaveBitmapFile(char* filename, BITMAPFILEHEADER* bitmapFileHeader,
		BITMAPINFOHEADER* bitmapInfoHeader, uint8_t* bitmapImage);


#endif /* BMP_H_ */
