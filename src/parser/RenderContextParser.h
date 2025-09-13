
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderContextParser.h                                   //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Render Contexts.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RENDERCONTEXTPARSER_H_
#define _RENDERCONTEXTPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "RenderContextToken.h"

//////////////////////////////////////////////////////////////////////

class RenderContextParser : public Parser
{
	private:
	RenderContext m_rcContext;

	RenderContextToken m_tToken;

	public:
	RenderContextParser();

	~RenderContextParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
