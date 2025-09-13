
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PointLightParser.cpp                                    //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Point Lights.                   //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "PointLightParser.h"
#include "VectorToken.h"
#include "MaterialToken.h"

//////////////////////////////////////////////////////////////////////

PointLightParser::PointLightParser()
{
	setExpecting(T_OPENBRACE);

	m_pCurrent = PLP_ANY;
}

//////////////////////////////////////////////////////////////////////

ParseResult PointLightParser::handleToken(const Token *tToken)
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
			if (strcmp(tToken->getString(), "position") == 0)
			{
				m_pCurrent = PLP_POSITION;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "intensity") == 0)
			{
				m_pCurrent = PLP_INTENSITY;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else
				return P_UNKNOWN;
		}
	}
	else if (getExpecting() == T_ASSIGNMENT)
	{
		if (m_pCurrent == PLP_POSITION || m_pCurrent == PLP_INTENSITY)
		{
			setExpecting(T_VECTOR);
			return P_OK;
		}
	}
	else if (getExpecting() == T_VECTOR)
	{
		VectorToken *vtToken = (VectorToken*)tToken;
		if (m_pCurrent == PLP_POSITION)
		{
			if (!m_lPointLight.setPosition(vtToken->getVector()))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_pCurrent == PLP_INTENSITY)
		{
			if (!m_lPointLight.setIntensity(Color(vtToken->getVector())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_ENDSTATEMENT)
	{
		if (m_pCurrent == PLP_POSITION || m_pCurrent == PLP_INTENSITY)
		{
			setExpecting(T_ANY);
			m_pCurrent = PLP_ANY;
			return P_OK;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* PointLightParser::getToken()
{
	m_plToken.setPointLight(m_lPointLight);

	return &m_plToken;
}

//////////////////////////////////////////////////////////////////////

bool PointLightParser::setTokenLineNumber(int iLineNumber)
{
	m_plToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
