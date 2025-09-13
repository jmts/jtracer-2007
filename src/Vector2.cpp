
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Vector2.cpp                                             //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements Common 2-Dimensional Vector Operations.      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Vector2.h"
#include <cmath>

//////////////////////////////////////////////////////////////////////

Vector2::Vector2()
{
	Vector2 &v = *this;

	v(0) = 0;
	v(1) = 0;
}

//////////////////////////////////////////////////////////////////////

Vector2::Vector2(float x, float y)
{
	Vector2 &v = *this;

	v(0) = x;
	v(1) = y;
}

//////////////////////////////////////////////////////////////////////

float& Vector2::operator() (unsigned int i)
{
	return m_x[i];
}

float Vector2::operator() (unsigned int i) const
{
	return m_x[i];
}

//////////////////////////////////////////////////////////////////////

const Vector2 Vector2::unit() const
{
	const Vector2 &v = *this;

	float len = length();

	return Vector2(v(0) / len, v(1) / len);
}

//////////////////////////////////////////////////////////////////////

float Vector2::length2() const
{
	const Vector2 &v = *this;

	return (v(0)*v(0) + v(1)*v(1));
}

//////////////////////////////////////////////////////////////////////

float Vector2::length() const
{
	return (std::sqrt(length2()));
}

//////////////////////////////////////////////////////////////////////

float Vector2::dot(const Vector2 &u) const
{
	const Vector2 &v = *this;

	return (v(0)*u(0) + v(1)*u(1));
}

//////////////////////////////////////////////////////////////////////

Vector2& Vector2::operator*=(float factor)
{
	Vector2 &v = *this;
	v(0) *= factor;
	v(1) *= factor;

	return *this;
}

const Vector2 Vector2::operator*(float factor) const
{
	return Vector2(*this) *= factor;
}

//////////////////////////////////////////////////////////////////////

Vector2 Vector2::operator+=(const Vector2 &u)
{
	Vector2 &v = *this;
	v(0) += u(0);
	v(1) += u(1);

	return *this;
}

const Vector2 Vector2::operator+(const Vector2 &u) const
{
	return Vector2(*this) += u;
}

//////////////////////////////////////////////////////////////////////

const Vector2 Vector2::operator-() const
{
	const Vector2 &v = *this;

	return Vector2(-v(0), -v(1));
}

Vector2& Vector2::operator-= (const Vector2 &u)
{
	Vector2 &v = *this;

	v(0) -= u(0);
	v(1) -= u(1);

	return *this;
}

const Vector2 Vector2::operator-(const Vector2 &u) const
{
	return Vector2(*this) -= u;
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Vector2 &v)
{
	os << "(" << v(0) << ", " << v(1) << ")";

	return os;
}

//////////////////////////////////////////////////////////////////////
