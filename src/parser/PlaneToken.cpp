
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PlaneToken.cpp                                          //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Plane Primitive Token For Parsed Planes.   //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "PlaneToken.h"

//////////////////////////////////////////////////////////////////////

PlaneToken::PlaneToken()
{
	setType(T_PLANE);
}

//////////////////////////////////////////////////////////////////////

PlaneToken::PlaneToken(const PlaneToken &t) : m_pPlane(t.getPlane())
{
	setType(T_PLANE);

	setLineNumber(t.getLineNumber());

	//m_pPlane = t.getPlane();
}

//////////////////////////////////////////////////////////////////////

bool PlaneToken::setPlane(const Plane &pPlane)
{
	m_pPlane = pPlane;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Plane& PlaneToken::getPlane() const
{
	return m_pPlane;
}

//////////////////////////////////////////////////////////////////////
