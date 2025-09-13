
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PerspectiveCameraToken.h                                //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Perspective Camera Token For Parsed        //
//          Perspective Cameras.                                    //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _PERSPECTIVECAMERATOKEN_H_
#define _PERSPECTIVECAMERATOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"
#include "..\cameras\PerspectiveCamera.h"

//////////////////////////////////////////////////////////////////////

class PerspectiveCameraToken : public Token
{
	private:
	PerspectiveCamera m_cCamera;

	public:
	PerspectiveCameraToken();

	PerspectiveCameraToken(const PerspectiveCameraToken &pct);

	~PerspectiveCameraToken() { }

	bool setPerspectiveCamera(const PerspectiveCamera &cCamera);

	const PerspectiveCamera& getPerspectiveCamera() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
