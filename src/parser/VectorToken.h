
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    VectorToken.h                                           //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Vector Token For Parsed Vectors.           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _VECTORTOKEN_H_
#define _VECTORTOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"

#include "..\Vector3.h"

//////////////////////////////////////////////////////////////////////

class VectorToken : public Token
{
	private:
	Vector3 m_vVector;

	public:
	VectorToken();

	VectorToken(const VectorToken &vt);

	~VectorToken() { }

	bool setVector(const Vector3 &v);

	const Vector3& getVector() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
