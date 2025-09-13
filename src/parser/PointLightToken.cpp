
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PointLightToken.cpp                                     //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Point Light Token For Parsed Point Lights. //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "PointLightToken.h"

//////////////////////////////////////////////////////////////////////

PointLightToken::PointLightToken()
{
	setType(T_POINTLIGHT);
}

//////////////////////////////////////////////////////////////////////

PointLightToken::PointLightToken(const PointLightToken &t)
{
	setType(T_POINTLIGHT);
	setLineNumber(t.getLineNumber());
	m_lPointLight = t.getPointLight();
}

//////////////////////////////////////////////////////////////////////

bool PointLightToken::setPointLight(const PointLight &lPointLight)
{
	m_lPointLight = lPointLight;

	return true;
}

//////////////////////////////////////////////////////////////////////

const PointLight& PointLightToken::getPointLight() const
{
	return m_lPointLight;
}

//////////////////////////////////////////////////////////////////////
