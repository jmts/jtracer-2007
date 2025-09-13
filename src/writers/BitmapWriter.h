
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    BitmapWriter.h                                          //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides Simple Windows Bitmap Output Facilities.       //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _BITMAPWRITER_H_
#define _BITMAPWRITER_H_

//////////////////////////////////////////////////////////////////////

#include "..\Surface.h"

#include <cstdio>

//////////////////////////////////////////////////////////////////////

typedef struct tagBMPFILEHEADER {
	unsigned short bfType;      // "BM" (19778)   2
	unsigned int   bfSize;      // File Size      4
	unsigned short bfReserved1; // 0              2
	unsigned short bfReserved2; // 0              2
	unsigned int   bfOffBits;   // Offset To Bits 4
} BMPFILEHEADER;

//////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////

class BitmapWriter
{
	private:
	static unsigned char clip(int x);

	static bool writeFileHeader(std::FILE *fp, int nWidth, int nHeight);

	static bool writeInfoHeader(std::FILE *fp, int nWidth, int nHeight);

	static bool writeFileData(std::FILE *fp, const Surface *sSurface);

	public:
	static bool write(const Surface *sSurface, const char *szFileName);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
