
#include "Vector3.h"

#ifndef _RAY_H_
#define _RAY_H_

class Ray
{
	private:
	Vector3 m_vOrigin;
	Vector3 m_vDirection;

	public:
	Ray() { }

	Ray(const Vector3 &vOrigin, const Vector3 &vDirection)
	{
		m_vOrigin = vOrigin;
		m_vDirection = vDirection.unit();
	}

	Ray(const Ray& rRay)
	{
		m_vOrigin = rRay.m_vOrigin;
		m_vDirection = rRay.m_vDirection;
	}

	Vector3 getOrigin() const
	{
		return m_vOrigin;
	}

	Vector3 getDirection() const
	{
		return m_vDirection;
	}
};

#endif
