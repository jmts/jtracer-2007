
#include "Surface.h"
#include "Color.h"
#include <cstdio.h>

#ifndef _BITMAPWRITER_H_
#define _BITMAPWRITER_H_

typedef struct tagBMPFILEHEADER {
	unsigned short bfType;      // "BM" (19778)   2
	unsigned int   bfSize;      // File Size      4
	unsigned short bfReserved1; // 0              2
	unsigned short bfReserved2; // 0              2
	unsigned int   bfOffBits;   // Offset To Bits 4
} BMPFILEHEADER;

typedef struct tagBMPINFOHEADER {
	unsigned int   biSize;          // sizeof(BMPINFOHEADER) 4
	int            biWidth;         // Image Width           4
	int            biHeight;        // Image Height          4
	unsigned short biPlanes;        // 1                     2
	unsigned short biBitCount;      // 24                    2
	unsigned int   biCompression;   // BI_RGB (0)            4
	unsigned int   biSizeImage;     // 0                     4
	int            biXPelsPerMeter; // 0                     4
	int            biYPelsPerMeter; // 0                     4
	unsigned int   biClrUsed;       // 0                     4
	unsigned int   biClrImportant;  // 0                     4
} BMPINFOHEADER; 

class BitmapWriter
{
	private:
	static unsigned char clip(int x)
	{
		if (x < 0)        return 0;
		else if (x > 255) return 255;
		else return x;
	}

	static bool writeFileHeader(std::FILE *fp, int nWidth, int nHeight)
	{
		BMPFILEHEADER bmfh = {0};
		bmfh.bfType    = 19778;
		bmfh.bfSize    = 14 + 40 + (nWidth*nHeight*4);
		bmfh.bfOffBits = 14 + 40;

		fwrite(&bmfh.bfType, sizeof(bmfh.bfType), 1, fp);
		fwrite(&bmfh.bfSize, sizeof(bmfh.bfSize), 1, fp);
		fwrite(&bmfh.bfReserved1, sizeof(bmfh.bfReserved1), 1, fp);
		fwrite(&bmfh.bfReserved2, sizeof(bmfh.bfReserved2), 1, fp);
		fwrite(&bmfh.bfOffBits, sizeof(bmfh.bfOffBits), 1, fp);
		

		return true;
	}

	static bool writeInfoHeader(std::FILE *fp, int nWidth, int nHeight)
	{
		BMPINFOHEADER bmih = {0};
		bmih.biSize = 40;
		bmih.biWidth = nWidth;
		bmih.biHeight = nHeight;
		bmih.biPlanes = 1;
		bmih.biBitCount = 32;

		fwrite(&bmih.biSize, sizeof(bmih.biSize), 1, fp);
		fwrite(&bmih.biWidth, sizeof(bmih.biWidth), 1, fp);
		fwrite(&bmih.biHeight, sizeof(bmih.biHeight), 1, fp);
		fwrite(&bmih.biPlanes, sizeof(bmih.biPlanes), 1, fp);
		fwrite(&bmih.biBitCount, sizeof(bmih.biBitCount), 1, fp);
		fwrite(&bmih.biCompression, sizeof(bmih.biCompression), 1, fp);
		fwrite(&bmih.biSizeImage, sizeof(bmih.biSizeImage), 1, fp);
		fwrite(&bmih.biXPelsPerMeter, sizeof(bmih.biXPelsPerMeter), 1, fp);
		fwrite(&bmih.biYPelsPerMeter, sizeof(bmih.biYPelsPerMeter), 1, fp);
		fwrite(&bmih.biClrUsed, sizeof(bmih.biClrUsed), 1, fp);
		fwrite(&bmih.biClrImportant, sizeof(bmih.biClrImportant), 1, fp);

		return true;
	}

	static bool writeFileData(std::FILE *fp, const Surface *sSurface)
	{
		for (int j = 0; j < sSurface->getHeight(); j++)
		{
			for (int i = 0; i < sSurface->getWidth(); i++)
			{
				Color c;
				sSurface->getPixel(i, j, c);

				fputc(clip( (int)(c(2) * 255) ), fp);
				fputc(clip( (int)(c(1) * 255) ), fp);
				fputc(clip( (int)(c(0) * 255) ), fp);
				fputc(0x00, fp);
			}
		}

		return 0;
	}

	public:
	static bool write(const Surface *sSurface, const char *szFileName)
	{
		if (!sSurface || !szFileName)
			return false;

		std::FILE *fp = std::fopen(szFileName, "wb");
		if (!fp)
			return false;

		writeFileHeader(fp, sSurface->getWidth(), sSurface->getHeight());
		writeInfoHeader(fp, sSurface->getWidth(), sSurface->getHeight());
		writeFileData(fp, sSurface);

		fclose(fp);

		return true;
	}
};

#endif
