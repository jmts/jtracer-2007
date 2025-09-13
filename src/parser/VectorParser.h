
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    VectorParser.h                                          //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Vector Elements.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _VECTORPARSER_H_
#define _VECTORPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "VectorToken.h"

//////////////////////////////////////////////////////////////////////

class VectorParser : public Parser
{
	private:
	VectorToken m_vtToken;

	int m_iIndex;
	Vector3 m_vVector;

	public:
	VectorParser();

	~VectorParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
