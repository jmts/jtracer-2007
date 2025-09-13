
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CameraList.cpp                                          //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Container Class For Maintaining A List Of  //
//          Cameras.                                                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "CameraList.h"

//////////////////////////////////////////////////////////////////////

CameraList::CameraList()
{
	m_vCameras.clear();
}

//////////////////////////////////////////////////////////////////////

bool CameraList::destroy()
{
	for (unsigned int i = 0; i < m_vCameras.size(); i++)
		delete m_vCameras.at(i);

	return true;
}

//////////////////////////////////////////////////////////////////////

bool CameraList::addCamera(Camera *cCamera)
{
	if (!cCamera)
		return false;

	m_vCameras.push_back(cCamera);

	return true;
}

//////////////////////////////////////////////////////////////////////

int CameraList::getNumCameras() const
{
	return m_vCameras.size();
}

//////////////////////////////////////////////////////////////////////

Camera* CameraList::getCamera(int i) const
{
	return m_vCameras.at(i);
}

//////////////////////////////////////////////////////////////////////

Camera* CameraList::findCamera(const char *szCameraName) const
{
	if (!szCameraName || strlen(szCameraName) == 0)
		return 0;

	for (unsigned int i = 0; i < m_vCameras.size(); i++)
		if (strcmp(m_vCameras.at(i)->getName(), szCameraName) == 0)
			return m_vCameras.at(i);

	return 0;
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const CameraList &c)
{
	os << std::endl;
	os << "Cameras: " << c.getNumCameras() << std::endl;
	if (c.getNumCameras() > 0)
	{
		const Camera* cCamera = c.getCamera(0);
		os << cCamera->getName() << std::endl;
	}

	return os;
}

//////////////////////////////////////////////////////////////////////
