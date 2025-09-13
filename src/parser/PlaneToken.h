
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PlaneToken.h                                            //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Plane Primitive Token For Parsed Planes.   //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _PLANETOKEN_H_
#define _PLANETOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"
#include "..\primitives\Plane.h"

//////////////////////////////////////////////////////////////////////

class PlaneToken : public Token
{
	private:
	Plane m_pPlane;

	public:
	PlaneToken();

	PlaneToken(const PlaneToken &t);

	~PlaneToken() { }

	bool setPlane(const Plane &pPlane);

	const Plane& getPlane() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
