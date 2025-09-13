
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Transform.cpp                                           //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides Geometric Transformation Facilities.           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Transform.h"

//////////////////////////////////////////////////////////////////////

Transform::Transform(const Matrix &mPointT)
{
	evaluate(mPointT);
}

//////////////////////////////////////////////////////////////////////

bool Transform::evaluate(const Matrix &mPointT)
{
	m_mPointT = mPointT;
	m_mPlaneT = m_mPointT.inverse().transpose();

	m_mPointI = m_mPointT.inverse();
	m_mPlaneI = m_mPointI.inverse().transpose();

	return true;
}

//////////////////////////////////////////////////////////////////////

const Transform Transform::makeTranslate(const Vector3 &v)
{
	Matrix mPointT = Matrix::makeTranslate(v);

	return Transform(mPointT);
}

//////////////////////////////////////////////////////////////////////

const Transform Transform::makeScale(const Vector3 &v)
{
	Matrix mPointT = Matrix::makeScale(v);

	return Transform(mPointT);
}

//////////////////////////////////////////////////////////////////////

const Transform Transform::makeRotateX(float fTheta)
{
	Matrix mPointT = Matrix::makeRotateX(fTheta * (M_PI/180.0f));

	return Transform(mPointT);
}

//////////////////////////////////////////////////////////////////////

const Transform Transform::makeRotateY(float fTheta)
{
	Matrix mPointT = Matrix::makeRotateY(fTheta * (M_PI/180.0f));

	return Transform(mPointT);
}

//////////////////////////////////////////////////////////////////////

const Transform Transform::makeRotateZ(float fTheta)
{
	Matrix mPointT = Matrix::makeRotateZ(fTheta * (M_PI/180.0f));

	return Transform(mPointT);
}

//////////////////////////////////////////////////////////////////////

const Transform Transform::inverse() const
{
	return Transform(m_mPointI);
}

//////////////////////////////////////////////////////////////////////

Ray Transform::operator*(const Ray &rRay) const
{
	Vector4 v4Origin(rRay.getOrigin());
	Vector4 v4Direction(rRay.getDirection(), 0.0f);

	v4Origin    = m_mPointT * v4Origin;
	v4Direction = m_mPointT * v4Direction;

	Vector3 v3Origin(v4Origin(0),v4Origin(1),v4Origin(2));
	Vector3 v3Direction(v4Direction(0), v4Direction(1), v4Direction(2));

	return Ray(v3Origin, v3Direction);
}

//////////////////////////////////////////////////////////////////////

Intersect Transform::operator*(const Intersect &iIntersect) const
{
	Vector4 v4Point(iIntersect.getPoint());
	Vector4 v4Normal(iIntersect.getNormal(), 0.0f);

	v4Point  = m_mPointT * v4Point;
	v4Normal = m_mPlaneT * v4Normal;

	Vector3 v3Point(v4Point(0), v4Point(1), v4Point(2));
	Vector3 v3Normal(v4Normal(0), v4Normal(1), v4Normal(2));

	return Intersect(v3Point, v3Normal.unit(), iIntersect.getType(), iIntersect.getPrimitive(), iIntersect.getT());
}

//////////////////////////////////////////////////////////////////////

Transform& Transform::operator*=(const Transform &n)
{
	evaluate(m_mPointT * n.m_mPointT);

	return *this;
}

//////////////////////////////////////////////////////////////////////

const Transform Transform::operator*(const Transform &rhs) const
{
	return Transform(*this) *= rhs;
}

//////////////////////////////////////////////////////////////////////
