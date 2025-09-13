
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CylinderParser.h                                        //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Cylinders.                      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _CYLINDERPARSER_H_
#define _CYLINDERPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "CylinderToken.h"

//////////////////////////////////////////////////////////////////////

class CylinderParser : public Parser
{
	private:
	Cylinder m_pCylinder;

	CylinderToken m_tToken;

	typedef enum { CP_ANY, CP_HEIGHT, CP_RADIUS }
		CProperty;

	CProperty m_pCurrent;

	public:
	CylinderParser();

	~CylinderParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
