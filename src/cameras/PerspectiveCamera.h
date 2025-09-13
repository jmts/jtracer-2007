
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PerspectiveCamera.h                                     //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Perspective Camera Viewpoint, Providing    //
//          Realistic Perspective Projections.                      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _PERSPECTIVECAMERA_H_
#define _PERSPECTIVECAMERA_H_

//////////////////////////////////////////////////////////////////////

#include "..\Camera.h"
#include "..\Vector3.h"

//////////////////////////////////////////////////////////////////////

class PerspectiveCamera : public Camera
{
	private:
	Vector3 m_vPosition;
	Vector3 m_vLookAt;
	Vector3 m_vUp;
	float   m_fFieldOfView;
	float   m_fAspect;

	Vector3 m_vLook;
	Vector3 m_vLeft;

	bool m_bInitialised;

	public:
	PerspectiveCamera();
	PerspectiveCamera(const char *szName, const Vector3 &vPosition, const Vector3 &vLookAt, const Vector3 &vUp, float fFieldOfView, float fAspect);
	PerspectiveCamera(const PerspectiveCamera& c);

	bool setPosition(const Vector3 &vPosition);
	const Vector3& getPosition() const;

	bool setLookAt(const Vector3 &vLookAt);
	const Vector3& getLookAt() const;

	bool setUp(const Vector3 &vUp);
	const Vector3& getUp() const;

	bool setFieldOfView(float fFieldOfView);
	float getFieldOfView() const;

	bool setAspect(float fAspect);
	float getAspect() const;

	bool init();

	Ray getRay(float x, float y) const;

	friend std::ostream& operator<<(std::ostream& os, const PerspectiveCamera &c);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
