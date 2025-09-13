
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Material.cpp                                            //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Encapsulates Information Required To Describe The       //
//          Material A Primitive Is Made Up Of.                     //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Material.h"

//////////////////////////////////////////////////////////////////////

Material::Material()
{
	m_fDiffuse = 1.0f;
	m_fSpecular = 64.0f;
	m_fReflection = 0.0f;
}

//////////////////////////////////////////////////////////////////////

Material::Material(const Color &cPigment, const Color& cAmbient, const Color &cDiffuse, const Color &cSpecular)
{
	m_cPigment = cPigment;
	m_cAmbient = cAmbient;
	m_cDiffuse = cDiffuse;
	m_cSpecular = cSpecular;

	m_fDiffuse = 1.0f;
	m_fSpecular = 64.0f;
}

//////////////////////////////////////////////////////////////////////

Material::Material(const Color &cPigment, const Color& cAmbient, const Color &cDiffuse, float kDiffuse, const Color &cSpecular, float kSpecular)
{
	m_cPigment = cPigment;
	m_cAmbient = cAmbient;
	m_cDiffuse = cDiffuse;
	m_cSpecular = cSpecular;

	m_fDiffuse = kDiffuse;
	m_fSpecular = kSpecular;
}

//////////////////////////////////////////////////////////////////////

bool Material::setPigment(const Color &cPigment)
{
	m_cPigment = cPigment;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Color& Material::getPigment() const
{
	return m_cPigment;
}

//////////////////////////////////////////////////////////////////////

bool Material::setAmbientColor(const Color &cAmbient)
{
	m_cAmbient = cAmbient;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Color& Material::getAmbientColor() const
{
	return m_cAmbient;
}

//////////////////////////////////////////////////////////////////////

bool Material::setDiffuseK(float kDiffuse)
{
	if (kDiffuse <= 0)
		return false;

	m_fDiffuse = kDiffuse;

	return true;
}

//////////////////////////////////////////////////////////////////////

float Material::getDiffuseK() const
{
	return m_fDiffuse;
}

//////////////////////////////////////////////////////////////////////

bool Material::setDiffuseColor(const Color &cDiffuse)
{
	m_cDiffuse = cDiffuse;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Color& Material::getDiffuseColor() const
{
	return m_cDiffuse;
}

//////////////////////////////////////////////////////////////////////

bool Material::setSpecularK(float kSpecular)
{
	if (kSpecular <= 0)
		return false;

	m_fSpecular = kSpecular;

	return true;
}

//////////////////////////////////////////////////////////////////////

float Material::getSpecularK() const
{
	return m_fSpecular;
}

//////////////////////////////////////////////////////////////////////

bool Material::setSpecularColor(const Color &cSpecular)
{
	m_cSpecular = cSpecular;

	return true;
}

//////////////////////////////////////////////////////////////////////

const Color& Material::getSpecularColor() const
{
	return m_cSpecular;
}

//////////////////////////////////////////////////////////////////////

bool Material::setReflectionK(float kReflection)
{
	if (kReflection < 0.0 && kReflection > 1.0)
		return false;

	m_fReflection = kReflection;
	return true;
}

//////////////////////////////////////////////////////////////////////

float Material::getReflectionK() const
{
	return m_fReflection;
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Material &m)
{
	os << "Pigment: " << m.getPigment() << std::endl;
	os << "Ambient: " << m.getAmbientColor() << std::endl;
	os << "Diffuse: " << m.getDiffuseColor() << std::endl;
	os << "Diffuse K: " << m.getDiffuseK() << std::endl;
	os << "Specular: " << m.getSpecularColor() << std::endl;
	os << "Specular K: " << m.getSpecularK() << std::endl;

	return os;
}

//////////////////////////////////////////////////////////////////////
