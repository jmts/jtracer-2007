
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Matrix.h                                                //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Encapsulates Common Matrix Operations.                  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _MATRIX_H_
#define _MATRIX_H_

//////////////////////////////////////////////////////////////////////

#include "Vector3.h"
#include "Vector4.h"

#include <ostream>

//////////////////////////////////////////////////////////////////////

class Matrix
{
	private:
	float m_x[4][4];

	public:
	Matrix();
	Matrix(float *x);

	float& operator() (unsigned int row, unsigned int col);
	float operator() (unsigned int row, unsigned int col) const;

	const static Matrix makeIdentity();
	const static Matrix makeTranslate(const Vector3 &v);
	const static Matrix makeScale(const Vector3 &v);
	const static Matrix makeRotateX(float angle);
	const static Matrix makeRotateY(float angle);
	const static Matrix makeRotateZ(float angle);

	const Matrix adjugate() const;
	float cofactor(int i, int j) const;
	const Matrix transpose() const;
	float determinant() const;
	const Matrix inverse() const;

	Matrix& operator/=(float factor);
	const Matrix operator/(float factor) const;

	Matrix& operator*=(const Matrix &n);
	const Matrix operator*(const Matrix &rhs) const;

	Vector4 operator*(const Vector4 &v) const;

	friend std::ostream& operator<< (std::ostream &o, const Matrix &m);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
