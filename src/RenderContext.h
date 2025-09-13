
#include "Scene.h"
#include "Cameras.h"
#include "RenderSettings.h"

#ifndef _RENDERCONTEXT_H_
#define _RENDERCONTEXT_H_

class RenderContext
{
	private:
	RenderSettings m_rsRenderSettings;
	Cameras m_cCameras;
	Scene m_sScene;

	public:
	RenderContext()
	{

	}

	RenderContext(const RenderSettings &rsRenderSettings, const Cameras &cCameras, const Scene &sScene) :
		m_rsRenderSettings(rsRenderSettings), m_cCameras(cCameras), m_sScene(sScene) {}

	~RenderContext()
	{
		
	}

	bool destroy()
	{
		m_cCameras.destroy();
		m_sScene.destroy();
	}

	RenderSettings getRenderSettings() const
	{
		return m_rsRenderSettings;
	}

	Cameras getCameras() const
	{
		return m_cCameras;
	}

	Scene getScene() const
	{
		return m_sScene;
	}
};

#endif
