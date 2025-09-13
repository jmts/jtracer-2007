
#ifndef _FILESURFACEWRITER_H_
#define _FILESURFACEWRITER_H_

#include "SurfaceWriter.h"

class FileSurfaceWriter : public SurfaceWriter
{
	public:
	virtual bool open(const char *szFileName) = 0;
	virtual bool write(const Surface *sSurface, const char *szFileName) = 0;
	virtual bool close() = 0;
};

#endif
