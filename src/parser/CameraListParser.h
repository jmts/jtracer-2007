
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CameraListParser.h                                      //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Camera Lists.                   //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _CAMERALISTPARSER_H_
#define _CAMERALISTPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "CameraListToken.h"

//////////////////////////////////////////////////////////////////////

class CameraListParser : public Parser
{
	private:
	CameraList m_cCameras;

	CameraListToken m_cToken;

	typedef enum { CLP_ANY }
		CLProperty;

	CLProperty m_clpCurrent;

	public:
	CameraListParser();

	~CameraListParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
