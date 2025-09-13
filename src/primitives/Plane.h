
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Plane.h                                                 //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Plane Primitive.                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _PLANE_H_
#define _PLANE_H_

//////////////////////////////////////////////////////////////////////

#include "..\Primitive.h"
#include "..\Vector3.h"
#include "..\Vector4.h"

//#include "Ray.h"
//#include "Intersect.h"

//////////////////////////////////////////////////////////////////////

class Plane : public Primitive
{
	private:
	Vector3 m_vNormal;
	float   m_fDistance;

	Vector4 m_vPlane;

	bool evaluate();

	public:
	Plane();
	Plane(const Vector3 &vNormal, float fDistance, const Material &mMaterial);

	bool setNormal(const Vector3 &vNormal);
	const Vector3& getNormal() const;

	bool setDistance(float fDistance);
	float getDistance() const;

	bool intersect(const Ray& rRay, Intersect &iIntersect, const IntersectConditions &icExclude) const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
