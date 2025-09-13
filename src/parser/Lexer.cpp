
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Lexer.cpp                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Lexical Analyser For Scene Description     //
//          Language.                                               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Lexer.h"

//////////////////////////////////////////////////////////////////////

Lexer::Lexer()
{
	m_bCharSaved = false;

	m_iLineNumber = 1;

	m_fp = 0;
}

//////////////////////////////////////////////////////////////////////

Lexer::~Lexer()
{
	close();
}

//////////////////////////////////////////////////////////////////////

bool Lexer::open(const char *szFileName)
{
	std::FILE *fp = std::fopen(szFileName, "r");

	if (fp)
	{
		if (m_fp)
			fclose(m_fp);

		m_fp = fp;
		return true;
	}

	m_bCharSaved = false;

	return false;
}

//////////////////////////////////////////////////////////////////////

bool Lexer::close()
{
	if (m_fp)
	{
		fclose(m_fp);
		m_fp = 0;

		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////

bool Lexer::isWhite(int ch)
{
	switch(ch)
	{
		case ' ':
		case '\t':
		case '\r':
		case '\n':
			return true;
		default:
			return false;
	}
}

//////////////////////////////////////////////////////////////////////

bool Lexer::isAlpha(int ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return true;

	return false;
}

//////////////////////////////////////////////////////////////////////

bool Lexer::isNumeric(int ch)
{
	if (ch >= '0' && ch <= '9')
		return true;

	return false;
}

//////////////////////////////////////////////////////////////////////

bool Lexer::isIdentifier(int ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == '_'))
		return true;

	return false;
}

//////////////////////////////////////////////////////////////////////

bool Lexer::isString(int ch)
{
	if (ch >= ' ' && ch <= '~' && ch != '\"')
		return true;

	return false;
}

//////////////////////////////////////////////////////////////////////

int Lexer::getChar()
{
	if (m_bCharSaved)
	{
		m_bCharSaved = false;

		return m_iChar;
	}

	return fgetc(m_fp);
}

//////////////////////////////////////////////////////////////////////

bool Lexer::saveChar(int ch)
{
	m_iChar = ch;
	m_bCharSaved = true;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Token* Lexer::retToken(TokenType ttType)
{
	m_tToken.setType(ttType);
	m_tToken.setLineNumber(m_iLineNumber);

	if (ttType == T_EOF || ttType == T_ERROR || ttType == T_EMPTY)
		m_tToken.setString(0);
	else
		m_tToken.setString(m_szToken);

	return &m_tToken;
}

//////////////////////////////////////////////////////////////////////
// getToken - Returns The Next General Token In The File /////////////
//////////////////////////////////////////////////////////////////////

const Token* Lexer::getToken()
{
	// Consume Whitespace
	int ch = getChar();
	while (isWhite(ch) || ch == '#')
	{
		if (ch == '#')
		{
			ch = getChar();
			while (ch != '\n' && ch != EOF)
				ch = getChar();
		}

		if (ch == '\n')
			m_iLineNumber++;

		ch = getChar();
	}

	int i = 0;
	TokenType ttType;

	// Handle End Of File
	if (ch == EOF)
	{
		ttType = T_EOF;
	}

	// Handle Identifiers
	else if (isAlpha(ch))
	{
		m_szToken[i++] = ch;
		while (isIdentifier((ch = getChar())))
			m_szToken[i++] = ch;

		ttType = T_IDENTIFIER;
		saveChar(ch);
	}

	// Handle Numbers
	else if (isNumeric(ch) || ch == '-')
	{
		if (ch == '-')
		{
			m_szToken[i++] = ch;
			ch = getChar();
		}

		m_szToken[i++] = ch;

		if (ch == '0')
		{
			ch = getChar();

			if (ch == '.')
			{
				m_szToken[i++] = ch;
				ch = getChar();
				if (isNumeric(ch))
				{
					m_szToken[i++] = ch;

					while (isNumeric((ch = getChar())))
						m_szToken[i++] = ch;

					ttType = T_NUMBER;
				}
				else
					ttType = T_ERROR;
			}
			else if (isNumeric(ch))
				ttType = T_ERROR;
			else
				ttType = T_NUMBER;
		}
		else if (isNumeric(ch))
		{
			// Chomp Integer
			while (isNumeric((ch = getChar())))
				m_szToken[i++] = ch;

			if (ch == '.')
			{
				m_szToken[i++] = ch;
				ch = getChar();
				if (isNumeric(ch))
				{
					m_szToken[i++] = ch;

					while (isNumeric((ch = getChar())))
						m_szToken[i++] = ch;

					ttType = T_NUMBER;
				}
				else
					ttType = T_ERROR;
			}
			else
				ttType = T_NUMBER;
		}
		else
			ttType = T_ERROR;

		saveChar(ch);
	}

	// Handle Strings
	else if (ch == '"')
	{
		while (isString((ch = getChar())))
			m_szToken[i++] = ch;
		if (ch == '"')
			ttType = T_STRING;
		else
			ttType = T_ERROR;
	}

	// Handle Braces
	else if (ch == '{')
	{
		m_szToken[i++] = ch;
		ttType = T_OPENBRACE;
	}
	else if (ch == '}')
	{
		m_szToken[i++] = ch;
		ttType = T_CLOSEBRACE;
	}

	// Handle Vector Brackets
	else if (ch == '<')
	{
		m_szToken[i++] = ch;
		ttType = T_OPENVECTOR;
	}
	else if (ch == '>')
	{
		m_szToken[i++] = ch;
		ttType = T_CLOSEVECTOR;
	}

	// Separators
	else if (ch == ',')
	{
		m_szToken[i++] = ch;
		ttType = T_SEPARATOR;
	}

	// Assignments
	else if (ch == ':')
	{
		m_szToken[i++] = ch;
		ttType = T_ASSIGNMENT;
	}

	// End Of Statement
	else if (ch == ';')
	{
		m_szToken[i++] = ch;
		ttType = T_ENDSTATEMENT;
	}

	// All Else
	else
	{
		ttType = T_ERROR;
	}

	m_szToken[i] = '\0';

	return retToken(ttType);
}

//////////////////////////////////////////////////////////////////////
