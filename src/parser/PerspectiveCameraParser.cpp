
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PerspectiveCameraParser.cpp                             //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Perspective Cameras.            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "PerspectiveCameraParser.h"
#include "VectorToken.h"

//////////////////////////////////////////////////////////////////////

PerspectiveCameraParser::PerspectiveCameraParser()
{
	setExpecting(T_OPENBRACE);

	m_pcpCurrent = PCP_ANY;
}

//////////////////////////////////////////////////////////////////////

ParseResult PerspectiveCameraParser::handleToken(const Token *tToken)
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
		else if (tToken->getType() == T_IDENTIFIER)
		{
			if (strcmp(tToken->getString(), "position") == 0)
			{
				m_pcpCurrent = PCP_POSITION;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "look_at") == 0)
			{
				m_pcpCurrent = PCP_LOOKAT;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "up") == 0)
			{
				m_pcpCurrent = PCP_UP;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "fov") == 0)
			{
				m_pcpCurrent = PCP_FOV;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "aspect") == 0)
			{
				m_pcpCurrent = PCP_ASPECT;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "name") == 0)
			{
				m_pcpCurrent = PCP_NAME;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
		}
	}
	else if (getExpecting() == T_ASSIGNMENT)
	{
		if (m_pcpCurrent == PCP_POSITION || m_pcpCurrent == PCP_LOOKAT || m_pcpCurrent == PCP_UP)
		{
			setExpecting(T_VECTOR);
			return P_OK;
		}
		else if (m_pcpCurrent == PCP_FOV || m_pcpCurrent == PCP_ASPECT)
		{
			setExpecting(T_NUMBER);
			return P_OK;
		}
		else if (m_pcpCurrent == PCP_NAME)
		{
			setExpecting(T_STRING);
			return P_OK;
		}
	}
	else if (getExpecting() == T_VECTOR)
	{
		VectorToken *vToken = (VectorToken*)tToken;
		if (m_pcpCurrent == PCP_POSITION)
		{
			m_cCamera.setPosition(vToken->getVector());
			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_pcpCurrent == PCP_LOOKAT)
		{
			m_cCamera.setLookAt(vToken->getVector());
			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_pcpCurrent == PCP_UP)
		{
			m_cCamera.setUp(vToken->getVector());
			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_NUMBER)
	{
		if (m_pcpCurrent == PCP_FOV)
		{
			float fFieldOfView = atof(tToken->getString());
			if (fFieldOfView <= 0.0)
				return P_ERRORVAL;
			m_cCamera.setFieldOfView(fFieldOfView);
			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_pcpCurrent == PCP_ASPECT)
		{
			float fAspect = atof(tToken->getString());
			if (fAspect <= 0.0)
				return P_ERRORVAL;
			m_cCamera.setAspect(fAspect);
			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_STRING)
	{
		if (m_pcpCurrent == PCP_NAME)
		{
			if (!m_cCamera.setName(tToken->getString()))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_ENDSTATEMENT)
	{
		if (m_pcpCurrent == PCP_POSITION || m_pcpCurrent == PCP_LOOKAT || m_pcpCurrent == PCP_UP)
		{
			setExpecting(T_ANY);
			return P_OK;
		}
		else if (m_pcpCurrent == PCP_ASPECT || m_pcpCurrent == PCP_FOV || m_pcpCurrent == PCP_NAME)
		{
			setExpecting(T_ANY);
			return P_OK;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* PerspectiveCameraParser::getToken()
{
	m_cToken.setPerspectiveCamera(m_cCamera);

	return &m_cToken;
}

//////////////////////////////////////////////////////////////////////

bool PerspectiveCameraParser::setTokenLineNumber(int iLineNumber)
{
	m_cToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
