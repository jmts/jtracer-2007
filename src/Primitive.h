
#include "Ray.h"
#include "Intersect.h"
#include "Transform.h"
#include "Material.h"

#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

class Primitive
{
	private:
	Transform m_tTransform;
	Material m_mMaterial;

	public:
	Primitive() {}

	virtual bool intersect(const Ray& rRay, Intersect &iIntersect) const = 0;

	Transform getTransform() const
	{
		return m_tTransform;
	}

	bool setTransform(const Transform &tTransform)
	{
		m_tTransform = tTransform;
		return true;
	}

	Material getMaterial() const
	{
		return m_mMaterial;
	}

	bool setMaterial(const Material &mMaterial)
	{
		m_mMaterial = mMaterial;
		return true;
	}
};

#endif
