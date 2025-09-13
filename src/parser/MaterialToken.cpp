
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    MaterialToken.cpp                                       //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Material Token For Parsed Material         //
//          Definitions.                                            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "MaterialToken.h"

//////////////////////////////////////////////////////////////////////

MaterialToken::MaterialToken()
{
	setType(T_MATERIAL);
}

//////////////////////////////////////////////////////////////////////

MaterialToken::MaterialToken(const MaterialToken &t)
{
	setType(T_MATERIAL);
	setLineNumber(t.getLineNumber());
	m_mMaterial = t.getMaterial();
}

//////////////////////////////////////////////////////////////////////

bool MaterialToken::setMaterial(const Material &mMaterial)
{
	m_mMaterial = mMaterial;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Material& MaterialToken::getMaterial() const
{
	return m_mMaterial;
}

//////////////////////////////////////////////////////////////////////
