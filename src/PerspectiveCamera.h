
#include "Camera.h"
#include "Vector3.h"
#include <cmath>

#ifndef _PERSPECTIVECAMERA_H_
#define _PERSPECTIVECAMERA_H_

class PerspectiveCamera : public Camera
{
	private:
	Vector3 m_vPosition;

	Vector3 m_vLook;
	Vector3 m_vUp;
	Vector3 m_vRight;

	public:
	PerspectiveCamera()
	{
		m_vPosition = Vector3(0.0f, 0.0f, 0.0f);

		m_vLook  = Vector3(0.0f, 0.0f, 1.0f);
		m_vRight = Vector3(1.0f, 0.0f, 0.0f);
		m_vUp    = Vector3(0.0f, 1.0f, 0.0f);

		float k = std::tan(M_PI/8.0f);

		m_vUp = m_vUp * k;
		m_vRight = m_vRight * k;
	}

	PerspectiveCamera(const char *szName,
	                  const Vector3 &vPosition, const Vector3 &vLookAt, const Vector3 &vUp,
	                  float fFOVy, float fAspect)
	{
		setName(szName);

		m_vPosition = vPosition;

		m_vLook  = (vLookAt - vPosition);
		m_vUp    = vUp;
		m_vRight = m_vUp.cross(m_vLook);
		m_vUp    = m_vLook.cross(m_vRight);

		m_vLook = m_vLook.unit();
		m_vRight = m_vRight.unit();
		m_vUp = m_vUp.unit();

		float k = std::tan((fFOVy / 2.0f));

		m_vUp = m_vUp * k;
		m_vRight = m_vRight * fAspect * k;
	}

	Ray getRay(float x, float y) const
	{
		float dx = (2.0f * x) - 1.0f;
		float dy = (2.0f * y) - 1.0f;

		return Ray(m_vPosition, (m_vLook + (m_vRight * dx) + (m_vUp * dy)));
	}
};

#endif
