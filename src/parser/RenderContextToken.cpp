
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderContextToken.cpp                                  //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Render Context Token For Parsed Render     //
//          Contexts.                                               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "RenderContextToken.h"

//////////////////////////////////////////////////////////////////////

RenderContextToken::RenderContextToken()
{
	setType(T_RENDERCONTEXT);
}

//////////////////////////////////////////////////////////////////////

RenderContextToken::RenderContextToken(const RenderContextToken &t)
{
	setType(T_RENDERCONTEXT);
	setLineNumber(t.getLineNumber());
	m_rcContext = t.m_rcContext;
}

//////////////////////////////////////////////////////////////////////

bool RenderContextToken::setRenderContext(const RenderContext &rcContext)
{
	m_rcContext = rcContext;

	return true;
}

//////////////////////////////////////////////////////////////////////

const RenderContext& RenderContextToken::getRenderContext() const
{
	return m_rcContext;
}

//////////////////////////////////////////////////////////////////////
