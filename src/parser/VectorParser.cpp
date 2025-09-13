
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    VectorParser.cpp                                        //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Vector Elements.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "VectorParser.h"

#include <cstdlib>

//////////////////////////////////////////////////////////////////////

VectorParser::VectorParser()
{
	m_iIndex = 0;

	setExpecting(T_NUMBER);
}

//////////////////////////////////////////////////////////////////////

ParseResult VectorParser::handleToken(const Token *tToken)
{
	if (getExpecting() != T_ANY && getExpecting() != tToken->getType())
		return P_UNEXPECTED;

	if (tToken->getType() == T_NUMBER)
	{
		m_vVector(m_iIndex++) = std::atof(tToken->getString());

		if (m_iIndex == 3)
			setExpecting(T_CLOSEVECTOR);
		else
			setExpecting(T_SEPARATOR);

		return P_OK;
	}

	if (tToken->getType() == T_SEPARATOR)
	{
		setExpecting(T_NUMBER);

		return P_OK;
	}

	if (tToken->getType() == T_CLOSEVECTOR)
	{
		return P_COMPLETE;
	}

	return P_ERROR;
}

//////////////////////////////////////////////////////////////////////

const Token* VectorParser::getToken()
{
	m_vtToken.setVector(m_vVector);

	return &m_vtToken;
}

//////////////////////////////////////////////////////////////////////

bool VectorParser::setTokenLineNumber(int iLineNumber)
{
	m_vtToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
