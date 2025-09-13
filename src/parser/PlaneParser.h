
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PlaneParser.h                                           //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Plane Primitives.               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _PLANEPARSER_H_
#define _PLANEPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "PlaneToken.h"

//////////////////////////////////////////////////////////////////////

class PlaneParser : public Parser
{
	private:
	Plane m_pPlane;

	PlaneToken m_tToken;

	typedef enum { PP_ANY, PP_NORMAL, PP_DISTANCE }
		PProperty;

	PProperty m_pCurrent;

	public:
	PlaneParser();

	~PlaneParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
