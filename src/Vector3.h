
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Vector3.h                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements Common 3-Dimensional Vector Operations.      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

//////////////////////////////////////////////////////////////////////

#include <ostream>

//////////////////////////////////////////////////////////////////////

class Vector3
{
	private:
	float m_x[3];

	public:
	Vector3();
	Vector3(float x, float y, float z);

	float& operator() (unsigned int i);
	float operator() (unsigned int i) const;

	float length() const;
	float length2() const;
	const Vector3 unit() const;

	float dot(const Vector3 &u) const;
	const Vector3 cross(Vector3 u);

	Vector3& operator*=(float factor);
	const Vector3 operator*(float factor) const;

	Vector3 operator+=(const Vector3 &u);
	const Vector3 operator+(const Vector3 &u) const;

	const Vector3 operator-() const;
	Vector3& operator-= (const Vector3 &u);
	const Vector3 operator-(const Vector3 &u) const;

	friend std::ostream& operator<<(std::ostream& os, const Vector3 &v);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
