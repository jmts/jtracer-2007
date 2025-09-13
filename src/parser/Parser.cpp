
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Parser.cpp                                              //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Generalised Parser Interface.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Parser.h"

//////////////////////////////////////////////////////////////////////

Parser::Parser()
{
	m_tExpecting = T_ANY;
}

//////////////////////////////////////////////////////////////////////

bool Parser::setExpecting(TokenType tExpecting)
{
	m_tExpecting = tExpecting;

	return true;
}

//////////////////////////////////////////////////////////////////////

TokenType Parser::getExpecting() const
{
	return m_tExpecting;
}

//////////////////////////////////////////////////////////////////////
