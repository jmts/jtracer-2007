
#include "Ray.h"
#include <cstring>

#ifndef _CAMERA_H_
#define _CAMERA_H_

class Camera
{
	private:
	char *m_szName;

	public:
	Camera()
	{
		m_szName = 0;
	}

	virtual ~Camera()
	{
		if (m_szName)
			delete [] m_szName;
	}

	virtual Ray getRay(float x, float y) const = 0;

	const char * getName() const
	{
		return m_szName;
	}

	bool setName(const char *szName)
	{
		if (!szName || strlen(szName) == 0)
			return false;

		if (m_szName)
			delete [] m_szName;

		int iLength = strlen(szName);
		m_szName = new char[iLength+1];
		strcpy(m_szName, szName);
		
		return true;
	}
};

#endif
