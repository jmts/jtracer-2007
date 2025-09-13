
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SceneToken.h                                            //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Scene Collection Token For Parsed Scenes.  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _SCENETOKEN_H_
#define _SCENETOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"

#include "..\Scene.h"

//////////////////////////////////////////////////////////////////////

class SceneToken : public Token
{
	private:
	Scene m_sScene;

	public:
	SceneToken();

	SceneToken(const SceneToken &t);

	~SceneToken() { }

	bool setScene(const Scene &sScene);

	const Scene& getScene() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
