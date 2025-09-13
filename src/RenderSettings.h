
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderSettings.h                                        //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides A Data Structure For Handling Rendering        //
//          Properties.                                             //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RENDERSETTINGS_H_
#define _RENDERSETTINGS_H_

//////////////////////////////////////////////////////////////////////

#include "Color.h"

#include <ostream>

//////////////////////////////////////////////////////////////////////

class RenderSettings
{
	private:
	int m_nWidth;			// Canvas Dimensions
	int m_nHeight;

	int m_nRecursions;		// Recurse Depth

	char *m_szActiveCamera;	// Render Viewpoint Name

	char *m_szFileName;		// Output Filename

	Color m_cAmbient;		// Ambient Light Intensity
	Color m_cInfinity;		// Colour At Infinity

	public:
	RenderSettings();
	RenderSettings(const RenderSettings &rs);
	RenderSettings& operator=(const RenderSettings& rs);

	~RenderSettings();

	const char* getActiveCamera() const;
	bool setActiveCamera(const char *szActiveCamera);

	const char* getFileName() const;
	bool setFileName(const char *szFileName);

	bool setWidth(int nWidth);
	int getWidth() const;

	bool setHeight(int nHeight);
	int getHeight() const;

	bool setRecursions(int nRecursions);
	int getRecursions() const;

	bool setAmbientLight(const Color &cAmbient);
	const Color& getAmbientLight() const;

	bool setInfinityColor(const Color &cInfinity);
	const Color& getInfinityColor() const;

	friend std::ostream& operator<<(std::ostream& os, const RenderSettings &rs);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
