
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PointLightParser.h                                      //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Point Lights.                   //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _POINTLIGHTPARSER_H_
#define _POINTLIGHTPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "PointLightToken.h"

//////////////////////////////////////////////////////////////////////

class PointLightParser : public Parser
{
	private:
	PointLight m_lPointLight;

	PointLightToken m_plToken;

	typedef enum { PLP_ANY, PLP_POSITION, PLP_INTENSITY }
		PLProperty;

	PLProperty m_pCurrent;

	public:
	PointLightParser();

	~PointLightParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
