
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CameraListToken.cpp                                     //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Camera List Token For Parsed Camera Lists. //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "CameraListToken.h"

//////////////////////////////////////////////////////////////////////

CameraListToken::CameraListToken()
{
	setType(T_CAMERALIST);
}

//////////////////////////////////////////////////////////////////////

CameraListToken::CameraListToken(const CameraListToken &clt)
{
	setType(T_CAMERALIST);
	setLineNumber(clt.getLineNumber());
	m_cCameras = clt.m_cCameras;
}

//////////////////////////////////////////////////////////////////////

bool CameraListToken::setCameraList(const CameraList &cCameras)
{
	m_cCameras = cCameras;

	return true;
}

//////////////////////////////////////////////////////////////////////

CameraList CameraListToken::getCameraList() const
{
	return m_cCameras;
}

//////////////////////////////////////////////////////////////////////
