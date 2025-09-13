
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SceneFileParser.h                                       //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Scene Description File Parser. Core Parser //
//          System For Parsing Files And Producing RenderContexts.  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _SCENEFILEPARSER_H_
#define _SCENEFILEPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Lexer.h"
#include "Parser.h"

#include "..\RenderContext.h"

#include <stack>

//////////////////////////////////////////////////////////////////////

class SceneFileParser
{
	private:
	Lexer m_lLexer;

	std::stack<Token *> m_sTokenStack;

	std::stack<Parser *> m_sParserStack;

	RenderContext m_rcContext;

	public:
	SceneFileParser() { }

	~SceneFileParser();

	Token* copyToken(const Token *tToken);
	const char* typeString(TokenType ttType);

	bool parse(const char *szFileName);
	bool parseKeywords(const Token* tToken);

	bool fillTokenStack();
	bool emptyTokenStack();
	bool emptyParserStack();

	const RenderContext& getRenderContext() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
