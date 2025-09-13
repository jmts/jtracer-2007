
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    MaterialParser.h                                        //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Material Definitions.           //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _MATERIALPARSER_H_
#define _MATERIALPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "MaterialToken.h"

//////////////////////////////////////////////////////////////////////

class MaterialParser : public Parser
{
	private:
	Material m_mMaterial;

	MaterialToken m_mToken;

	typedef enum { MP_ANY, MP_PIGMENT, MP_AMBIENT, MP_DIFFUSE,
		MP_DIFFUSEK, MP_SPECULAR, MP_SPECULARK, MP_REFLECTION}
		MProperty;

	MProperty m_mpCurrent;

	public:
	MaterialParser();

	~MaterialParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
