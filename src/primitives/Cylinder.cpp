
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Cylinder.cpp                                            //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Cylinder Primitive.                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Cylinder.h"

#include "..\Vector2.h"

#include <cmath>

//////////////////////////////////////////////////////////////////////

Cylinder::Cylinder(float fRadius, float fHeight)
{
	m_fRadius = 0.5;
	m_fHeight = 1.0;

	setRadius(fRadius);
	setHeight(fHeight);
}

//////////////////////////////////////////////////////////////////////

Cylinder::Cylinder(float fRadius, float fHeight, const Material &mMaterial)
{
	m_fRadius = 0.5;
	m_fHeight = 1.0;

	setRadius(fRadius);
	setHeight(fHeight);
	setMaterial(mMaterial);
}

//////////////////////////////////////////////////////////////////////

Cylinder::Cylinder(float fRadius, float fHeight, const Material &mMaterial, const Transform &tTransform)
{
	m_fRadius = 0.5;
	m_fHeight = 1.0;

	setRadius(fRadius);
	setHeight(fHeight);
	setMaterial(mMaterial);
	setTransform(tTransform);
}

//////////////////////////////////////////////////////////////////////

bool Cylinder::setRadius(float fRadius)
{
	if (fRadius <= 0.0)
		return false;

	m_fRadius = fRadius;

	return true;
}

float Cylinder::getRadius() const
{
	return m_fRadius;
}

//////////////////////////////////////////////////////////////////////

bool Cylinder::setHeight(float fHeight)
{
	if (fHeight <= 0.0)
		return false;

	m_fHeight = fHeight;

	return true;
}

float Cylinder::getHeight() const
{
	return m_fHeight;
}

//////////////////////////////////////////////////////////////////////

bool Cylinder::intersect(const Ray& rRay, Intersect &iIntersect, const IntersectConditions &icExclude) const
{
	const Vector3 &vOrigin = rRay.getOrigin();
	const Vector3 &vDirection = rRay.getDirection();

	float fTopCap = m_fHeight;
	float fBottomCap = 0.0f;

	if (vDirection(1) > 0 && vOrigin(1) > fTopCap)
		return false;

	if (vDirection(1) < 0 && vOrigin(1) < fBottomCap)
		return false;

	Vector2 v2Origin    = -Vector2(vOrigin(0), vOrigin(2));
	Vector2 v2Direction = Vector2(vDirection(0), vDirection(2));

	float f2Origin2 = v2Origin.dot(v2Origin);
	float fRadius2 = m_fRadius * m_fRadius;

	if (f2Origin2 < fRadius2 && vOrigin(1) < fTopCap && vOrigin(1) > fBottomCap)
	{
		// Inside Cylinder
		if (icExclude.getExcludeType() == ISECT_OUT && icExclude.getPrimitive() == this)
			return false;

		return false;
	}
	else
	{
		// Outside Cylinder
		if (icExclude.getExcludeType() == ISECT_IN && icExclude.getPrimitive() == this)
			return false;

		// Test Top
		if (vDirection(1) < 0.0f && vOrigin(1) > fTopCap)
		{
			float t = (fTopCap - vOrigin(1)) / vDirection(1);
			Vector3 vPoint = vOrigin + (vDirection * t);
			Vector2 v2Point(vPoint(0), vPoint(2));
			if (v2Point.dot(v2Point) < fRadius2)
			{
				iIntersect.setPoint(vPoint);
				iIntersect.setNormal(Vector3(0, 1, 0));
				iIntersect.setType(ISECT_IN);
				iIntersect.setPrimitive(this);
				iIntersect.setT(t);

				return true;
			}
		}

		// Test Bottom
		else if (vDirection(1) > 0.0f && vOrigin(1) < fBottomCap)
		{
			float t = (fBottomCap - vOrigin(1)) / vDirection(1);

			//float t = (vOrigin(1) - m_fBottomCap) / vDirection(1);
			Vector3 vPoint = vOrigin + (vDirection * t);
			Vector2 v2Point(vPoint(0), vPoint(2));
			if (v2Point.dot(v2Point) < fRadius2)
			{
				iIntersect.setPoint(vPoint);
				iIntersect.setNormal(Vector3(0, -1, 0));
				iIntersect.setType(ISECT_IN);
				iIntersect.setPrimitive(this);
				iIntersect.setT(t);

				return true;
			}
		}

		// Test Body
		float fProjT = v2Origin.dot(v2Direction);
		if (fProjT < 0.0f)
			return false;	// Outside, Points Away

		fProjT /= v2Direction.length();

		float fHalfChord2 = fRadius2 - f2Origin2 + (fProjT * fProjT);
		if (fHalfChord2 < 0.0f)
			return false;

		float t = (fProjT - std::sqrt(fHalfChord2)) / v2Direction.length();
		Vector3 vPoint = vOrigin + (vDirection * t);
		if (vPoint(1) > fTopCap || vPoint(1) < fBottomCap)
			return false;

		Vector3 vNormal = Vector3(vPoint(0), 0.0, vPoint(2)).unit();
		iIntersect.setPoint(vPoint);
		iIntersect.setNormal(vNormal);
		iIntersect.setType(ISECT_IN);
		iIntersect.setPrimitive(this);
		iIntersect.setT(t);

		return true;
	}

	//return false;
}

//////////////////////////////////////////////////////////////////////
