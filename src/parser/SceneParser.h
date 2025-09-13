
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SceneParser.h                                           //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Scene Element Collections.      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _SCENEPARSER_H_
#define _SCENEPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "SceneToken.h"

//////////////////////////////////////////////////////////////////////

class SceneParser : public Parser
{
	private:
	Scene m_sScene;

	SceneToken m_tToken;

	public:
	SceneParser();

	~SceneParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
