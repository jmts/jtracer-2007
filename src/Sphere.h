
#include "Primitive.h"
#include "Ray.h"
#include "Intersect.h"

#ifndef _SPHERE_H_
#define _SPHERE_H_

class Sphere : public Primitive
{
	private:
	Vector3 m_vCenter;
	float   m_fRadius;

	public:
	Sphere() : m_vCenter(0.0f, 0.0f, 0.0f), m_fRadius(1.0f) {}

	Sphere(const Vector3 &vCenter, float fRadius)
	{
		m_vCenter = vCenter;
		m_fRadius = fRadius;
	}

	Sphere(const Vector3 &vCenter, float fRadius, const Material &mMaterial)
	{
		m_vCenter = vCenter;
		m_fRadius = fRadius;
		setMaterial(mMaterial);
	}

	Sphere(const Vector3 &vCenter, float fRadius, const Material &mMaterial, const Transform &tTransform)
	{
		m_vCenter = vCenter;
		m_fRadius = fRadius;
		setMaterial(mMaterial);
		setTransform(tTransform);
	}

	bool intersect(const Ray& rRay, Intersect &iIntersect) const
	{
		Vector3 vOC = m_vCenter - rRay.getOrigin();
		float   fLOC2 = vOC.dot(vOC);
		float   fSR2 = m_fRadius * m_fRadius;
		

		//if (fOC2 < fRadius2)
		//	Inside Sphere

		float fTCA = vOC.dot(rRay.getDirection());
		if (fLOC2 >= fSR2 && fTCA < 0.0f)
			return false; //Outside Sphere, Past Origin, Miss

		float fHC2 = fSR2 - fLOC2 + (fTCA*fTCA);
		if (fLOC2 >= fSR2 && fHC2 < 0.0f)
			return false; //Outside Sphere, Miss

		float t;
		IntersectType itType;
		if (fLOC2 >= fSR2)
		{
			// Outside, Hit
			t = fTCA - std::sqrt(fHC2);
			itType = ISECT_IN;
		}
		else
		{
			// Inside, Hit
			t = fTCA + std::sqrt(fHC2);
			itType = ISECT_OUT;
		}

		Vector3 vPoint = rRay.getOrigin() + (rRay.getDirection() * t);
		Vector3 vNormal = (vPoint - m_vCenter).unit();
		
		iIntersect.setPoint(vPoint);
		iIntersect.setNormal(vNormal);
		iIntersect.setType(itType);

		return true;
	}
};

#endif
