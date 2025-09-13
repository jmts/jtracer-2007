
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CylinderToken.cpp                                       //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Cylinder Token For Parsed Cylinders.       //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "CylinderToken.h"

//////////////////////////////////////////////////////////////////////

CylinderToken::CylinderToken()
{
	setType(T_CYLINDER);
}

//////////////////////////////////////////////////////////////////////

CylinderToken::CylinderToken(const CylinderToken &t)
{
	setType(T_CYLINDER);

	setLineNumber(t.getLineNumber());

	setCylinder(t.getCylinder());
}

//////////////////////////////////////////////////////////////////////

bool CylinderToken::setCylinder(const Cylinder &pCylinder)
{
	m_pCylinder = pCylinder;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Cylinder& CylinderToken::getCylinder() const
{
	return m_pCylinder;
}

//////////////////////////////////////////////////////////////////////
