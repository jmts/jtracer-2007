
/////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Plane.cpp                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Plane Primitive.                           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Plane.h"

//////////////////////////////////////////////////////////////////////

bool Plane::evaluate()
{
	Vector3 vUnit = m_vNormal.unit();

	Vector3 vPoint = vUnit * m_fDistance;

	m_vPlane = Vector4(vUnit, -(vUnit.dot(vPoint)));

	m_vNormal = vUnit;

	return true;
}

//////////////////////////////////////////////////////////////////////

Plane::Plane()
{
	setNormal(Vector3(0.0f, 1.0f, 0.0f));

	setDistance(0.0f);

	evaluate();
}

//////////////////////////////////////////////////////////////////////

Plane::Plane(const Vector3 &vNormal, float fDistance, const Material &mMaterial)
{
	setNormal(vNormal);

	setDistance(fDistance);

	evaluate();

	setMaterial(mMaterial);
}

//////////////////////////////////////////////////////////////////////

bool Plane::setNormal(const Vector3 &vNormal)
{
	if (vNormal.length2() == 0.0f)
		return false;

	m_vNormal = vNormal;

	evaluate();

	return true;
}

const Vector3& Plane::getNormal() const
{
	return m_vNormal;
}

//////////////////////////////////////////////////////////////////////

bool Plane::setDistance(float fDistance)
{
	m_fDistance = fDistance;

	evaluate();

	return true;
}

float Plane::getDistance() const
{
	return m_fDistance;
}

//////////////////////////////////////////////////////////////////////

bool Plane::intersect(const Ray& rRay, Intersect &iIntersect, const IntersectConditions &icExclude) const
{
	IntersectType itType = ISECT_IN;

	float fDot = m_vNormal.dot(rRay.getDirection());
	if (fDot == 0.0f)
		return false;

	if (fDot > 0.0f)
		itType = ISECT_OUT;

	Vector4 vOrigin(rRay.getOrigin());
	float t = (-m_vPlane.dot(vOrigin)) / fDot;

	if ((t < 0.0f) || (icExclude.getPrimitive() == this && itType == icExclude.getExcludeType()))
		return false;

	Vector3 vPoint = rRay.getOrigin() + (rRay.getDirection() * t);

	iIntersect.setType(itType);
	iIntersect.setPoint(vPoint);
	iIntersect.setNormal(m_vNormal);
	iIntersect.setPrimitive(this);
	iIntersect.setT(t);

	return true;
}

//////////////////////////////////////////////////////////////////////
