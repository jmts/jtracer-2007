
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    MaterialParser.cpp                                      //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Material Definitions.           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "MaterialParser.h"
#include "VectorToken.h"

//////////////////////////////////////////////////////////////////////

MaterialParser::MaterialParser()
{
	setExpecting(T_OPENBRACE);

	m_mpCurrent = MP_ANY;
}

//////////////////////////////////////////////////////////////////////

ParseResult MaterialParser::handleToken(const Token *tToken)
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
			if (strcmp(tToken->getString(), "pigment") == 0)
			{
				m_mpCurrent = MP_PIGMENT;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "ambient") == 0)
			{
				m_mpCurrent = MP_AMBIENT;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "diffuse") == 0)
			{
				m_mpCurrent = MP_DIFFUSE;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "diffuse_k") == 0)
			{
				m_mpCurrent = MP_DIFFUSEK;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "specular") == 0)
			{
				m_mpCurrent = MP_SPECULAR;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "specular_k") == 0)
			{
				m_mpCurrent = MP_SPECULARK;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else if (strcmp(tToken->getString(), "reflection") == 0)
			{
				m_mpCurrent = MP_REFLECTION;
				setExpecting(T_ASSIGNMENT);
				return P_OK;
			}
			else
				return P_UNKNOWN;
		}
	}
	else if (getExpecting() == T_ASSIGNMENT)
	{
		if (m_mpCurrent == MP_DIFFUSEK || m_mpCurrent == MP_SPECULARK || m_mpCurrent == MP_REFLECTION)
		{
			setExpecting(T_NUMBER);
			return P_OK;
		}
		else if (m_mpCurrent == MP_PIGMENT || m_mpCurrent == MP_AMBIENT || m_mpCurrent == MP_DIFFUSE || m_mpCurrent == MP_SPECULAR)
		{
			setExpecting(T_VECTOR);
			return P_OK;
		}
	}
	else if (getExpecting() == T_NUMBER)
	{
		if (m_mpCurrent == MP_DIFFUSEK)
		{
			if (!m_mMaterial.setDiffuseK(atof(tToken->getString())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_mpCurrent == MP_SPECULARK)
		{
			if (!m_mMaterial.setSpecularK(atof(tToken->getString())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_mpCurrent == MP_REFLECTION)
		{
			if (!m_mMaterial.setReflectionK(atof(tToken->getString())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_VECTOR)
	{
		VectorToken *vtToken = (VectorToken*)tToken;
		if (m_mpCurrent == MP_PIGMENT)
		{
			if (!m_mMaterial.setPigment(Color(vtToken->getVector())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_mpCurrent == MP_AMBIENT)
		{
			if (!m_mMaterial.setAmbientColor(Color(vtToken->getVector())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_mpCurrent == MP_DIFFUSE)
		{
			if (!m_mMaterial.setDiffuseColor(Color(vtToken->getVector())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
		else if (m_mpCurrent == MP_SPECULAR)
		{
			if (!m_mMaterial.setSpecularColor(Color(vtToken->getVector())))
				return P_ERRORVAL;

			setExpecting(T_ENDSTATEMENT);
			return P_OK;
		}
	}
	else if (getExpecting() == T_ENDSTATEMENT)
	{
		if (m_mpCurrent == MP_DIFFUSEK || m_mpCurrent == MP_SPECULARK || m_mpCurrent == MP_REFLECTION)
		{
			setExpecting(T_ANY);
			m_mpCurrent = MP_ANY;
			return P_OK;
		}
		else if (m_mpCurrent == MP_PIGMENT || m_mpCurrent == MP_AMBIENT || m_mpCurrent == MP_DIFFUSE || m_mpCurrent == MP_SPECULAR)
		{
			setExpecting(T_ANY);
			m_mpCurrent = MP_ANY;
			return P_OK;
		}
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* MaterialParser::getToken()
{
	m_mToken.setMaterial(m_mMaterial);

	return &m_mToken;
}

//////////////////////////////////////////////////////////////////////

bool MaterialParser::setTokenLineNumber(int iLineNumber)
{
	m_mToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
