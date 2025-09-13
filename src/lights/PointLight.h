
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PointLight.h                                            //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Point Light Light Source.                  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _POINTLIGHT_H_
#define _POINTLIGHT_H_

//////////////////////////////////////////////////////////////////////

#include "..\Light.h"

//////////////////////////////////////////////////////////////////////

class PointLight : public Light
{
	private:
	Color m_cIntensity;

	public:
	PointLight() {}

	PointLight(const Vector3 &vPosition, const Color &cIntensity);

	bool setIntensity(const Color &cIntensity);

	const Color& getIntensity(const Vector3 &vPoint) const;

	bool isVisible(const Vector3 &vPoint) const;

	friend std::ostream& operator<<(std::ostream& os, const PointLight &l);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
