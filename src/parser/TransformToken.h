
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    TransformToken.h                                        //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Transform Token For Parsed Geometric       //
//          Transformations.                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _TRANSFORMTOKEN_H_
#define _TRANSFORMTOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"

#include "..\Transform.h"

//////////////////////////////////////////////////////////////////////

class TransformToken : public Token
{
	private:
	Transform m_tTransform;

	public:
	TransformToken();

	TransformToken(const TransformToken &t);

	~TransformToken() { }

	bool setTransform(const Transform &tTransform);

	const Transform& getTransform() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
