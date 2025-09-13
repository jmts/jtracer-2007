
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SphereToken.h                                           //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Sphere Primitive Token For Parsed Spheres. //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _SPHERETOKEN_H_
#define _SPHERETOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"

#include "..\primitives\Sphere.h"

//////////////////////////////////////////////////////////////////////

class SphereToken : public Token
{
	private:
	Sphere m_sSphere;

	public:
	SphereToken();

	SphereToken(const SphereToken &t);

	~SphereToken() { }

	bool setSphere(const Sphere &sSphere);

	const Sphere& getSphere() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
