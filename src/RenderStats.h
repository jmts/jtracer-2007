
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderStats.h                                           //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides Statistical Tallying Facilities For An Entire  //
//          Render.                                                 //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RENDERSTATS_H_
#define _RENDERSTATS_H_

//////////////////////////////////////////////////////////////////////

#include "TraceStats.h"

#include <ctime>

//////////////////////////////////////////////////////////////////////

class RenderStats
{
	private:
	int m_nIntersects;
	int m_nPrimaryRays;
	int m_nSecondaryRays;
	int m_nTotalRays;
	int m_nShadowRays;

	int m_nPixels;
	int m_nPrimitives;
	int m_nLights;

	std::time_t m_tStartTime;
	std::time_t m_tEndTime;

	public:
	RenderStats();

	bool zeroStats();

	bool incIntersects();
	int getIntersects() const;

	bool incPrimaryRays();
	int getPrimaryRays() const;

	bool incSecondaryRays();
	int getSecondaryRays() const;

	bool incTotalRays();
	int getTotalRays() const;

	bool incShadowRays();
	int getShadowRays() const;

	bool incPixels();
	int getPixels() const;

	bool setPrimitives(int nPrimitives);
	int getPrimitives() const;

	bool setLights(int nLights);
	int getLights() const;

	bool addTraceStats(const TraceStats &tsStats);

	bool captureStartTime();
	bool captureEndTime();
	int getRenderTime() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
