
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PlaneParser.cpp                                         //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Plane Primitives.               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "PlaneParser.h"
#include "VectorToken.h"
#include "MaterialToken.h"
#include "TransformToken.h"

//////////////////////////////////////////////////////////////////////

PlaneParser::PlaneParser()
{
	setExpecting(T_OPENBRACE);

	m_pCurrent = PP_ANY;
}

//////////////////////////////////////////////////////////////////////

ParseResult PlaneParser::handleToken(const Token *tToken)
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
			if (strcmp(tToken->getString(), "normal") == 0)
			{
				m_pCurrent = PP_NORMAL;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "distance") == 0)
			{
				m_pCurrent = PP_DISTANCE;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else
				return P_UNKNOWN;
		}

		if (tToken->getType() == T_MATERIAL)
		{
			MaterialToken *mToken = (MaterialToken*)tToken;

			m_pPlane.setMaterial(mToken->getMaterial());

			return P_OK;
		}

		if (tToken->getType() == T_TRANSFORM)
		{
			TransformToken *trToken = (TransformToken*)tToken;
			m_pPlane.setTransform(trToken->getTransform());
			return P_OK;
		}
	}
	else if (getExpecting() == T_ASSIGNMENT)
	{
		if (m_pCurrent == PP_DISTANCE)
		{
			setExpecting(T_NUMBER);

			return P_OK;
		}
		else if (m_pCurrent == PP_NORMAL)
		{
			setExpecting(T_VECTOR);

			return P_OK;
		}
	}
	else if (getExpecting() == T_NUMBER)
	{
		if (m_pCurrent == PP_DISTANCE)
		{
			if (!m_pPlane.setDistance(atof(tToken->getString())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_VECTOR)
	{
		VectorToken *vtToken = (VectorToken*)tToken;
		if (m_pCurrent == PP_NORMAL)
		{
			if (!m_pPlane.setNormal(vtToken->getVector()))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_ENDSTATEMENT)
	{
		if (m_pCurrent == PP_DISTANCE || m_pCurrent == PP_NORMAL)
		{
			setExpecting(T_ANY);
			m_pCurrent = PP_ANY;
			return P_OK;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* PlaneParser::getToken()
{
	m_tToken.setPlane(m_pPlane);

	return &m_tToken;
}

//////////////////////////////////////////////////////////////////////

bool PlaneParser::setTokenLineNumber(int iLineNumber)
{
	m_tToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
