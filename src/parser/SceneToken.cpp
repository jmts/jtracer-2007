
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SceneToken.cpp                                          //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Scene Collection Token For Parsed Scenes.  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "SceneToken.h"

//////////////////////////////////////////////////////////////////////

SceneToken::SceneToken()
{
	setType(T_SCENE);
}

//////////////////////////////////////////////////////////////////////

SceneToken::SceneToken(const SceneToken &t)
{
	setType(T_SCENE);
	setLineNumber(t.getLineNumber());
	m_sScene = t.m_sScene;
}

//////////////////////////////////////////////////////////////////////

bool SceneToken::setScene(const Scene &sScene)
{
	m_sScene = sScene;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Scene& SceneToken::getScene() const
{
	return m_sScene;
}

//////////////////////////////////////////////////////////////////////
