
#ifndef _INTERSECT_H_
#define _INTERSECT_H_

typedef enum { ISECT_IN, ISECT_OUT } IntersectType;

class Intersect
{
	private:
	Vector3 m_vPoint;
	Vector3 m_vNormal;
	IntersectType m_itType;

	public:

	Intersect() {}

	Intersect(const Vector3 &vPoint, const Vector3 &vNormal, IntersectType itType)
	{
		m_vPoint = vPoint;
		m_vNormal = vNormal;
		m_itType = itType;
	}

	bool setType(IntersectType itType)
	{
		m_itType = itType;
		return true;
	}

	IntersectType getType() const
	{
		return m_itType;
	}

	bool setPoint(const Vector3 &vPoint)
	{
		m_vPoint = vPoint;
		return true;
	}

	Vector3 getPoint() const
	{
		return m_vPoint;
	}

	bool setNormal(const Vector3 &vNormal)
	{
		m_vNormal = vNormal;
		return true;
	}

	Vector3 getNormal() const
	{
		return m_vNormal;
	}
};

#endif
