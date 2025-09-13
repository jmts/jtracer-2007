
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Surface.h                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Canvas For Rendering An Image To.            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _SURFACE_H_
#define _SURFACE_H_

//////////////////////////////////////////////////////////////////////

#include "Color.h"

//////////////////////////////////////////////////////////////////////

class Surface
{
	private:
	int m_nWidth;
	int m_nHeight;

	protected:
	float *m_fRed;
	float *m_fGreen;
	float *m_fBlue;

	public:
	Surface();

	Surface& operator=(const Surface& s);

	virtual ~Surface();

	bool create(int nWidth, int nHeight);
	bool destroy();

	int getWidth() const;
	int getHeight() const;

	bool setPixel(int x, int y, const Color &c);
	bool getPixel(int x, int y, Color &c) const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
