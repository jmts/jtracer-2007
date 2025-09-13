
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    CameraList.h                                            //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Container Class For Maintaining A List Of  //
//          Cameras.                                                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _CAMERALIST_H_
#define _CAMERALIST_H_

//////////////////////////////////////////////////////////////////////

#include "Camera.h"

#include <vector>

//////////////////////////////////////////////////////////////////////

class CameraList
{
	private:
	std::vector<Camera*> m_vCameras;

	public:
	CameraList();

	CameraList(const CameraList &c) : m_vCameras(c.m_vCameras) { }

	~CameraList() { }

	bool destroy();

	bool addCamera(Camera *cCamera);
	int  getNumCameras() const;
	Camera* getCamera(int i) const;
	Camera* findCamera(const char *szCameraName) const;

	friend std::ostream& operator<<(std::ostream& os, const CameraList &c);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
