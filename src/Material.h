
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Material.h                                              //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Encapsulates Information Required To Describe The       //
//          Material A Primitive Is Made Up Of.                     //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

//////////////////////////////////////////////////////////////////////

#include "Color.h"
#include <ostream>

//////////////////////////////////////////////////////////////////////

class Material
{
	private:
	Color m_cPigment;

	Color m_cAmbient;

	Color m_cDiffuse;
	float m_fDiffuse;

	Color m_cSpecular;
	float m_fSpecular;

	float m_fReflection;

	//bool m_bMetallic;

	public:
	Material();
	Material(const Color &cPigment, const Color& cAmbient, const Color &cDiffuse, const Color &cSpecular);
	Material(const Color &cPigment, const Color& cAmbient, const Color &cDiffuse, float kDiffuse, const Color &cSpecular, float kSpecular);

	bool setPigment(const Color &cPigment);
	const Color& getPigment() const;

	bool setAmbientColor(const Color &cAmbient);
	const Color& getAmbientColor() const;

	bool setDiffuseK(float kDiffuse);
	float getDiffuseK() const;

	bool setDiffuseColor(const Color &cDiffuse);
	const Color& getDiffuseColor() const;

	bool setSpecularK(float kSpecular);
	float getSpecularK() const;

	bool setSpecularColor(const Color &cSpecular);
	const Color& getSpecularColor() const;

	bool setReflectionK(float kReflection);
	float getReflectionK() const;

	friend std::ostream& operator<<(std::ostream& os, const Material &m);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
