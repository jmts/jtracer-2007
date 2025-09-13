
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Light.h                                                 //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides An Abstract Interface For Implementing A Range //
//          Of Light Sources.                                       //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _LIGHT_H_
#define _LIGHT_H_

//////////////////////////////////////////////////////////////////////

#include "Vector3.h"
#include "Color.h"

//////////////////////////////////////////////////////////////////////

class Light
{
	private:
	Vector3 m_vPosition;

	public:
	virtual bool isVisible(const Vector3 &vPoint) const = 0;
	virtual const Color& getIntensity(const Vector3 &vPoint) const = 0;

	bool setPosition(const Vector3 &vPosition);

	const Vector3& getPosition() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
