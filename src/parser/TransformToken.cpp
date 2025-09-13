
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    TransformToken.cpp                                      //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Transform Token For Parsed Geometric       //
//          Transformations.                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "TransformToken.h"

//////////////////////////////////////////////////////////////////////

TransformToken::TransformToken()
{
	setType(T_TRANSFORM);
}

//////////////////////////////////////////////////////////////////////

TransformToken::TransformToken(const TransformToken &t)
{
	setType(T_TRANSFORM);

	setLineNumber(t.getLineNumber());

	setTransform(t.getTransform());
}

//////////////////////////////////////////////////////////////////////

bool TransformToken::setTransform(const Transform &tTransform)
{
	m_tTransform = tTransform;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Transform& TransformToken::getTransform() const
{
	return m_tTransform;
}

//////////////////////////////////////////////////////////////////////
