
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderSettingsParser.cpp                                //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Render Settings.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "RenderSettingsParser.h"
#include "VectorToken.h"

//////////////////////////////////////////////////////////////////////

RenderSettingsParser::RenderSettingsParser()
{
	setExpecting(T_OPENBRACE);

	m_rspCurrent = RSP_ANY;
}

//////////////////////////////////////////////////////////////////////

ParseResult RenderSettingsParser::handleToken(const Token *tToken)
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
			return P_COMPLETE;

		if (tToken->getType() == T_IDENTIFIER)
		{
			if (strcmp(tToken->getString(), "width") == 0)
			{
				m_rspCurrent = RSP_WIDTH;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "height") == 0)
			{
				m_rspCurrent = RSP_HEIGHT;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "active_camera") == 0)
			{
				m_rspCurrent = RSP_CAMERA;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "filename") == 0)
			{
				m_rspCurrent = RSP_FILENAME;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "ambient_light") == 0)
			{
				m_rspCurrent = RSP_AMBIENT;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "background") == 0)
			{
				m_rspCurrent = RSP_BACKGROUND;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "recurse_depth") == 0)
			{
				m_rspCurrent = RSP_RECURSEDEPTH;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else
				return P_UNKNOWN;
		}
	}
	else if (getExpecting() == T_ASSIGNMENT)
	{
		if (m_rspCurrent == RSP_WIDTH || m_rspCurrent == RSP_HEIGHT || m_rspCurrent == RSP_RECURSEDEPTH)
		{
			setExpecting(T_NUMBER);
			return P_OK;
		}
		else if (m_rspCurrent == RSP_CAMERA || m_rspCurrent == RSP_FILENAME)
		{
			setExpecting(T_STRING);
			return P_OK;
		}
		else if (m_rspCurrent == RSP_AMBIENT || m_rspCurrent == RSP_BACKGROUND)
		{
			setExpecting(T_VECTOR);
			return P_OK;
		}
	}
	else if (getExpecting() == T_NUMBER)
	{
		if (m_rspCurrent == RSP_WIDTH)
		{
			if (!m_rsSettings.setWidth(atoi(tToken->getString())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_rspCurrent == RSP_HEIGHT)
		{
			if (!m_rsSettings.setHeight(atoi(tToken->getString())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_rspCurrent == RSP_RECURSEDEPTH)
		{
			if (!m_rsSettings.setRecursions(atoi(tToken->getString())))
				return P_ERRORVAL;
			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_STRING)
	{
		if (m_rspCurrent == RSP_CAMERA)
		{
			if (!m_rsSettings.setActiveCamera(tToken->getString()))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_rspCurrent == RSP_FILENAME)
		{
			if (!m_rsSettings.setFileName(tToken->getString()))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_VECTOR)
	{
		VectorToken *vtToken = (VectorToken*)tToken;
		if (m_rspCurrent == RSP_AMBIENT)
		{
			if (!m_rsSettings.setAmbientLight(Color(vtToken->getVector())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_rspCurrent == RSP_BACKGROUND)
		{
			if (!m_rsSettings.setInfinityColor(Color(vtToken->getVector())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_ENDSTATEMENT)
	{
		if (m_rspCurrent == RSP_WIDTH || m_rspCurrent == RSP_HEIGHT || m_rspCurrent == RSP_RECURSEDEPTH)
		{
			setExpecting(T_ANY);
			m_rspCurrent = RSP_ANY;
			return P_OK;
		}
		else if (m_rspCurrent == RSP_CAMERA || m_rspCurrent == RSP_FILENAME)
		{
			setExpecting(T_ANY);
			m_rspCurrent = RSP_ANY;
			return P_OK;
		}
		else if (m_rspCurrent == RSP_AMBIENT || m_rspCurrent == RSP_BACKGROUND)
		{
			setExpecting(T_ANY);
			m_rspCurrent = RSP_ANY;
			return P_OK;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* RenderSettingsParser::getToken()
{
	m_rsToken.setRenderSettings(m_rsSettings);

	return &m_rsToken;
}

//////////////////////////////////////////////////////////////////////

bool RenderSettingsParser::setTokenLineNumber(int iLineNumber)
{
	m_rsToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
