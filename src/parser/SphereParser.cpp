
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SphereParser.cpp                                        //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Sphere Primitives.              //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "SphereParser.h"
#include "VectorToken.h"
#include "MaterialToken.h"
#include "TransformToken.h"

//////////////////////////////////////////////////////////////////////

SphereParser::SphereParser()
{
	setExpecting(T_OPENBRACE);

	m_pCurrent = SP_ANY;
}

//////////////////////////////////////////////////////////////////////

ParseResult SphereParser::handleToken(const Token *tToken)
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
			if (strcmp(tToken->getString(), "center") == 0)
			{
				m_pCurrent = SP_CENTER;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "radius") == 0)
			{
				m_pCurrent = SP_RADIUS;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else
				return P_UNKNOWN;
		}

		if (tToken->getType() == T_MATERIAL)
		{
			MaterialToken *mToken = (MaterialToken*)tToken;
			m_sSphere.setMaterial(mToken->getMaterial());
			return P_OK;
		}

		if (tToken->getType() == T_TRANSFORM)
		{
			TransformToken *trToken = (TransformToken*)tToken;
			m_sSphere.setTransform(trToken->getTransform());
			return P_OK;
		}
	}
	else if (getExpecting() == T_ASSIGNMENT)
	{
		if (m_pCurrent == SP_RADIUS)
		{
			setExpecting(T_NUMBER);
			return P_OK;
		}
		else if (m_pCurrent == SP_CENTER)
		{
			setExpecting(T_VECTOR);
			return P_OK;
		}
	}
	else if (getExpecting() == T_NUMBER)
	{
		if (m_pCurrent == SP_RADIUS)
		{
			if (!m_sSphere.setRadius(atof(tToken->getString())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_VECTOR)
	{
		VectorToken *vtToken = (VectorToken*)tToken;
		if (m_pCurrent == SP_CENTER)
		{
			if (!m_sSphere.setCenter(vtToken->getVector()))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_ENDSTATEMENT)
	{
		if (m_pCurrent == SP_RADIUS || m_pCurrent == SP_CENTER)
		{
			setExpecting(T_ANY);
			m_pCurrent = SP_ANY;
			return P_OK;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* SphereParser::getToken()
{
	m_sToken.setSphere(m_sSphere);

	return &m_sToken;
}

//////////////////////////////////////////////////////////////////////

bool SphereParser::setTokenLineNumber(int iLineNumber)
{
	m_sToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
