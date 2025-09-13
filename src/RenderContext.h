
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderContext.h                                         //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Data Structure To Encapsulate The Entire     //
//          Context Within Which An Image Should Be Rendered.       //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RENDERCONTEXT_H_
#define _RENDERCONTEXT_H_

//////////////////////////////////////////////////////////////////////

#include "Scene.h"
#include "CameraList.h"
#include "RenderSettings.h"

#include <ostream>

//////////////////////////////////////////////////////////////////////

class RenderContext
{
	private:
	RenderSettings m_rsRenderSettings;
	CameraList m_cCameras;
	Scene m_sScene;

	public:
	RenderContext() { }
	RenderContext(const RenderSettings &rsRenderSettings, const CameraList &cCameras, const Scene &sScene) :
		m_rsRenderSettings(rsRenderSettings), m_cCameras(cCameras), m_sScene(sScene) {}

	RenderContext& operator=(const RenderContext& rc);

	~RenderContext() { }

	bool destroy();

	const RenderSettings& getRenderSettings() const;
	bool setRenderSettings(const RenderSettings& rsSettings);

	const CameraList& getCameraList() const;
	bool setCameraList(const CameraList &cCameras);

	const Scene& getScene() const;
	bool setScene(const Scene &sScene);

	friend std::ostream& operator<<(std::ostream& os, const RenderContext &rc);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
