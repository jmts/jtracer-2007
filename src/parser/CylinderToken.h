
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CylinderToken.h                                         //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Cylinder Token For Parsed Cylinders.       //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _CYLINDERTOKEN_H_
#define _CYLINDERTOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"

#include "..\primitives\Cylinder.h"

//////////////////////////////////////////////////////////////////////

class CylinderToken : public Token
{
	private:
	Cylinder m_pCylinder;

	public:
	CylinderToken();

	CylinderToken(const CylinderToken &t);

	~CylinderToken() { }

	bool setCylinder(const Cylinder &pCylinder);

	const Cylinder& getCylinder() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
