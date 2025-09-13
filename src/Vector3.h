
#include <cmath>
#include <ostream>

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

class Vector3
{
	private:
	float m_x[3];

	public:
	Vector3()
	{
		Vector3 &v = *this;

		v(0) = 0;
		v(1) = 0;
		v(2) = 0;
	}

	Vector3(float x, float y, float z)
	{
		Vector3 &v = *this;

		v(0) = x;
		v(1) = y;
		v(2) = z;
	}

	float& operator() (unsigned int i)
	{
		return m_x[i];
	}

	float operator() (unsigned int i) const
	{
		return m_x[i];
	}

	const Vector3 unit() const
	{
		const Vector3 &v = *this;

		float len = length();

		return Vector3(v(0) / len, v(1) / len, v(2) / len);
	}

	const Vector3 cross(Vector3 u)
	{
		Vector3 &v = *this;

		return Vector3(v(1)*u(2)-v(2)*u(1),
		               v(2)*u(0)-v(0)*u(2),
		               v(0)*u(1)-v(1)*u(0));
	}

	float length2() const
	{
		const Vector3 &v = *this;

		return (v(0)*v(0) + v(1)*v(1) + v(2)*v(2));
	}

	float length() const
	{
		return (std::sqrt(length2()));
	}

	float dot(const Vector3 &u) const
	{
		const Vector3 &v = *this;

		return (v(0)*u(0) + v(1)*u(1) + v(2)*u(2));
	}

	Vector3& operator*=(float factor)
	{
		Vector3 &v = *this;
		v(0) *= factor;
		v(1) *= factor;
		v(2) *= factor;

		return *this;
	}

	const Vector3 operator*(float factor) const
	{
		return Vector3(*this) *= factor;
	}

	Vector3 operator+=(const Vector3 &u)
	{
		Vector3 &v = *this;
		v(0) += u(0);
		v(1) += u(1);
		v(2) += u(2);

		return *this;
	}

	const Vector3 operator+(const Vector3 &u) const
	{
		return Vector3(*this) += u;
	}

	const Vector3 operator-() const
	{
		const Vector3 &v = *this;

		return Vector3(-v(0), -v(1), -v(2));
	}

	Vector3& operator-= (const Vector3 &u)
	{
		Vector3 &v = *this;

		v(0) -= u(0);
		v(1) -= u(1);
		v(2) -= u(2);

		return *this;
	}

	const Vector3 operator-(const Vector3 &u) const
	{
		return Vector3(*this) -= u;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector3 &v);
};

std::ostream& operator<<(std::ostream& os, const Vector3 &v)
{
	os << "(" << v(0) << ", " << v(1) << ", " << v(2) << ")";

	return os;
}

#endif
