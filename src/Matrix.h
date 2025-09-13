
#include "Vector3.h"
#include "Vector4.h"
#include <cmath>

#ifndef _MATRIX_H_
#define _MATRIX_H_

class Matrix
{
	private:
	float m_x[4][4];

	public:
	Matrix()
	{
		Matrix &m = *this;

		m(0,0) = 1; m(0,1) = 0; m(0,2) = 0; m(0,3) = 0;
		m(1,0) = 0; m(1,1) = 1; m(1,2) = 0; m(1,3) = 0;
		m(2,0) = 0; m(2,1) = 0; m(2,2) = 1; m(2,3) = 0;
		m(3,0) = 0; m(3,1) = 0; m(3,2) = 0; m(3,3) = 1;
	}

	Matrix(float *x)
	{
		Matrix &m = *this;

		m(0,0) = x[0];  m(0,1) = x[1];  m(0,2) = x[2];  m(0,3) = x[3];
		m(1,0) = x[4];  m(1,1) = x[5];  m(1,2) = x[6];  m(1,3) = x[7];
		m(2,0) = x[8];  m(2,1) = x[9];  m(2,2) = x[10]; m(2,3) = x[11];
		m(3,0) = x[12]; m(3,1) = x[13]; m(3,2) = x[14]; m(3,3) = x[15];
	}

	float& operator() (unsigned int row, unsigned int col)
	{
		return m_x[row][col];
	}

	float operator() (unsigned int row, unsigned int col) const
	{
		return m_x[row][col];
	}

	const static Matrix makeIdentity()
	{
		float m[16] = {1, 0, 0, 0,
		               0, 1, 0, 0,
		               0, 0, 1, 0,
		               0, 0, 0, 1};

		return Matrix(m);
	}

	const static Matrix makeTranslate(const Vector3 &v)
	{
		float m[16] = {1, 0, 0, v(0),
		               0, 1, 0, v(1),
		               0, 0, 1, v(2),
		               0, 0, 0, 1};

		return Matrix(m);
	}

	const static Matrix makeScale(const Vector3 &v)
	{
		float m[16] = {v(0), 0,    0,    0,
		               0,    v(1), 0,    0,
		               0,    0,    v(2), 0,
		               0,    0,    0,    1};

		return Matrix(m);
	}

	const static Matrix makeRotateX(float angle)
	{
		float s = sin(angle);
		float c = cos(angle);

		float m[16] = { 1, 0,  0, 0,
		                0, c, -s, 0,
		                0, s,  c, 0,
		                0, 0,  0, 1 };

		return Matrix(m);
	}

	const static Matrix makeRotateY(float angle)
	{
		float s = sin(angle);
		float c = cos(angle);

		float m[16] = {  c, 0, s, 0,
		                 0, 1, 0, 0,
		                -s, 0, c, 0,
		                 0, 0, 0, 1 };

		return Matrix(m);
	}

	const static Matrix makeRotateZ(float angle)
	{
		float s = sin(angle);
		float c = cos(angle);

		float m[16] = { c, -s, 0, 0,
		                s,  c, 0, 0,
		                0,  0, 1, 0,
		                0,  0, 0, 1 };

		return Matrix(m);
	}

	Vector4 operator*(const Vector4 &v) const
	{
		const Matrix &m = *this;

		float a = m(0,0)*v(0) + m(0,1)*v(1) + m(0,2)*v(2) + m(0,3)*v(3);
		float b = m(1,0)*v(0) + m(1,1)*v(1) + m(1,2)*v(2) + m(1,3)*v(3);
		float c = m(2,0)*v(0) + m(2,1)*v(1) + m(2,2)*v(2) + m(2,3)*v(3);
		float d = m(3,0)*v(0) + m(3,1)*v(1) + m(3,2)*v(2) + m(3,3)*v(3);

		return Vector4(a, b, c, d);
	}

	const Matrix adjugate() const
	{
		Matrix m;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				m(i, j) = cofactor(j, i);

		return Matrix(m);
	}

	float cofactor(int i, int j) const
	{
		float x[3][3];
		const Matrix &m = *this;

		int c = 0;
		for (int a = 0; a < 4; a++)
		{
			if (a == i)
				continue;

			int d = 0;
			for (int b = 0; b < 4; b++)
			{
				if (b == j)
					continue;

				x[c][d] = m(a, b);
				d++;
			}
			c++; // HA!
		}

		// Calculate Determinant
		float det = (x[0][0]*(x[1][1]*x[2][2]-x[1][2]*x[2][1]))+
					(x[0][1]*(x[1][2]*x[2][0]-x[1][0]*x[2][2]))+
					(x[0][2]*(x[1][0]*x[2][1]-x[1][1]*x[2][0]));

		return ((i + j) % 2 == 1) ? -det : det;
	}

	const Matrix transpose() const
	{
		const Matrix &m = *this;
		Matrix n;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				n(i, j) = m(j, i);

		return Matrix(n);
	}

	float determinant() const
	{
		const Matrix &m = *this;

		// Fuck yeah!!
		return
		 m(0, 0)*(+m(1, 1)*(m(2, 2)*m(3, 3)-m(2, 3)*m(3, 2))
		          -m(1, 2)*(m(2, 1)*m(3, 3)-m(2, 3)*m(3, 1))
		          +m(1, 3)*(m(2, 1)*m(3, 2)-m(2, 2)*m(3, 1)))
		-m(0, 1)*(+m(1, 0)*(m(2, 2)*m(3, 3)-m(2, 3)*m(3, 2))
		          -m(1, 2)*(m(2, 0)*m(3, 3)-m(2, 3)*m(3, 0))
		          +m(1, 3)*(m(2, 0)*m(3, 2)-m(2, 2)*m(3, 0)))
		+m(0, 2)*(+m(1, 0)*(m(2, 1)*m(3, 3)-m(2, 3)*m(3, 1))
		          -m(1, 1)*(m(2, 0)*m(3, 3)-m(2, 3)*m(3, 0))
		          +m(1, 3)*(m(2, 0)*m(3, 1)-m(2, 1)*m(3, 0)))
		-m(0, 3)*(+m(1, 0)*(m(2, 1)*m(3, 2)-m(2, 2)*m(3, 1))
		          -m(1, 1)*(m(2, 0)*m(3, 2)-m(2, 2)*m(3, 0))
		          +m(1, 2)*(m(2, 0)*m(3, 1)-m(2, 1)*m(3, 0)));
	}

	const Matrix inverse() const
	{
		return adjugate() / determinant();
	}

	Matrix& operator/=(float factor)
	{
		Matrix &m = *this;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				m(i, j) /= factor;

		return *this;
	}

	const Matrix operator/(float factor) const
	{
		return Matrix(*this) /= factor;
	}

	Matrix& operator*=(const Matrix &n)
	{
		Matrix &m = *this;
		Matrix x;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				x(i, j) = m(i, 0)*n(0, j)+m(i, 1)*n(1, j)+m(i, 2)*n(2, j)+m(i, 3)*n(3, j);

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				m(i, j) = x(i ,j);

		return *this;
	}

	const Matrix operator*(const Matrix &rhs) const
	{
		return Matrix(*this) *= rhs;
	}

	friend std::ostream& operator<< (std::ostream &o, const Matrix &m);
};

std::ostream& operator<< (std::ostream &o, const Matrix &m)
{
	       o << '{';
	       o << '{' << m(0, 0) << ',' << m(0, 1) << ',' << m(0, 2) << ',' << m(0, 3) << '}' << ',';
	       o << '{' << m(1, 0) << ',' << m(1, 1) << ',' << m(1, 2) << ',' << m(1, 3) << '}' << ',';
	       o << '{' << m(2, 0) << ',' << m(2, 1) << ',' << m(2, 2) << ',' << m(2, 3) << '}' << ',';
	return o << '{' << m(3, 0) << ',' << m(3, 1) << ',' << m(3, 2) << ',' << m(3, 3) << '}' << '}';
}

#endif
