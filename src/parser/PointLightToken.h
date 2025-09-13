
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PointLightToken.h                                       //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Point Light Token For Parsed Point Lights. //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _POINTLIGHTTOKEN_H_
#define _POINTLIGHTTOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"
#include "..\lights\PointLight.h"

//////////////////////////////////////////////////////////////////////

class PointLightToken : public Token
{
	private:
	PointLight m_lPointLight;

	public:
	PointLightToken();

	PointLightToken(const PointLightToken &t);

	~PointLightToken() { }

	bool setPointLight(const PointLight &lPointLight);

	const PointLight& getPointLight() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
