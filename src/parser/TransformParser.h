
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    TransformParser.h                                       //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Geometric Transformations.      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _TRANSFORMPARSER_H_
#define _TRANSFORMPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "TransformToken.h"

//////////////////////////////////////////////////////////////////////

class TransformParser : public Parser
{
	private:
	Transform m_tTransform;

	TransformToken m_tToken;

	typedef enum { TP_ANY, TP_SCALE, TP_TRANSLATE, TP_XROTATE, TP_YROTATE, TP_ZROTATE }
		TProperty;

	TProperty m_pCurrent;

	public:
	TransformParser();

	~TransformParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
