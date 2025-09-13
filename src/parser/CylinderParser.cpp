
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CylinderParser.cpp                                      //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Cylinders.                      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "CylinderParser.h"
#include "MaterialToken.h"
#include "TransformToken.h"

//////////////////////////////////////////////////////////////////////

CylinderParser::CylinderParser()
{
	setExpecting(T_OPENBRACE);

	m_pCurrent = CP_ANY;
}

//////////////////////////////////////////////////////////////////////

ParseResult CylinderParser::handleToken(const Token *tToken)
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
			if (strcmp(tToken->getString(), "radius") == 0)
			{
				m_pCurrent = CP_RADIUS;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "height") == 0)
			{
				m_pCurrent = CP_HEIGHT;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else
				return P_UNKNOWN;
		}

		if (tToken->getType() == T_MATERIAL)
		{
			MaterialToken *mToken = (MaterialToken*)tToken;
			m_pCylinder.setMaterial(mToken->getMaterial());
			return P_OK;
		}

		if (tToken->getType() == T_TRANSFORM)
		{
			TransformToken *trToken = (TransformToken*)tToken;
			m_pCylinder.setTransform(trToken->getTransform());
			return P_OK;
		}

	}
	else if (getExpecting() == T_ASSIGNMENT)
	{
		if (m_pCurrent == CP_RADIUS || m_pCurrent == CP_HEIGHT)
		{
			setExpecting(T_NUMBER);
			return P_OK;
		}
	}
	else if (getExpecting() == T_NUMBER)
	{
		if (m_pCurrent == CP_RADIUS)
		{
			if (!m_pCylinder.setRadius(atof(tToken->getString())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_pCurrent == CP_HEIGHT)
		{
			if (!m_pCylinder.setHeight(atof(tToken->getString())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_ENDSTATEMENT)
	{
		if (m_pCurrent == CP_RADIUS || m_pCurrent == CP_HEIGHT)
		{
			setExpecting(T_ANY);
			m_pCurrent = CP_ANY;
			return P_OK;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* CylinderParser::getToken()
{
	m_tToken.setCylinder(m_pCylinder);

	return &m_tToken;
}

//////////////////////////////////////////////////////////////////////

bool CylinderParser::setTokenLineNumber(int iLineNumber)
{
	m_tToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
