
#include "Color.h"

#ifndef _SURFACE_H_
#define _SURFACE_H_

class Surface
{
	private:
	float *m_fRed;
	float *m_fGreen;
	float *m_fBlue;

	int m_nWidth;
	int m_nHeight;

	public:
	Surface()
	{
		m_fRed = 0;
		m_fGreen = 0;
		m_fBlue = 0;

		m_nWidth = 0;
		m_nHeight = 0;
	}

	virtual ~Surface()
	{
		if (m_fRed)
			delete [] m_fRed;

		if (m_fGreen)
			delete [] m_fGreen;

		if (m_fBlue)
			delete [] m_fBlue;
	}

	int getWidth() const
	{
		return m_nWidth;
	}

	int getHeight() const
	{
		return m_nHeight;
	}

	bool create(int nWidth, int nHeight)
	{
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

	bool destroy()
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

		m_nWidth = 0;
		m_nHeight = 0;

		return true;
	}

	bool setPixel(int x, int y, const Color &c)
	{
		if (!m_fRed || !m_fGreen || !m_fBlue || x < 0 || y < 0 || x >= m_nWidth || y >= m_nHeight)
			return false;

		int nOffset = (y * m_nWidth) + x;

		m_fRed[nOffset]   = c(0);
		m_fGreen[nOffset] = c(1);
		m_fBlue[nOffset]  = c(2);

		return true;
	}

	bool getPixel(int x, int y, Color &c) const
	{
		if (!m_fRed || !m_fGreen || !m_fBlue || x < 0 || y < 0 || x >= m_nWidth || y >= m_nHeight)
			return false;

		int nOffset = (y * m_nWidth) + x;

		c = Color(m_fRed[nOffset], m_fGreen[nOffset], m_fBlue[nOffset]);

		return true;
	}
};

#endif
