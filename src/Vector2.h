
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Vector2.h                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements Common 2-Dimensional Vector Operations.      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

//////////////////////////////////////////////////////////////////////

#include <ostream>

//////////////////////////////////////////////////////////////////////

class Vector2
{
	private:
	float m_x[2];

	public:
	Vector2();
	Vector2(float x, float y);

	float& operator() (unsigned int i);
	float operator() (unsigned int i) const;

	float length() const;
	float length2() const;
	const Vector2 unit() const;

	float dot(const Vector2 &u) const;

	Vector2& operator*=(float factor);
	const Vector2 operator*(float factor) const;

	Vector2 operator+=(const Vector2 &u);
	const Vector2 operator+(const Vector2 &u) const;

	const Vector2 operator-() const;
	Vector2& operator-= (const Vector2 &u);
	const Vector2 operator-(const Vector2 &u) const;

	friend std::ostream& operator<<(std::ostream& os, const Vector2 &v);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
