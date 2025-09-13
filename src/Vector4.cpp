
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Vector4.cpp                                             //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements Common 4-Dimensional Vector Operations.      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Vector4.h"

//////////////////////////////////////////////////////////////////////

Vector4::Vector4()
{
	Vector4 &v = *this;

	v(0) = 0;
	v(1) = 0;
	v(2) = 0;
	v(3) = 1;
}

//////////////////////////////////////////////////////////////////////

Vector4::Vector4(float x, float y, float z, float h)
{
	Vector4 &v = *this;

	v(0) = x;
	v(1) = y;
	v(2) = z;
	v(3) = h;
}

//////////////////////////////////////////////////////////////////////

Vector4::Vector4(const Vector3 &u)
{
	Vector4 &v = *this;
	v(0) = u(0);
	v(1) = u(1);
	v(2) = u(2);
	v(3) = 1.0;
}

//////////////////////////////////////////////////////////////////////

Vector4::Vector4(const Vector3 &u, float h)
{
	Vector4 &v = *this;
	v(0) = u(0);
	v(1) = u(1);
	v(2) = u(2);
	v(3) = h;
}

//////////////////////////////////////////////////////////////////////

const Vector4 Vector4::normalise() const
{
	const Vector4 &v = *this;

	return Vector4(v(0)/v(3), v(1)/v(3), v(2)/v(3), 1);
}

//////////////////////////////////////////////////////////////////////

float Vector4::dot(const Vector4 &u) const
{
	const Vector4 &v = *this;

	return (v(0)*u(0) + v(1)*u(1) + v(2)*u(2) + v(3)*u(3));
}

//////////////////////////////////////////////////////////////////////

float& Vector4::operator() (size_t i)
{
	return m_x[i];
}

float Vector4::operator() (size_t i) const
{
	return m_x[i];
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Vector4 &v)
{
	os << "(" << v(0) << ", " << v(1) << ", " << v(2) << ", " << v(3) << ")";

	return os;
}

//////////////////////////////////////////////////////////////////////
