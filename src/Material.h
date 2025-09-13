
#include "Color.h"

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

class Material
{
	private:
	Color m_cPigment;

	Color m_cAmbient;
	
	Color m_cDiffuse;
	float m_fDiffuse;
	
	Color m_cSpecular;
	float m_fSpecular;

	public:
	Material()
	{
		m_fDiffuse = 0.0f;
		m_fSpecular = 0.0f;
	}

	Material(const Color &cPigment, const Color& cAmbient, const Color &cDiffuse, const Color &cSpecular)
	{
		m_cPigment = cPigment;
		m_cAmbient = cAmbient;
		m_cDiffuse = cDiffuse;
		m_cSpecular = cSpecular;

		m_fDiffuse = 1.0f;
		m_fSpecular = 1.0f;
	}

	Material(const Color &cPigment, const Color& cAmbient, const Color &cDiffuse, float kDiffuse, const Color &cSpecular, float kSpecular)
	{
		m_cPigment = cPigment;
		m_cAmbient = cAmbient;
		m_cDiffuse = cDiffuse;
		m_cSpecular = cSpecular;

		m_fDiffuse = kDiffuse;
		m_fSpecular = kSpecular;
	}

	bool setPigment(const Color &cPigment)
	{
		m_cPigment = cPigment;

		return true;
	}

	Color getPigment() const
	{
		return m_cPigment;
	}

	bool setAmbientColor(const Color &cAmbient)
	{
		m_cAmbient = cAmbient;

		return true;
	}

	Color getAmbientColor() const
	{
		return m_cAmbient;
	}

	bool setDiffuseK(float kDiffuse)
	{
		m_fDiffuse = kDiffuse;

		return true;
	}

	float getDiffuseK() const
	{
		return m_fDiffuse;
	}

	bool setDiffuseColor(const Color &cDiffuse)
	{
		m_cDiffuse = cDiffuse;

		return true;
	}

	Color getDiffuseColor() const
	{
		return m_cDiffuse;
	}

	bool setSpecularK(float kSpecular)
	{
		m_fSpecular = kSpecular;

		return true;
	}

	float getSpecularK() const
	{
		return m_fSpecular;
	}

	bool setSpecularColor(const Color &cSpecular)
	{
		m_cSpecular = cSpecular;

		return true;
	}

	Color getSpecularColor() const
	{
		return m_cSpecular;
	}
};

#endif
