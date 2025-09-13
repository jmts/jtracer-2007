
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Sphere.cpp                                              //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Sphere Primitive.                          //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Sphere.h"

//////////////////////////////////////////////////////////////////////

Sphere::Sphere(const Vector3 &vCenter, float fRadius)
{
	m_vCenter = vCenter;
	m_fRadius = fRadius;
}

//////////////////////////////////////////////////////////////////////

Sphere::Sphere(const Vector3 &vCenter, float fRadius, const Material &mMaterial)
{
	m_vCenter = vCenter;
	m_fRadius = fRadius;
	setMaterial(mMaterial);
}

//////////////////////////////////////////////////////////////////////

Sphere::Sphere(const Vector3 &vCenter, float fRadius, const Material &mMaterial, const Transform &tTransform)
{
	m_vCenter = vCenter;
	m_fRadius = fRadius;
	setMaterial(mMaterial);
	setTransform(tTransform);
}

//////////////////////////////////////////////////////////////////////

bool Sphere::setCenter(const Vector3 &vCenter)
{
	m_vCenter = vCenter;
	return true;
}

const Vector3& Sphere::getCenter() const
{
	return m_vCenter;
}

//////////////////////////////////////////////////////////////////////

bool Sphere::setRadius(float fRadius)
{
	if (fRadius <= 0.0f)
		return false;

	m_fRadius = fRadius;
	return true;
}

float Sphere::getRadius() const
{
	return m_fRadius;
}

//////////////////////////////////////////////////////////////////////

bool Sphere::intersect(const Ray& rRay, Intersect &iIntersect, const IntersectConditions &icExclude) const
{
	Vector3 vOrigin = m_vCenter - rRay.getOrigin();
	float   fOrigin2 = vOrigin.dot(vOrigin);
	float   fRadius2 = m_fRadius * m_fRadius;

	float t;
	IntersectType itType;
	if (fOrigin2 < fRadius2) // Inside Sphere
	{
		if (icExclude.getPrimitive() == this && icExclude.getExcludeType() == ISECT_OUT)
			return false;

		//float fDirection2 = rRay.getDirection().dot(rRay.getDirection());

		float fProjT = vOrigin.dot(rRay.getDirection()) / rRay.getDirection().length();

		float fHalfChord2 = fRadius2 + (fProjT * fProjT) - fOrigin2;

		t = fProjT + std::sqrt(fHalfChord2);
		itType = ISECT_OUT;
	}
	else // Outside Sphere
	{
		float fProjT = vOrigin.dot(rRay.getDirection());
		if (fProjT < 0.0f)
			return false; // Outside, Points Away

		//float fDirection2 = rRay.getDirection().dot(rRay.getDirection());
		fProjT /= rRay.getDirection().length();

		float fHalfChord2 = fRadius2 - fOrigin2 + ((fProjT * fProjT));// / fDirection2);
		if (fHalfChord2 < 0.0f)
			return false;

		t = (fProjT - std::sqrt(fHalfChord2)) / rRay.getDirection().length();
		itType = ISECT_IN;
	}

	Vector3 vPoint = rRay.getOrigin() + (rRay.getDirection() * t);
	Vector3 vNormal = (vPoint - m_vCenter).unit();

	iIntersect.setPoint(vPoint);
	iIntersect.setNormal(vNormal);
	iIntersect.setType(itType);
	iIntersect.setPrimitive(this);
	iIntersect.setT(t);

	return true;
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Sphere &s)
{
	os << "Center: " << s.getCenter() << std::endl;
	os << "Radius: " << s.getRadius() << std::endl;
	os << "Material: " << s.getMaterial() << std::endl;

	return os;
}

//////////////////////////////////////////////////////////////////////
