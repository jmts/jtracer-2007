
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderSettingsToken.cpp                                 //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Render Settings Token For Parsed Render    //
//          Settings Structures.                                    //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "RenderSettingsToken.h"

//////////////////////////////////////////////////////////////////////

RenderSettingsToken::RenderSettingsToken()
{
	setType(T_RENDERSETTINGS);
}

//////////////////////////////////////////////////////////////////////

RenderSettingsToken::RenderSettingsToken(const RenderSettingsToken &rst)
{
	setType(T_RENDERSETTINGS);
	setLineNumber(rst.getLineNumber());
	m_rsSettings = rst.m_rsSettings;
}

//////////////////////////////////////////////////////////////////////

bool RenderSettingsToken::setRenderSettings(const RenderSettings &rsSettings)
{
	m_rsSettings = rsSettings;
	return true;
}

//////////////////////////////////////////////////////////////////////

RenderSettings RenderSettingsToken::getRenderSettings() const
{
	return m_rsSettings;
}

//////////////////////////////////////////////////////////////////////
