
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Parser.h                                                //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Generalised Parser Interface.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _PARSER_H_
#define _PARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"

//////////////////////////////////////////////////////////////////////

typedef enum { P_UNKNOWN, P_ERROR, P_ERRORVAL, P_UNEXPECTED, P_COMPLETE, P_OK } ParseResult;

//////////////////////////////////////////////////////////////////////

class Parser
{
	private:
	TokenType m_tExpecting;

	public:
	Parser();

	bool setExpecting(TokenType tExpecting);
	TokenType getExpecting() const;

	virtual bool setTokenLineNumber(int iLineNumber) = 0;
	virtual ParseResult handleToken(const Token *tToken) = 0;
	virtual const Token* getToken() = 0;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
