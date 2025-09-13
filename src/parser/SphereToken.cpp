
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SphereToken.cpp                                         //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Sphere Primitive Token For Parsed Spheres. //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "SphereToken.h"

//////////////////////////////////////////////////////////////////////

SphereToken::SphereToken()
{
	setType(T_SPHERE);
}

//////////////////////////////////////////////////////////////////////

SphereToken::SphereToken(const SphereToken &t)
{
	setType(T_SPHERE);
	setLineNumber(t.getLineNumber());
	m_sSphere = t.getSphere();
}

//////////////////////////////////////////////////////////////////////

bool SphereToken::setSphere(const Sphere &sSphere)
{
	m_sSphere = sSphere;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Sphere& SphereToken::getSphere() const
{
	return m_sSphere;
}

//////////////////////////////////////////////////////////////////////
