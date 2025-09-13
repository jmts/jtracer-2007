
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Ray.cpp                                                 //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides An Implementation Of A Ray For The System.     //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Ray.h"

//////////////////////////////////////////////////////////////////////

Ray::Ray(const Vector3 &vOrigin, const Vector3 &vDirection)
{
	m_vOrigin = vOrigin;
	m_vDirection = vDirection;//.unit();
}

//////////////////////////////////////////////////////////////////////

Ray::Ray(const Ray& rRay)
{
	m_vOrigin = rRay.m_vOrigin;
	m_vDirection = rRay.m_vDirection;
}

//////////////////////////////////////////////////////////////////////

const Vector3& Ray::getOrigin() const
{
	return m_vOrigin;
}

//////////////////////////////////////////////////////////////////////

const Vector3& Ray::getDirection() const
{
	return m_vDirection;
}

//////////////////////////////////////////////////////////////////////
