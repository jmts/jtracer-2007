
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PerspectiveCameraToken.cpp                              //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Perspective Camera Token For Parsed        //
//          Perspective Cameras.                                    //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "PerspectiveCameraToken.h"

//////////////////////////////////////////////////////////////////////

PerspectiveCameraToken::PerspectiveCameraToken()
{
	setType(T_PERSPECTIVECAMERA);
}

//////////////////////////////////////////////////////////////////////

PerspectiveCameraToken::PerspectiveCameraToken(const PerspectiveCameraToken &pct)
{
	setType(T_PERSPECTIVECAMERA);

	setLineNumber(pct.getLineNumber());
	m_cCamera = pct.m_cCamera;
}

//////////////////////////////////////////////////////////////////////

bool PerspectiveCameraToken::setPerspectiveCamera(const PerspectiveCamera &cCamera)
{
	m_cCamera = cCamera;
	return true;
}

//////////////////////////////////////////////////////////////////////

const PerspectiveCamera& PerspectiveCameraToken::getPerspectiveCamera() const
{
	return m_cCamera;
}

//////////////////////////////////////////////////////////////////////
