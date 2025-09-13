
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PrintingParser.h                                        //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser That Outputs Input Tokens To STDOUT //
//          For Debugging Purposes.                                 //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _PRINTINGPARSER_H_
#define _PRINTINGPARSER_H_

//////////////////////////////////////////////////////////////////////

#include "Parser.h"

//////////////////////////////////////////////////////////////////////

class PrintingParser : public Parser
{
	public:
	PrintingParser() { }

	ParseResult handleToken(const Token *tToken);

	const Token* getToken();

	bool setTokenLineNumber(int iLineNumber);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
