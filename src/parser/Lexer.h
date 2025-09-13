
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Lexer.h                                                 //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Lexical Analyser For Scene Description     //
//          Language.                                               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _LEXER_H_
#define _LEXER_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"

#include <cstdio>

//////////////////////////////////////////////////////////////////////

class Lexer
{
	private:
	char m_szToken[256];

	int m_iLineNumber;

	bool m_bCharSaved;
	int  m_iChar;

	std::FILE *m_fp;

	Token m_tToken;

	public:
	Lexer();
	~Lexer();

	bool open(const char *szFileName);
	bool close();

	bool isWhite(int ch);
	bool isAlpha(int ch);
	bool isNumeric(int ch);
	bool isIdentifier(int ch);
	bool isString(int ch);

	int getChar();
	bool saveChar(int ch);

	const Token* getToken();
	const Token* retToken(TokenType ttType);

};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
