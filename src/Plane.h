
#include "Vector3.h"
#include "Vector4.h"
#include "Primitive.h"
#include "Ray.h"
#include "Intersect.h"

#ifndef _PLANE_H_
#define _PLANE_H_

class Plane : public Primitive
{
	private:
	Vector4 m_vPlane;

	public:
	Plane() : m_vPlane(0.0f, 1.0f, 0.0f, 0.0f) {}

	Plane(const Vector4 &vPlane)
	{
		m_vPlane = vPlane;
	}

	Plane(const Vector3 &vNormal, float fDistance)
	{
		Vector3 vUnit = vNormal.unit();

		Vector3 vPoint = vUnit*fDistance;

		m_vPlane = Vector4(vUnit, -(vUnit.dot(vPoint)));
	}

	bool intersect(const Ray& rRay, Intersect &iIntersect) const
	{
		Vector4 vOrigin(rRay.getOrigin());

		Vector3 vNormal(m_vPlane(0), m_vPlane(1), m_vPlane(2));

		float fDenom = (vNormal.dot(rRay.getDirection()));
		IntersectType itType = ISECT_IN;
		if (fDenom == 0.0f)
			return false;
		else if (fDenom > 0.0f)
			itType = ISECT_OUT;

		float t = (-(m_vPlane.dot(vOrigin))) / fDenom;

		if (t < 0.0f)
			return false;

		Vector3 vPoint = rRay.getOrigin() + (rRay.getDirection() * t);

		iIntersect.setType(itType);
		iIntersect.setPoint(vPoint);
		iIntersect.setNormal(vNormal);

		return true;
	}
};

#endif
