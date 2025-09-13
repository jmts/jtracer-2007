
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Vector4.h                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements Common 4-Dimensional Vector Operations.      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _VECTOR4_H_
#define _VECTOR4_H_

//////////////////////////////////////////////////////////////////////

#include "Vector3.h"

#include <ostream>

//////////////////////////////////////////////////////////////////////

class Vector4
{
	private:
	float m_x[4];

	public:
	Vector4();
	Vector4(float x, float y, float z, float h);
	Vector4(const Vector3 &u);
	Vector4(const Vector3 &u, float h);

	const Vector4 normalise() const;

	float dot(const Vector4 &u) const;

	float& operator() (size_t i);
	float operator() (size_t i) const;

	friend std::ostream& operator<<(std::ostream& os, const Vector4 &v);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
