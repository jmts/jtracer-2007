
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Color.h                                                 //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Encapsulates Common Colour Operations.                  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _COLOR_H_
#define _COLOR_H_

//////////////////////////////////////////////////////////////////////

#include "Vector3.h"

#include <ostream>

//////////////////////////////////////////////////////////////////////

class Color
{
	private:
	float m_x[3];

	public:
	Color();
	Color(float fRed, float fGreen, float fBlue);

	Color(const Color &d);
	Color(const Vector3 &v);

	float& operator() (unsigned int i);
	float operator() (unsigned int i) const;

	Color operator+=(const Color &u);
	const Color operator+(const Color &u) const;

	Color operator*=(const Color &u);
	const Color operator*(const Color &u) const;

	Color& operator*=(float factor);
	const Color operator*(float factor) const;

	const Color clip() const;

	bool nonZero() const;

	friend std::ostream& operator<<(std::ostream& os, const Color &c);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
