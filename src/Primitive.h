
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Primitive.h                                             //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Generalised Interface To Enable The          //
//          Implementation Of A Variety Of Geometric Primitives.    //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

//////////////////////////////////////////////////////////////////////

#include "Transform.h"
#include "Material.h"
#include "Ray.h"
#include "Intersect.h"

//////////////////////////////////////////////////////////////////////

class Primitive
{
	private:
	Transform m_tTransform;
	Material m_mMaterial;

	public:
	Primitive() {}

	virtual bool intersect(const Ray& rRay, Intersect &iIntersect, const IntersectConditions &icExclude) const = 0;

	const Transform& getTransform() const;
	bool setTransform(const Transform &tTransform);

	const Material& getMaterial() const;
	bool setMaterial(const Material &mMaterial);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
