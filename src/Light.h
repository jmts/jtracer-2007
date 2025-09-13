
#include "Vector3.h"

#ifndef _LIGHT_H_
#define _LIGHT_H_

class Light
{
	public:
	virtual bool isVisible(Vector3 vPoint) const = 0;
};

#endif
