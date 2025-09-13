
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderContextParser.cpp                                 //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Render Contexts.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "RenderContextParser.h"
#include "RenderSettingsToken.h"
#include "CameraListToken.h"
#include "SceneToken.h"

//////////////////////////////////////////////////////////////////////

RenderContextParser::RenderContextParser()
{
	setExpecting(T_ANY);
}

//////////////////////////////////////////////////////////////////////

ParseResult RenderContextParser::handleToken(const Token *tToken)
{
	if (getExpecting() != T_ANY && getExpecting() != tToken->getType())
		return P_UNEXPECTED;

	if (getExpecting() == T_ANY)
	{
		if (tToken->getType() == T_RENDERSETTINGS)
		{
			RenderSettingsToken *rsToken = (RenderSettingsToken*)tToken;
			RenderSettings rsSettings = rsToken->getRenderSettings();
			m_rcContext.setRenderSettings(rsSettings);

			return P_OK;
		}

		if (tToken->getType() == T_CAMERALIST)
		{
			CameraListToken *cToken = (CameraListToken*)tToken;
			CameraList cCameras = cToken->getCameraList();
			m_rcContext.setCameraList(cCameras);

			return P_OK;
		}

		if (tToken->getType() == T_SCENE)
		{
			SceneToken *sToken = (SceneToken*)tToken;
			Scene sScene = sToken->getScene();
			m_rcContext.setScene(sScene);

			return P_OK;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* RenderContextParser::getToken()
{
	m_tToken.setRenderContext(m_rcContext);

	return &m_tToken;
}

//////////////////////////////////////////////////////////////////////

bool RenderContextParser::setTokenLineNumber(int iLineNumber)
{
	m_tToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
