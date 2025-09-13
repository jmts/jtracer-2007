
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderSettingsToken.h                                   //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Render Settings Token For Parsed Render    //
//          Settings Structures.                                    //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RENDERSETTINGSTOKEN_H_
#define _RENDERSETTINGSTOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"

#include "..\RenderSettings.h"

//////////////////////////////////////////////////////////////////////

class RenderSettingsToken : public Token
{
	private:
	RenderSettings m_rsSettings;

	public:
	RenderSettingsToken();

	RenderSettingsToken(const RenderSettingsToken &rst);

	~RenderSettingsToken() { }

	bool setRenderSettings(const RenderSettings &rsSettings);

	RenderSettings getRenderSettings() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
