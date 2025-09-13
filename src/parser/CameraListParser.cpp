
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CameraListParser.cpp                                    //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Camera Lists.                   //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "CameraListParser.h"
#include "PerspectiveCameraToken.h"

//////////////////////////////////////////////////////////////////////

CameraListParser::CameraListParser()
{
	setExpecting(T_OPENBRACE);
}

//////////////////////////////////////////////////////////////////////

ParseResult CameraListParser::handleToken(const Token *tToken)
{
	if (getExpecting() != T_ANY && getExpecting() != tToken->getType())
		return P_UNEXPECTED;

	if (getExpecting() == T_OPENBRACE)
	{
		setExpecting(T_ANY);
		return P_OK;
	}

	else if (getExpecting() == T_ANY)
	{
		if (tToken->getType() == T_CLOSEBRACE)
		{
			return P_COMPLETE;
		}

		else if (tToken->getType() == T_PERSPECTIVECAMERA)
		{
			PerspectiveCameraToken *cToken = (PerspectiveCameraToken*)tToken;
			PerspectiveCamera *cCamera = new PerspectiveCamera(cToken->getPerspectiveCamera());
			m_cCameras.addCamera(cCamera);
			return P_OK;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* CameraListParser::getToken()
{
	m_cToken.setCameraList(m_cCameras);

	return &m_cToken;
}

//////////////////////////////////////////////////////////////////////

bool CameraListParser::setTokenLineNumber(int iLineNumber)
{
	m_cToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
