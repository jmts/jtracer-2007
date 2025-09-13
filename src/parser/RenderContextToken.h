
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderContextToken.h                                    //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Render Context Token For Parsed Render     //
//          Contexts.                                               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RENDERCONTEXTTOKEN_H_
#define _RENDERCONTEXTTOKEN_H_

//////////////////////////////////////////////////////////////////////

#include "Token.h"
#include "..\RenderContext.h"

//////////////////////////////////////////////////////////////////////

class RenderContextToken : public Token
{
	private:
	RenderContext m_rcContext;

	public:
	RenderContextToken();

	RenderContextToken(const RenderContextToken &t);

	~RenderContextToken() { }

	bool setRenderContext(const RenderContext &rcContext);

	const RenderContext& getRenderContext() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
