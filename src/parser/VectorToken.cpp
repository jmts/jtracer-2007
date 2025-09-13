
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    VectorToken.cpp                                         //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Vector Token For Parsed Vectors.           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "VectorToken.h"

//////////////////////////////////////////////////////////////////////

VectorToken::VectorToken()
{
	setType(T_VECTOR);
}

//////////////////////////////////////////////////////////////////////

VectorToken::VectorToken(const VectorToken &vt)
{
	setType(T_VECTOR);
	setVector(vt.getVector());
	setLineNumber(vt.getLineNumber());
}

//////////////////////////////////////////////////////////////////////

bool VectorToken::setVector(const Vector3 &v)
{
	m_vVector = v;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Vector3& VectorToken::getVector() const
{
	return m_vVector;
}

//////////////////////////////////////////////////////////////////////
