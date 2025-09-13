
#ifndef _SURFACEWRITER_H_
#define _SURFACEWRITER_H_

#include "Surface.h"

class SurfaceWriter
{
	public:
	virtual bool write(const Surface *sSurface) = 0;
};

#endif
