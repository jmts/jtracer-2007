
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Color.cpp                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Encapsulates Common Colour Operations.                  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Color.h"

//////////////////////////////////////////////////////////////////////

Color::Color()
{
	Color &c = *this;

	c(0) = 0.0;
	c(1) = 0.0;
	c(2) = 0.0;
}

//////////////////////////////////////////////////////////////////////

Color::Color(float fRed, float fGreen, float fBlue)
{
	Color &c = *this;

	c(0) = fRed;
	c(1) = fGreen;
	c(2) = fBlue;
}

//////////////////////////////////////////////////////////////////////

Color::Color(const Color &d)
{
	Color &c = *this;
	c(0) = d(0);
	c(1) = d(1);
	c(2) = d(2);
}

//////////////////////////////////////////////////////////////////////

Color::Color(const Vector3 &v)
{
	Color &c = *this;

	float fRed   = v(0);
	float fGreen = v(1);
	float fBlue  = v(2);

	fRed   = (fRed   < 0.0f) ? 0.0f : fRed;
	fGreen = (fGreen < 0.0f) ? 0.0f : fGreen;
	fBlue  = (fBlue  < 0.0f) ? 0.0f : fBlue;

	fRed   = (fRed   > 1.0f) ? 1.0f : fRed;
	fGreen = (fGreen > 1.0f) ? 1.0f : fGreen;
	fBlue  = (fBlue  > 1.0f) ? 1.0f : fBlue;

	c(0) = fRed;
	c(1) = fGreen;
	c(2) = fBlue;
}

//////////////////////////////////////////////////////////////////////

float& Color::operator() (unsigned int i)
{
	return m_x[i];
}

float Color::operator() (unsigned int i) const
{
	return m_x[i];
}

//////////////////////////////////////////////////////////////////////

Color Color::operator+=(const Color &u)
{
	Color &c = *this;
	c(0) += u(0);
	c(1) += u(1);
	c(2) += u(2);

	return *this;
}

const Color Color::operator+(const Color &u) const
{
	return Color(*this) += u;
}

//////////////////////////////////////////////////////////////////////

Color Color::operator*=(const Color &u)
{
	Color &c = *this;
	c(0) *= u(0);
	c(1) *= u(1);
	c(2) *= u(2);

	return *this;
}

const Color Color::operator*(const Color &u) const
{
	return Color(*this) *= u;
}

//////////////////////////////////////////////////////////////////////

Color& Color::operator*=(float factor)
{
	Color &c = *this;
	c(0) *= factor;
	c(1) *= factor;
	c(2) *= factor;

	return *this;
}

const Color Color::operator*(float factor) const
{
	return Color(*this) *= factor;
}

//////////////////////////////////////////////////////////////////////
// clip - Return A Colour With Values Clipped Between 0.0 And 1.0 ////
//////////////////////////////////////////////////////////////////////

const Color Color::clip() const
{
	const Color &c = *this;

	float fRed   = c(0);
	float fGreen = c(1);
	float fBlue  = c(2);

	fRed   = (fRed   < 0.0f) ? 0.0f : fRed;
	fGreen = (fGreen < 0.0f) ? 0.0f : fGreen;
	fBlue  = (fBlue  < 0.0f) ? 0.0f : fBlue;

	fRed   = (fRed   > 1.0f) ? 1.0f : fRed;
	fGreen = (fGreen > 1.0f) ? 1.0f : fGreen;
	fBlue  = (fBlue  > 1.0f) ? 1.0f : fBlue;

	return Color(fRed, fGreen, fBlue);
}

//////////////////////////////////////////////////////////////////////
// nonZero - Returns True If A Colour Is Not Black ///////////////////
//////////////////////////////////////////////////////////////////////

bool Color::nonZero() const
{
	const Color &c = *this;
	if (c(0) > 0.0 || c(1) > 0.0 || c(2) > 0.0)
		return true;

	return false;
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Color &c)
{
	os << "(" << c(0) << ", " << c(1) << ", " << c(2) << ")";

	return os;
}

//////////////////////////////////////////////////////////////////////
