
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderSettings.cpp                                      //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Data Structure For Handling Rendering        //
//          Properties.                                             //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "RenderSettings.h"

#include <cstring>

//////////////////////////////////////////////////////////////////////

RenderSettings::RenderSettings()
{
	m_nWidth = 1;
	m_nHeight = 1;
	m_nRecursions = 0;
	m_szActiveCamera = 0;
	m_szFileName = 0;
	m_cAmbient = Color(0.0f, 0.0f, 0.0f);
	m_cInfinity = Color(0.0f, 0.0f, 0.0f);
}

//////////////////////////////////////////////////////////////////////

RenderSettings::RenderSettings(const RenderSettings &rs)
{
	m_nWidth = rs.getWidth();
	m_nHeight = rs.getHeight();

	m_nRecursions = rs.m_nRecursions;

	m_szActiveCamera = 0;
	m_szFileName = 0;

	if (rs.getActiveCamera())
		setActiveCamera(rs.getActiveCamera());

	if (rs.getFileName())
		setFileName(rs.getFileName());

	m_cAmbient = rs.getAmbientLight();

	m_cInfinity = rs.getInfinityColor();
}

//////////////////////////////////////////////////////////////////////

RenderSettings& RenderSettings::operator=(const RenderSettings& rs)
{
	if (&rs == this)
		return *this;

	m_nWidth = rs.getWidth();
	m_nHeight = rs.getHeight();

	m_nRecursions = rs.m_nRecursions;

	m_szActiveCamera = 0;
	m_szFileName = 0;

	if (rs.getActiveCamera())
		setActiveCamera(rs.getActiveCamera());

	if (rs.getFileName())
		setFileName(rs.getFileName());

	m_cAmbient = rs.getAmbientLight();

	m_cInfinity = rs.getInfinityColor();

	return *this;
}

//////////////////////////////////////////////////////////////////////

RenderSettings::~RenderSettings()
{
	if (m_szActiveCamera)
		delete [] m_szActiveCamera;

	if (m_szFileName)
		delete [] m_szFileName;
}

//////////////////////////////////////////////////////////////////////

const char* RenderSettings::getActiveCamera() const
{
	return m_szActiveCamera;
}

//////////////////////////////////////////////////////////////////////

bool RenderSettings::setActiveCamera(const char *szActiveCamera)
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

//////////////////////////////////////////////////////////////////////

const char* RenderSettings::getFileName() const
{
	return m_szFileName;
}

//////////////////////////////////////////////////////////////////////

bool RenderSettings::setFileName(const char *szFileName)
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

//////////////////////////////////////////////////////////////////////

bool RenderSettings::setWidth(int nWidth)
{
	if (nWidth < 1)
		return false;

	m_nWidth = nWidth;

	return true;
}

//////////////////////////////////////////////////////////////////////

int RenderSettings::getWidth() const
{
	return m_nWidth;
}

//////////////////////////////////////////////////////////////////////

bool RenderSettings::setHeight(int nHeight)
{
	if (nHeight < 1)
		return false;

	m_nHeight = nHeight;

	return true;
}

//////////////////////////////////////////////////////////////////////

int RenderSettings::getHeight() const
{
	return m_nHeight;
}

//////////////////////////////////////////////////////////////////////

bool RenderSettings::setRecursions(int nRecursions)
{
	if (nRecursions < 0)
		return false;

	m_nRecursions = nRecursions;

	return true;
}

//////////////////////////////////////////////////////////////////////

int RenderSettings::getRecursions() const
{
	return m_nRecursions;
}

//////////////////////////////////////////////////////////////////////

bool RenderSettings::setAmbientLight(const Color &cAmbient)
{
	m_cAmbient = cAmbient;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Color& RenderSettings::getAmbientLight() const
{
	return m_cAmbient;
}

//////////////////////////////////////////////////////////////////////

bool RenderSettings::setInfinityColor(const Color &cInfinity)
{
	m_cInfinity = cInfinity;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Color& RenderSettings::getInfinityColor() const
{
	return m_cInfinity;
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const RenderSettings &rs)
{
	os << "    Width: " << rs.getWidth() << std::endl;
	os << "    Height: " << rs.getHeight() << std::endl;

	os << "    Active Camera: ";
	if (rs.getActiveCamera())
		os << rs.getActiveCamera() << std::endl;
	else
		os << "None" << std::endl;

	os << "    File Name: ";
	if (rs.getFileName())
		os << rs.getFileName() << std::endl;
	else
		os << "None" << std::endl;

	os << "    Ambient Light: " << rs.getAmbientLight() << std::endl;
	os << "    Background: " << rs.getInfinityColor() << std::endl;

	return os;
}

//////////////////////////////////////////////////////////////////////
