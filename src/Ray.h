
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Ray.h                                                   //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides An Implementation Of A Ray For The System.     //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RAY_H_
#define _RAY_H_

//////////////////////////////////////////////////////////////////////

#include "Vector3.h"

//////////////////////////////////////////////////////////////////////

class Ray
{
	private:
	Vector3 m_vOrigin;
	Vector3 m_vDirection;

	public:
	Ray() : m_vOrigin(0,0,0), m_vDirection(0,0,1) { }
	Ray(const Vector3 &vOrigin, const Vector3 &vDirection);
	Ray(const Ray& rRay);

	const Vector3& getOrigin() const;
	const Vector3& getDirection() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
