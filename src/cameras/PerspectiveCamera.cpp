
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PerspectiveCamera.cpp                                   //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Perspective Camera Viewpoint, Providing    //
//          Realistic Perspective Projections.                      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "PerspectiveCamera.h"

#include <cmath>

//////////////////////////////////////////////////////////////////////

PerspectiveCamera::PerspectiveCamera()
{
	setPosition(Vector3(0.0f, 0.0f, 0.0f));
	setLookAt(Vector3(0.0f, 0.0f, 1.0f));
	setUp(Vector3(0.0f, 1.0f, 0.0f));
	setFieldOfView(45.0f);
	setAspect(1.0f);

	m_bInitialised = false;
}

//////////////////////////////////////////////////////////////////////

PerspectiveCamera::PerspectiveCamera(const char *szName, const Vector3 &vPosition, const Vector3 &vLookAt, const Vector3 &vUp, float fFieldOfView, float fAspect)
{
	setName(szName);
	setPosition(vPosition);
	setLookAt(vLookAt);
	setUp(vUp);
	setFieldOfView(fFieldOfView);
	setAspect(fAspect);

	m_bInitialised = false;
}

//////////////////////////////////////////////////////////////////////

PerspectiveCamera::PerspectiveCamera(const PerspectiveCamera& c)
{
	setName(c.getName());
	setPosition(c.getPosition());
	setLookAt(c.getLookAt());
	setUp(c.getUp());
	setFieldOfView(c.getFieldOfView());
	setAspect(c.getAspect());
}

//////////////////////////////////////////////////////////////////////

bool PerspectiveCamera::setPosition(const Vector3 &vPosition)
{
	m_vPosition = vPosition;

	return true;
}

const Vector3& PerspectiveCamera::getPosition() const
{
	return m_vPosition;
}

//////////////////////////////////////////////////////////////////////

bool PerspectiveCamera::setLookAt(const Vector3 &vLookAt)
{
	m_vLookAt = vLookAt;

	return true;
}

const Vector3& PerspectiveCamera::getLookAt() const
{
	return m_vLookAt;
}

//////////////////////////////////////////////////////////////////////

bool PerspectiveCamera::setUp(const Vector3 &vUp)
{
	m_vUp = vUp;

	return true;
}

const Vector3& PerspectiveCamera::getUp() const
{
	return m_vUp;
}

//////////////////////////////////////////////////////////////////////

bool PerspectiveCamera::setFieldOfView(float fFieldOfView)
{
	m_fFieldOfView = fFieldOfView;

	return true;
}

float PerspectiveCamera::getFieldOfView() const
{
	return m_fFieldOfView;
}

//////////////////////////////////////////////////////////////////////

bool PerspectiveCamera::setAspect(float fAspect)
{
	m_fAspect = fAspect;

	return true;
}

float PerspectiveCamera::getAspect() const
{
	return m_fAspect;
}

//////////////////////////////////////////////////////////////////////

bool PerspectiveCamera::init()
{
	m_vLook = m_vLookAt - m_vPosition;
	m_vLeft = m_vUp.cross(m_vLook);
	m_vUp   = m_vLook.cross(m_vLeft);

	m_vLook = m_vLook.unit();
	m_vUp   = m_vUp.unit();
	m_vLeft = m_vLeft.unit();

	float k = std::tan((m_fFieldOfView/2.0f) * (M_PI/180.0f));

	m_vUp   = m_vUp   * k;
	m_vLeft = m_vLeft * k * m_fAspect;

	m_bInitialised = true;

	return true;
}

//////////////////////////////////////////////////////////////////////

Ray PerspectiveCamera::getRay(float x, float y) const
{
	float dx = (2.0f * x) - 1.0f;
	float dy = (2.0f * y) - 1.0f;

	Vector3 vDirection = (m_vLook - (m_vLeft * dx) + (m_vUp * dy));
	return Ray(m_vPosition, vDirection.unit());
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const PerspectiveCamera &c)
{
	os << "Name: ";
	if (c.getName())
		os << c.getName() << std::endl;
	else
		os << "None" << std::endl;

	os << "Position: " << c.getPosition() << std::endl;
	os << "Look At: " << c.getLookAt() << std::endl;
	os << "Up: " << c.getUp() << std::endl;
	os << "Field Of View: " << c.getFieldOfView() << std::endl;
	os << "Aspect: " << c.getAspect() << std::endl;

	return os;
}

//////////////////////////////////////////////////////////////////////
