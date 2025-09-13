
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SphereParser.h                                          //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Sphere Primitives.              //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _SPHEREPARSER_H_
#define _SPHEREPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "SphereToken.h"

//////////////////////////////////////////////////////////////////////

class SphereParser : public Parser
{
	private:
	Sphere m_sSphere;

	SphereToken m_sToken;

	typedef enum { SP_ANY, SP_CENTER, SP_RADIUS }
		SProperty;

	SProperty m_pCurrent;

	public:
	SphereParser();

	~SphereParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
