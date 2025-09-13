
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PerspectiveCameraParser.h                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Perspective Cameras.            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _PERSPECTIVECAMERAPARSER_H_
#define _PERSPECTIVECAMERAPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "PerspectiveCameraToken.h"

//////////////////////////////////////////////////////////////////////

class PerspectiveCameraParser : public Parser
{
	private:
	PerspectiveCamera m_cCamera;

	PerspectiveCameraToken m_cToken;

	typedef enum { PCP_ANY, PCP_NAME, PCP_POSITION, PCP_LOOKAT, PCP_UP, PCP_FOV, PCP_ASPECT }
		PCProperty;

	PCProperty m_pcpCurrent;

	public:
	PerspectiveCameraParser();

	~PerspectiveCameraParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
