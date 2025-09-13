
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PointLight.cpp                                          //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Point Light Light Source.                  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "PointLight.h"

//////////////////////////////////////////////////////////////////////

PointLight::PointLight(const Vector3 &vPosition, const Color &cIntensity)
{
	setPosition(vPosition);

	m_cIntensity = cIntensity;
}

//////////////////////////////////////////////////////////////////////

bool PointLight::setIntensity(const Color &cIntensity)
{
	m_cIntensity = cIntensity;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Color& PointLight::getIntensity(const Vector3 &vPoint) const
{
	return m_cIntensity;
}

//////////////////////////////////////////////////////////////////////

bool PointLight::isVisible(const Vector3 &vPoint) const
{
	return true;
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const PointLight &l)
{
	os << "Position: " << l.getPosition() << std::endl;
	os << "Intensity: " << l.getIntensity(Vector3()) << std::endl;

	return os;
}

//////////////////////////////////////////////////////////////////////
