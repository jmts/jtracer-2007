
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Renderer.cpp                                            //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Class To Control The Rendering Procedure.  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Renderer.h"

#include "CameraList.h"
#include "RenderSettings.h"
#include "Ray.h"
#include "Color.h"

//////////////////////////////////////////////////////////////////////

Renderer::Renderer()
{
	m_cCamera = 0;

	m_nRecursions = 0;

	m_reCurrent = RE_NONE;
}

//////////////////////////////////////////////////////////////////////
// create - Initialise The Renderer And Ray Tracer Systems ///////////
//////////////////////////////////////////////////////////////////////

bool Renderer::create(const RenderContext &rcContext)
{
	// Ensure There Are Viewpoints
	CameraList cCameras = rcContext.getCameraList();
	if (cCameras.getNumCameras() == 0)
	{
		m_reCurrent = RE_CAMERAS;
		return false;
	}

	// Find A Camera To Render From
	RenderSettings rsSettings = rcContext.getRenderSettings();
	if (rsSettings.getActiveCamera())
		m_cCamera = cCameras.findCamera(rsSettings.getActiveCamera());

	if (!m_cCamera)
		m_cCamera = cCameras.getCamera(0);

	m_cCamera->init();

	// Set The Recurse Depth
	m_nRecursions = rsSettings.getRecursions();

	// Check There Are Primitives To Render
	Scene sScene = rcContext.getScene();
	if (sScene.getNumPrimitives() == 0)
	{
		m_reCurrent = RE_PRIMITIVES;
		return false;
	}
	m_rtTracer.setScene(rcContext.getScene());

	// Create A Surface To Render To
	m_sSurface.create(rsSettings.getWidth(), rsSettings.getHeight());

	// Set Ray Tracer Colours
	m_rtTracer.setAmbientLight(rsSettings.getAmbientLight());
	m_rtTracer.setInfinityColor(rsSettings.getInfinityColor());

	// Initialise Render Stats
	m_rsStats.zeroStats();
	m_rsStats.setPrimitives(rcContext.getScene().getNumPrimitives());
	m_rsStats.setLights(rcContext.getScene().getNumLights());

	return true;
}

//////////////////////////////////////////////////////////////////////

bool Renderer::destroy()
{
	return true;
}

//////////////////////////////////////////////////////////////////////

const char* Renderer::getErrorString() const
{
	switch(m_reCurrent)
	{
		case RE_NONE: return "No Error";
		case RE_CAMERAS: return "No Cameras Defined";
		case RE_LIGHTS: return "No Lighting Defined";
		case RE_PRIMITIVES: return "No Primitives Defined";
	}
	return "Unknown Error";
}

//////////////////////////////////////////////////////////////////////
// render - Render A Whole Image /////////////////////////////////////
//////////////////////////////////////////////////////////////////////

bool Renderer::render()
{
	m_rsStats.captureStartTime();

	int nHeight = m_sSurface.getHeight();

	for (int y = 0; y < nHeight; y++)
		renderScanline(y);

	m_rsStats.captureEndTime();

	return true;
}

//////////////////////////////////////////////////////////////////////
// renderScanline - Render An Entire Row In The Image ////////////////
//////////////////////////////////////////////////////////////////////

bool Renderer::renderScanline(int y)
{
	int nWidth = m_sSurface.getWidth();

	for (int x = 0; x < nWidth; x++)
		renderPixel(x, y);

	return true;
}

//////////////////////////////////////////////////////////////////////
// renderPixel - Trace And Render A Pixel In The Image ///////////////
//////////////////////////////////////////////////////////////////////

bool Renderer::renderPixel(int x, int y)
{
	float nWidth = (float)m_sSurface.getWidth();
	float nHeight = (float)m_sSurface.getHeight();

	// Calculate Pixel Centre
	float dx = ((float)x + 0.5f) / nWidth;
	float dy = ((float)y + 0.5f) / nHeight;

	// Trace The Pixel Ray (Primary Ray)
	Ray rRay = m_cCamera->getRay(dx, dy);
	Color cColor = m_rtTracer.traceRay(rRay, m_nRecursions);

	// Set The Pixel
	m_sSurface.setPixel(x, y, cColor);

	// Update Statistics
	m_rsStats.incPixels();
	m_rsStats.addTraceStats(m_rtTracer.getStats());

	return true;
}

//////////////////////////////////////////////////////////////////////

const Surface* Renderer::getSurface()
{
	return &m_sSurface;
}

//////////////////////////////////////////////////////////////////////

const RenderStats& Renderer::getStats() const
{
	return m_rsStats;
}

//////////////////////////////////////////////////////////////////////
