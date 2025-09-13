
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CameraListToken.h                                       //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Camera List Token For Parsed Camera Lists. //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _CAMERALISTTOKEN_H_
#define _CAMERALISTTOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"
#include "..\CameraList.h"

//////////////////////////////////////////////////////////////////////

class CameraListToken : public Token
{
	private:
	CameraList m_cCameras;

	public:
	CameraListToken();

	CameraListToken(const CameraListToken &rst);

	~CameraListToken() { }

	bool setCameraList(const CameraList &cCameras);

	CameraList getCameraList() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
