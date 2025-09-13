
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Primitive.cpp                                           //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Generalised Interface To Enable The          //
//          Implementation Of A Variety Of Geometric Primitives.    //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Primitive.h"

//////////////////////////////////////////////////////////////////////

const Transform& Primitive::getTransform() const
{
	return m_tTransform;
}

//////////////////////////////////////////////////////////////////////

bool Primitive::setTransform(const Transform &tTransform)
{
	m_tTransform = tTransform;
	return true;
}

//////////////////////////////////////////////////////////////////////

const Material& Primitive::getMaterial() const
{
	return m_mMaterial;
}

//////////////////////////////////////////////////////////////////////

bool Primitive::setMaterial(const Material &mMaterial)
{
	m_mMaterial = mMaterial;

	return true;
}

//////////////////////////////////////////////////////////////////////
