
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Cylinder.h                                              //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Cylinder Primitive.                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _CYLINDER_H_
#define _CYLINDER_H_

//////////////////////////////////////////////////////////////////////

#include "..\Primitive.h"

//////////////////////////////////////////////////////////////////////

class Cylinder : public Primitive
{
	private:
	float m_fRadius;
	float m_fHeight;

	public:
	Cylinder() : m_fRadius(0.5f), m_fHeight(1.0f) {}
	Cylinder(float fRadius, float fHeight);
	Cylinder(float fRadius, float fHeight, const Material &mMaterial);
	Cylinder(float fRadius, float fHeight, const Material &mMaterial, const Transform &tTransform);

	bool setRadius(float fRadius);
	float getRadius() const;

	bool setHeight(float fHeight);
	float getHeight() const;

	bool intersect(const Ray& rRay, Intersect &iIntersect, const IntersectConditions &icExclude) const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
