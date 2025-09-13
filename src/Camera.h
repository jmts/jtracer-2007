
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Camera.h                                                //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Generalised Camera Model To Allow Support  //
//          For A Range Of Specialised Cameras With Varying         //
//          Projection Systems.                                     //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _CAMERA_H_
#define _CAMERA_H_

//////////////////////////////////////////////////////////////////////

#include "Ray.h"

//////////////////////////////////////////////////////////////////////

class Camera
{
	private:
	char *m_szName;

	public:
	Camera();
	virtual ~Camera();

	virtual bool init() = 0;

	virtual Ray getRay(float x, float y) const = 0;

	const char* getName() const;
	bool setName(const char *szName);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
