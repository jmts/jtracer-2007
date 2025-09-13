
#include "Camera.h"
#include <vector>

#ifndef _CAMERAS_H_
#define _CAMERAS_H_

class Cameras
{
	private:
	std::vector<Camera*> m_vCameras;

	public:
	Cameras()
	{
		m_vCameras.clear();
	}

	Cameras(const Cameras &c) : m_vCameras(c.m_vCameras) { }

	~Cameras()
	{

	}

	bool destroy()
	{
		for (unsigned int i = 0; i < m_vCameras.size(); i++)
			delete m_vCameras.at(i);

		return true;
	}

	bool addCamera(Camera *cCamera)
	{
		if (!cCamera)
			return false;

		m_vCameras.push_back(cCamera);

		return true;
	}

	int getNumCameras() const
	{
		return m_vCameras.size();
	}

	const Camera* findCamera(const char *szCameraName) const
	{
		if (!szCameraName || strlen(szCameraName) == 0)
			return 0;

		for (unsigned int i = 0; i < m_vCameras.size(); i++)
			if (strcmp(m_vCameras.at(i)->getName(), szCameraName) == 0)
				return m_vCameras.at(i);

		return 0;
	}

	const Camera* getCamera(int i)
	{
		return m_vCameras.at(i);
	}
};

#endif
