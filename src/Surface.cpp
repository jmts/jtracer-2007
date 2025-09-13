
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Surface.cpp                                             //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Canvas For Rendering An Image To.            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Surface.h"

//////////////////////////////////////////////////////////////////////

Surface::Surface()
{
	m_fRed   = 0;
	m_fGreen = 0;
	m_fBlue  = 0;

	m_nWidth  = 0;
	m_nHeight = 0;
}

//////////////////////////////////////////////////////////////////////

Surface::~Surface()
{
	destroy();
}

//////////////////////////////////////////////////////////////////////

int Surface::getWidth() const
{
	return m_nWidth;
}

int Surface::getHeight() const
{
	return m_nHeight;
}

//////////////////////////////////////////////////////////////////////

bool Surface::create(int nWidth, int nHeight)
{
	if (m_nWidth > 0 || m_nHeight > 0)
		return false;

	if (nWidth < 1 || nHeight < 1)
		return false;

	int nSize = nWidth * nHeight;

	m_fRed   = new float[nSize];
	m_fGreen = new float[nSize];
	m_fBlue  = new float[nSize];

	m_nWidth  = nWidth;
	m_nHeight = nHeight;

	return true;
}

//////////////////////////////////////////////////////////////////////

bool Surface::destroy()
{
	if (m_fRed)
	{
		delete [] m_fRed;
		m_fRed = 0;
	}

	if (m_fGreen)
	{
		delete [] m_fGreen;
		m_fGreen = 0;
	}

	if (m_fBlue)
	{
		delete [] m_fBlue;
		m_fBlue = 0;
	}

	m_nWidth  = 0;
	m_nHeight = 0;

	return true;
}

//////////////////////////////////////////////////////////////////////

bool Surface::setPixel(int x, int y, const Color &c)
{
	if (!m_fRed || !m_fGreen || !m_fBlue || x < 0 || y < 0 || x >= m_nWidth || y >= m_nHeight)
		return false;

	int nOffset = (y * m_nWidth) + x;

	m_fRed[nOffset]   = c(0);
	m_fGreen[nOffset] = c(1);
	m_fBlue[nOffset]  = c(2);

	return true;
}

//////////////////////////////////////////////////////////////////////

bool Surface::getPixel(int x, int y, Color &c) const
{
	if (!m_fRed || !m_fGreen || !m_fBlue || x < 0 || y < 0 || x >= m_nWidth || y >= m_nHeight)
		return false;

	int nOffset = (y * m_nWidth) + x;

	c = Color(m_fRed[nOffset], m_fGreen[nOffset], m_fBlue[nOffset]);

	return true;
}

//////////////////////////////////////////////////////////////////////
