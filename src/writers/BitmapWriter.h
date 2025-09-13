
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

#include "..\FileSurfaceWriter.h"

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

class BitmapWriter : public FileSurfaceWriter
{
	private:
	unsigned char clip(int x);

	bool writeFileHeader(int nWidth, int nHeight);

	bool writeInfoHeader(int nWidth, int nHeight);

	bool writeFileData(const Surface *sSurface);

	std::FILE *m_fp;

	public:
	BitmapWriter()
	{
		m_fp = 0;
	}

	~BitmapWriter()
	{
		close();
	}

	bool open(const char *szFileName)
	{
		if (!szFileName || m_fp)
			return false;

		m_fp = std::fopen(szFileName, "wb");
		if (!m_fp)
			return false;

		return true;
	}

	bool write(const Surface *sSurface)
	{
		if (!m_fp || !sSurface)
			return false;

		fseek(m_fp, 0, SEEK_SET);

		writeFileHeader(sSurface->getWidth(), sSurface->getHeight());
		writeInfoHeader(sSurface->getWidth(), sSurface->getHeight());
		writeFileData  (sSurface);

		return true;
	}

	bool write(const Surface *sSurface, const char *szFileName)
	{
		if (!open(szFileName))
			return false;

		if (!write(sSurface))
			return false;

		close();

		return true;
	}

	bool close()
	{
		if (!m_fp)
			return false;

		fclose(m_fp);

		return true;
	}
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
