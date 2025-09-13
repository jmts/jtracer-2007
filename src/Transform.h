
#include "Vector3.h"
#include "Matrix.h"
#include "Intersect.h"

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

class Transform
{
	private:
	Matrix m_mPointT; // Transform
	Matrix m_mPointI; // Inverse

	Matrix m_mPlaneT; // Transform
	Matrix m_mPlaneI; // Inverse

	Transform(const Matrix &mPointT, const Matrix &mPointI, const Matrix &mPlaneT, const Matrix &mPlaneI)
	{
		m_mPointT = mPointT;
		m_mPointI = mPointI;

		m_mPlaneT = mPlaneT;
		m_mPlaneI = mPlaneI;
	}

	public:
	Transform() {}

	const static Transform makeTranslate(const Vector3 &v)
	{
		Matrix mPointT = Matrix::makeTranslate(v);
		Matrix mPointI = mPointT.inverse();

		Matrix mPlaneT = mPointT.inverse().transpose();
		Matrix mPlaneI = mPointI.inverse().transpose();

		return Transform(mPointT, mPointI, mPlaneT, mPlaneI);
	}

	const static Transform makeScale(const Vector3 &v)
	{
		Matrix mPointT = Matrix::makeScale(v);
		Matrix mPointI = mPointT.inverse();

		Matrix mPlaneT = mPointT.inverse().transpose();
		Matrix mPlaneI = mPointI.inverse().transpose();

		return Transform(mPointT, mPointI, mPlaneT, mPlaneI);
	}

	const Transform inverse() const
	{
		return Transform(m_mPointI, m_mPointT, m_mPlaneI, m_mPlaneT);
	}

	Ray operator*(const Ray &rRay) const
	{
		Vector4 v4Origin(rRay.getOrigin());
		Vector4 v4Direction(rRay.getDirection(), 0.0f);

		v4Origin = m_mPointT * v4Origin;
		v4Direction = m_mPlaneT * v4Direction;

		Vector3 v3Origin(v4Origin(0),v4Origin(1),v4Origin(2));
		Vector3 v3Direction(v4Direction(0), v4Direction(1), v4Direction(2));

		return Ray(v3Origin, v3Direction.unit());
	}

	Intersect operator*(const Intersect &iIntersect) const
	{
		Vector4 v4Point(iIntersect.getPoint());
		Vector4 v4Normal(iIntersect.getNormal(), 0.0f);

		v4Point = m_mPointT * v4Point;
		v4Normal = m_mPlaneT * v4Normal;

		Vector3 v3Point(v4Point(0), v4Point(1), v4Point(2));
		Vector3 v3Normal(v4Normal(0), v4Normal(1), v4Normal(2));

		return Intersect(v3Point, v3Normal, iIntersect.getType());
	}
};

#endif
