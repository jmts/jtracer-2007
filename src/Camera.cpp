
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Camera.cpp                                              //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Generalised Camera Model To Allow Support  //
//          For A Range Of Specialised Cameras With Varying         //
//          Projection Systems.                                     //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Camera.h"

#include <cstring>

//////////////////////////////////////////////////////////////////////

Camera::Camera()
{
	m_szName = 0;
}

//////////////////////////////////////////////////////////////////////

Camera::~Camera()
{
	if (m_szName)
		delete [] m_szName;
}

//////////////////////////////////////////////////////////////////////

const char* Camera::getName() const
{
	return m_szName;
}

//////////////////////////////////////////////////////////////////////

bool Camera::setName(const char *szName)
{
	if (!szName || strlen(szName) == 0)
		return false;

	if (m_szName)
		delete [] m_szName;

	int iLength = strlen(szName);
	m_szName = new char[iLength+1];
	strcpy(m_szName, szName);

	return true;
}

//////////////////////////////////////////////////////////////////////
