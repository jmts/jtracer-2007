
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Token.h                                                 //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Generalised Token Interface For Lexer And    //
//          Parser Implementations.                                 //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _TOKEN_H_
#define _TOKEN_H_

//////////////////////////////////////////////////////////////////////

#include <cstring>

//////////////////////////////////////////////////////////////////////

typedef enum {T_ANY,
              T_EMPTY,
              T_IDENTIFIER,
              T_NUMBER,
              T_STRING,
              T_OPENBRACE,
              T_CLOSEBRACE,
              T_OPENVECTOR,
              T_CLOSEVECTOR,
              T_SEPARATOR,
              T_ASSIGNMENT,
              T_ENDSTATEMENT,
              T_EOF,
              T_ERROR,
			  T_VECTOR,
			  T_RENDERSETTINGS,
              T_PERSPECTIVECAMERA,
			  T_CAMERALIST,
              T_MATERIAL,
			  T_SPHERE,
			  T_POINTLIGHT,
			  T_SCENE,
			  T_RENDERCONTEXT,
			  T_PLANE,
			  T_CYLINDER,
			  T_TRANSFORM } TokenType;

//////////////////////////////////////////////////////////////////////

class Token
{
	private:
	TokenType   m_ttType;
	char* m_szString;

	int m_iLineNumber;

	public:
	Token();
	Token(const Token &t);

	virtual ~Token();

	bool setType(TokenType ttType);
	TokenType getType() const;

	bool setString(const char* szString);
	const char* getString() const;

	bool setLineNumber(int iLineNumber);
	int getLineNumber() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
