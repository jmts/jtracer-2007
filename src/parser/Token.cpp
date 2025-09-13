
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Token.cpp                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Generalised Token Interface For Lexer And    //
//          Parser Implementations.                                 //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Token.h"

//////////////////////////////////////////////////////////////////////

Token::Token()
{
	m_szString = 0;
	m_iLineNumber = 0;
}

//////////////////////////////////////////////////////////////////////

Token::Token(const Token &t)
{
	setType(t.getType());

	m_szString = 0;
	setString(t.getString());

	m_iLineNumber = 0;
	setLineNumber(t.getLineNumber());
}

//////////////////////////////////////////////////////////////////////

Token::~Token()
{
	if (m_szString)
		delete [] m_szString;
}

//////////////////////////////////////////////////////////////////////

bool Token::setType(TokenType ttType)
{
	m_ttType = ttType;

	return true;
}

//////////////////////////////////////////////////////////////////////

TokenType Token::getType() const
{
	return m_ttType;
}

//////////////////////////////////////////////////////////////////////

bool Token::setString(const char* szString)
{
	if (szString)
	{
		int len = std::strlen(szString);

		char *szNewString = new char[len+1];

		std::strcpy(szNewString, szString);

		if (m_szString)
			delete [] m_szString;

		m_szString = szNewString;
	}
	else
	{
		if (m_szString)
		{
			delete [] m_szString;
			m_szString = 0;
		}
	}

	return true;
}

//////////////////////////////////////////////////////////////////////

const char* Token::getString() const
{
	return m_szString;
}

//////////////////////////////////////////////////////////////////////

bool Token::setLineNumber(int iLineNumber)
{
	m_iLineNumber = iLineNumber;
	return true;
}

//////////////////////////////////////////////////////////////////////

int Token::getLineNumber() const
{
	return m_iLineNumber;
}

//////////////////////////////////////////////////////////////////////
