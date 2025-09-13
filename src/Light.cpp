
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Light.cpp                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides An Abstract Interface For Implementing A Range //
//          Of Light Sources.                                       //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Light.h"

//////////////////////////////////////////////////////////////////////

bool Light::setPosition(const Vector3 &vPosition)
{
	m_vPosition = vPosition;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Vector3& Light::getPosition() const
{
	return m_vPosition;
}

//////////////////////////////////////////////////////////////////////
