
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    TransformParser.cpp                                     //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Geometric Transformations.      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "TransformParser.h"
#include "VectorToken.h"

//////////////////////////////////////////////////////////////////////

TransformParser::TransformParser()
{
	setExpecting(T_OPENBRACE);

	m_pCurrent = TP_ANY;
}

//////////////////////////////////////////////////////////////////////

ParseResult TransformParser::handleToken(const Token *tToken)
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
			if (strcmp(tToken->getString(), "translate") == 0)
			{
				m_pCurrent = TP_TRANSLATE;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "scale") == 0)
			{
				m_pCurrent = TP_SCALE;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "xrotate") == 0)
			{
				m_pCurrent = TP_XROTATE;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "yrotate") == 0)
			{
				m_pCurrent = TP_YROTATE;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "zrotate") == 0)
			{
				m_pCurrent = TP_ZROTATE;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else
				return P_UNKNOWN;
		}
	}
	else if (getExpecting() == T_ASSIGNMENT)
	{
		if (m_pCurrent == TP_TRANSLATE || m_pCurrent == TP_SCALE)
		{
			setExpecting(T_VECTOR);
			return P_OK;
		}
		else if (m_pCurrent == TP_XROTATE || m_pCurrent == TP_YROTATE || m_pCurrent == TP_ZROTATE)
		{
			setExpecting(T_NUMBER);
			return P_OK;
		}
	}
	else if (getExpecting() == T_VECTOR)
	{
		VectorToken *vToken = (VectorToken*)tToken;
		if (m_pCurrent == TP_TRANSLATE)
		{
			m_tTransform = Transform::makeTranslate(vToken->getVector()) * m_tTransform;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_pCurrent == TP_SCALE)
		{
			Vector3 vVector = vToken->getVector();
			if (vVector(0) == 0.0 || vVector(1) == 0.0 || vVector(2) == 0.0)
				return P_ERRORVAL;

			m_tTransform = Transform::makeScale(vVector) * m_tTransform;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_NUMBER)
	{
		if (m_pCurrent == TP_XROTATE)
		{
			m_tTransform = Transform::makeRotateX(atof(tToken->getString())) * m_tTransform;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_pCurrent == TP_YROTATE)
		{
			m_tTransform = Transform::makeRotateY(atof(tToken->getString())) * m_tTransform;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_pCurrent == TP_ZROTATE)
		{
			m_tTransform = Transform::makeRotateZ(atof(tToken->getString())) * m_tTransform;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_ENDSTATEMENT)
	{
		switch(m_pCurrent)
		{
			case TP_TRANSLATE:
			case TP_SCALE:
			case TP_XROTATE:
			case TP_YROTATE:
			case TP_ZROTATE:
				setExpecting(T_ANY);
				m_pCurrent = TP_ANY;
				return P_OK;
			default:
				;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* TransformParser::getToken()
{
	m_tToken.setTransform(m_tTransform);

	return &m_tToken;
}

//////////////////////////////////////////////////////////////////////

bool TransformParser::setTokenLineNumber(int iLineNumber)
{
	m_tToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
