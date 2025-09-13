
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Intersect.h                                             //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Encapsulates Important Intersection Information         //
//          Used In Ray Tracing At Intersection Points.             //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _INTERSECT_H_
#define _INTERSECT_H_

//////////////////////////////////////////////////////////////////////

#include "Vector3.h"

//#include "Primitive.h"

//////////////////////////////////////////////////////////////////////

typedef enum { ISECT_IN, ISECT_OUT } IntersectType;

//////////////////////////////////////////////////////////////////////

class Primitive;

//////////////////////////////////////////////////////////////////////

class Intersect
{
	private:
	Vector3 m_vPoint;				// Intersection Point
	Vector3 m_vNormal;				// Normal At Intersection Point

	const Primitive *m_pPrimitive;	// Primitive Intersected

	IntersectType m_itType;			// Inward/Outward Intersection

	float m_fT;						// t Value At Intersection Point

	public:
	Intersect();
	Intersect(const Vector3 &vPoint, const Vector3 &vNormal, IntersectType itType, const Primitive *pPrimitive);
	Intersect(const Vector3 &vPoint, const Vector3 &vNormal, IntersectType itType, const Primitive *pPrimitive, float fT);

	bool setType(IntersectType itType);
	IntersectType getType() const;

	bool setPoint(const Vector3 &vPoint);
	Vector3 getPoint() const;

	bool setNormal(const Vector3 &vNormal);
	Vector3 getNormal() const;

	bool setPrimitive(const Primitive *pPrimitive);
	const Primitive* getPrimitive() const;

	bool setT(float fT);
	float getT() const;
};

//////////////////////////////////////////////////////////////////////

class IntersectConditions
{
	private:
	const Primitive *m_pPrimitive;	// Primitive To Exclude
	IntersectType m_itExclude;		// Direction To Exclude

	public:
	IntersectConditions();
	IntersectConditions(const Primitive *pPrimitive, IntersectType itExclude);

	const Primitive* getPrimitive() const;

	IntersectType getExcludeType() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
