
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Renderer.h                                              //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Class To Control The Rendering Procedure.  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RENDERER_H_
#define _RENDERER_H_

//////////////////////////////////////////////////////////////////////

#include "Surface.h"
#include "RayTracer.h"
#include "Camera.h"
#include "RenderStats.h"
#include "RenderContext.h"

//////////////////////////////////////////////////////////////////////

class Renderer
{
	private:
	Surface m_sSurface;
	RayTracer m_rtTracer;
	Camera *m_cCamera;

	RenderStats m_rsStats;

	int m_nRecursions;

	typedef enum { RE_NONE, RE_CAMERAS, RE_LIGHTS, RE_PRIMITIVES } RenderError;

	RenderError m_reCurrent;

	public:
	Renderer();
	~Renderer() {}

	bool create(const RenderContext &rcContext);
	bool destroy();

	const char* getErrorString() const;

	bool render();
	bool renderScanline(int y);
	bool renderPixel(int x, int y);

	const Surface* getSurface();

	const RenderStats& getStats() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
