
#include "Color.h"

#include <cstring>

#ifndef _RENDERSETTINGS_H_
#define _RENDERSETTINGS_H_

class RenderSettings
{
	private:
	int m_nWidth;  // Canvas Dimensions
	int m_nHeight;

	int m_nRecursions;

	char *m_szActiveCamera;

	char *m_szFileName;

	Color m_cInfinity;

	public:
	RenderSettings()
	{
		m_nWidth = 1;
		m_nHeight = 1;

		m_nRecursions = 1;

		m_szActiveCamera = 0;

		m_szFileName = 0;

		m_cInfinity = Color(0.0f, 0.0f, 0.0f);
	}

	RenderSettings(const RenderSettings &rs)
	{
		m_nWidth = rs.getWidth();
		m_nHeight = rs.getHeight();

		m_szActiveCamera = 0;
		m_szFileName = 0;

		if (rs.getActiveCamera())
		{
			int iLength = std::strlen(rs.getActiveCamera());
			m_szActiveCamera = new char[iLength + 1];
			std::strcpy(m_szActiveCamera, rs.getActiveCamera());
		}

		if (rs.getFileName())
		{
			int iLength = std::strlen(rs.getFileName());
			m_szFileName = new char[iLength + 1];
			std::strcpy(m_szFileName, rs.getFileName());
		}

		m_cInfinity = rs.getInfinityColor();
	}

	~RenderSettings()
	{
		if (m_szActiveCamera)
			delete [] m_szActiveCamera;

		if (m_szFileName)
			delete [] m_szFileName;
	}

	const char *getActiveCamera() const
	{
		return m_szActiveCamera;
	}

	bool setActiveCamera(const char *szActiveCamera)
	{
		if (!szActiveCamera || std::strlen(szActiveCamera) == 0)
			return false;

		if (m_szActiveCamera)
			delete [] m_szActiveCamera;

		int iLength = std::strlen(szActiveCamera);
		m_szActiveCamera = new char[iLength + 1];
		std::strcpy(m_szActiveCamera, szActiveCamera);

		return true;
	}

	const char *getFileName() const
	{
		return m_szFileName;
	}

	bool setFileName(const char *szFileName)
	{
		if (!szFileName || std::strlen(szFileName) == 0)
			return false;

		if (m_szFileName)
			delete [] m_szFileName;

		int iLength = std::strlen(szFileName);
		m_szFileName = new char[iLength + 1];
		std::strcpy(m_szFileName, szFileName);

		return true;
	}

	bool setWidth(int nWidth)
	{
		if (nWidth < 1)
			return false;

		m_nWidth = nWidth;

		return true;
	}

	int getWidth() const
	{
		return m_nWidth;
	}

	bool setHeight(int nHeight)
	{
		if (nHeight < 1)
			return false;

		m_nHeight = nHeight;

		return true;
	}

	int getHeight() const
	{
		return m_nHeight;
	}

	bool setRecursions(int nRecursions)
	{
		if (nRecursions < 1)
			return false;

		m_nRecursions = nRecursions;

		return true;
	}

	int getRecursions() const
	{
		return m_nRecursions;
	}

	bool setInfinityColor(const Color &cInfinity)
	{
		m_cInfinity = cInfinity;

		return true;
	}

	Color getInfinityColor() const
	{
		return m_cInfinity;
	}
};

#endif
