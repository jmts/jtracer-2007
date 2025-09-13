
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderSettingsParser.h                                  //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Render Settings.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RENDERSETTINGSPARSER_H_
#define _RENDERSETTINGSPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "RenderSettingsToken.h"

//////////////////////////////////////////////////////////////////////

class RenderSettingsParser : public Parser
{
	private:
	RenderSettings m_rsSettings;

	RenderSettingsToken m_rsToken;

	typedef enum { RSP_ANY,
		RSP_WIDTH, RSP_HEIGHT,
		RSP_RECURSEDEPTH,
		RSP_CAMERA, RSP_FILENAME,
		RSP_AMBIENT, RSP_BACKGROUND }
		RSProperty;

	RSProperty m_rspCurrent;

	public:
	RenderSettingsParser();

	~RenderSettingsParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
