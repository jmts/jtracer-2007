
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Sphere.h                                                //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Sphere Primitive.                          //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _SPHERE_H_
#define _SPHERE_H_

//////////////////////////////////////////////////////////////////////

#include "..\Primitive.h"
#include "..\Vector3.h"

//////////////////////////////////////////////////////////////////////

class Sphere : public Primitive
{
	private:
	Vector3 m_vCenter;
	float   m_fRadius;

	public:
	Sphere() : m_vCenter(0.0f, 0.0f, 0.0f), m_fRadius(1.0f) {}

	Sphere(const Vector3 &vCenter, float fRadius);
	Sphere(const Vector3 &vCenter, float fRadius, const Material &mMaterial);
	Sphere(const Vector3 &vCenter, float fRadius, const Material &mMaterial, const Transform &tTransform);

	bool setCenter(const Vector3 &vCenter);
	const Vector3& getCenter() const;

	bool setRadius(float fRadius);
	float getRadius() const;

	bool intersect(const Ray& rRay, Intersect &iIntersect, const IntersectConditions &icExclude) const;

	friend std::ostream& operator<<(std::ostream& os, const Sphere &s);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
