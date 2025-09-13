
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Intersect.cpp                                           //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Encapsulates Important Intersection Information         //
//          Used In Ray Tracing At Intersection Points.             //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Intersect.h"

//////////////////////////////////////////////////////////////////////

Intersect::Intersect()
{
	m_pPrimitive = 0;
	m_fT = 0.0;
}

//////////////////////////////////////////////////////////////////////

Intersect::Intersect(const Vector3 &vPoint, const Vector3 &vNormal, IntersectType itType, const Primitive *pPrimitive)
{
	m_vPoint = vPoint;
	m_vNormal = vNormal;
	m_itType = itType;
	m_pPrimitive = pPrimitive;
	m_fT = 0.0;
}

//////////////////////////////////////////////////////////////////////

Intersect::Intersect(const Vector3 &vPoint, const Vector3 &vNormal, IntersectType itType, const Primitive *pPrimitive, float fT)
{
	m_vPoint = vPoint;
	m_vNormal = vNormal;
	m_itType = itType;
	m_pPrimitive = pPrimitive;
	m_fT = fT;
}

//////////////////////////////////////////////////////////////////////

bool Intersect::setType(IntersectType itType)
{
	m_itType = itType;
	return true;
}

IntersectType Intersect::getType() const
{
	return m_itType;
}

//////////////////////////////////////////////////////////////////////

bool Intersect::setPoint(const Vector3 &vPoint)
{
	m_vPoint = vPoint;
	return true;
}

Vector3 Intersect::getPoint() const
{
	return m_vPoint;
}

//////////////////////////////////////////////////////////////////////

bool Intersect::setNormal(const Vector3 &vNormal)
{
	m_vNormal = vNormal;
	return true;
}

Vector3 Intersect::getNormal() const
{
	return m_vNormal;
}

//////////////////////////////////////////////////////////////////////

bool Intersect::setPrimitive(const Primitive *pPrimitive)
{
	m_pPrimitive = pPrimitive;

	return true;
}

const Primitive* Intersect::getPrimitive() const
{
	return m_pPrimitive;
}

//////////////////////////////////////////////////////////////////////

bool Intersect::setT(float fT)
{
	m_fT = fT;

	return true;
}

float Intersect::getT() const
{
	return m_fT;
}

//////////////////////////////////////////////////////////////////////

IntersectConditions::IntersectConditions()
{
	m_pPrimitive = 0;
}

//////////////////////////////////////////////////////////////////////

IntersectConditions::IntersectConditions(const Primitive *pPrimitive, IntersectType itExclude)
{
	m_pPrimitive = pPrimitive;
	m_itExclude = itExclude;
}

//////////////////////////////////////////////////////////////////////

const Primitive* IntersectConditions::getPrimitive() const
{
	return m_pPrimitive;
}

//////////////////////////////////////////////////////////////////////

IntersectType IntersectConditions::getExcludeType() const
{
	return m_itExclude;
}

//////////////////////////////////////////////////////////////////////
