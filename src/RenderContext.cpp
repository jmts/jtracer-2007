
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderContext.cpp                                       //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Data Structure To Encapsulate The Entire     //
//          Context Within Which An Image Should Be Rendered.       //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "RenderContext.h"

//////////////////////////////////////////////////////////////////////

RenderContext& RenderContext::operator=(const RenderContext& rc)
{
	if (&rc == this)
		return *this;

	m_rsRenderSettings = rc.m_rsRenderSettings;
	m_cCameras = rc.m_cCameras;
	m_sScene = rc.m_sScene;

	return *this;
}

//////////////////////////////////////////////////////////////////////

bool RenderContext::destroy()
{
	m_cCameras.destroy();

	m_sScene.destroy();

	return true;
}

//////////////////////////////////////////////////////////////////////

const RenderSettings& RenderContext::getRenderSettings() const
{
	return m_rsRenderSettings;
}

bool RenderContext::setRenderSettings(const RenderSettings& rsSettings)
{
	m_rsRenderSettings = rsSettings;
	return true;
}

//////////////////////////////////////////////////////////////////////

const CameraList& RenderContext::getCameraList() const
{
	return m_cCameras;
}

bool RenderContext::setCameraList(const CameraList &cCameras)
{
	m_cCameras = cCameras;
	return true;
}

//////////////////////////////////////////////////////////////////////

const Scene& RenderContext::getScene() const
{
	return m_sScene;
}

bool RenderContext::setScene(const Scene &sScene)
{
	m_sScene = sScene;
	return true;
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const RenderContext &rc)
{
	os << "Render Settings: " << rc.getRenderSettings() << std::endl;
	os << "Cameras: " << rc.getCameraList() << std::endl;
	os << "Scene: " << rc.getScene() << std::endl;

	return os;
}

//////////////////////////////////////////////////////////////////////
