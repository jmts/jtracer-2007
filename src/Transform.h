
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Transform.h                                             //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides Geometric Transformation Facilities.           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

//////////////////////////////////////////////////////////////////////

#include "Matrix.h"
#include "Vector3.h"
#include "Ray.h"

#include "Intersect.h"

//////////////////////////////////////////////////////////////////////

class Transform
{
	private:
	Matrix m_mPointT; // Transform
	Matrix m_mPointI; // Inverse

	Matrix m_mPlaneT; // Transform
	Matrix m_mPlaneI; // Inverse

	Transform(const Matrix &mPointT);

	bool evaluate(const Matrix &mPointT);

	public:
	Transform() {}

	const static Transform makeTranslate(const Vector3 &v);
	const static Transform makeScale(const Vector3 &v);
	const static Transform makeRotateX(float fTheta);
	const static Transform makeRotateY(float fTheta);
	const static Transform makeRotateZ(float fTheta);

	const Transform inverse() const;

	Ray operator*(const Ray &rRay) const;
	Intersect operator*(const Intersect &iIntersect) const;

	Transform& operator*=(const Transform &n);
	const Transform operator*(const Transform &rhs) const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
