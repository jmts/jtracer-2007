
#include "Surface.h"
#include "RayTracer.h"
#include "Camera.h"
#include "RenderContext.h"
#include "Cameras.h"
#include "RenderSettings.h"
#include "Ray.h"
#include "Color.h"

#ifndef _RENDERER_H_
#define _RENDERER_H_

class Renderer
{
	private:
	Surface m_sSurface;
	RayTracer m_rtTracer;
	const Camera *m_cCamera;

	int m_nRecursions;

	public:
	Renderer()
	{
		m_cCamera = 0;
	}

	~Renderer() {}

	bool create(const RenderContext &rcContext)
	{
		Cameras cCameras = rcContext.getCameras();
		if (cCameras.getNumCameras() == 0)
			return false;

		RenderSettings rsSettings = rcContext.getRenderSettings();
		if (rsSettings.getActiveCamera())
			m_cCamera = cCameras.findCamera(rsSettings.getActiveCamera());

		if (!m_cCamera)
			m_cCamera = cCameras.getCamera(0);

		m_sSurface.create(rsSettings.getWidth(), rsSettings.getHeight());

		m_rtTracer.setScene(rcContext.getScene());
		m_rtTracer.setInfinityColor(rsSettings.getInfinityColor());

		return true;
	}

	bool destroy()
	{

	}

	bool renderPixel(int x, int y)
	{
		float nWidth = (float)m_sSurface.getWidth();
		float nHeight = (float)m_sSurface.getHeight();

		float dx = (float)x + 0.5f / nWidth;
		float dy = (float)y + 0.5f / nHeight;

		Ray rRay = m_cCamera->getRay(dx, dy);

		Color cColor = m_rtTracer.traceRay(rRay, m_nRecursions);

		m_sSurface.setPixel(x, y, cColor);

		return true;
	}

	bool renderScanline(int y)
	{
		int nWidth = m_sSurface.getWidth();

		for (int x = 0; x < nWidth; x++)
			renderPixel(x, y);

		return true;
	}

	bool render()
	{
		int nHeight = m_sSurface.getHeight();

		for (int y = 0; y < nHeight; y++)
			renderScanline(y);

		return true;
	}

	const Surface* getSurface()
	{
		return &m_sSurface;
	}
};

#endif
