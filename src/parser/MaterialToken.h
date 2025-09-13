
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    MaterialToken.h                                         //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Material Token For Parsed Material         //
//          Definitions.                                            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _MATERIALTOKEN_H_
#define _MATERIALTOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"
#include "..\Material.h"

//////////////////////////////////////////////////////////////////////

class MaterialToken : public Token
{
	private:
	Material m_mMaterial;

	public:
	MaterialToken();

	MaterialToken(const MaterialToken &t);

	~MaterialToken() { }

	bool setMaterial(const Material &mMaterial);

	const Material& getMaterial() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
