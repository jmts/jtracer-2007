
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    BitmapWriter.cpp                                        //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides Simple Windows Bitmap Output Facilities.       //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "BitmapWriter.h"

#include "..\Color.h"

//////////////////////////////////////////////////////////////////////

bool BitmapWriter::write(const Surface *sSurface, const char *szFileName)
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

//////////////////////////////////////////////////////////////////////

bool BitmapWriter::writeFileHeader(std::FILE *fp, int nWidth, int nHeight)
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

//////////////////////////////////////////////////////////////////////

bool BitmapWriter::writeInfoHeader(std::FILE *fp, int nWidth, int nHeight)
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

//////////////////////////////////////////////////////////////////////

bool BitmapWriter::writeFileData(std::FILE *fp, const Surface *sSurface)
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

//////////////////////////////////////////////////////////////////////

unsigned char BitmapWriter::clip(int x)
{
	if (x < 0)        return 0;
	else if (x > 255) return 255;
	else return x;
}

//////////////////////////////////////////////////////////////////////
