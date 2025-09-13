
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RenderStats.cpp                                         //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides Statistical Tallying Facilities For An Entire  //
//          Render.                                                 //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "RenderStats.h"

#include <cmath>

//////////////////////////////////////////////////////////////////////

RenderStats::RenderStats()
{
	zeroStats();
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::zeroStats()
{
	m_nIntersects = 0;
	m_nPrimaryRays = 0;
	m_nSecondaryRays = 0;
	m_nTotalRays = 0;
	m_nShadowRays = 0;

	m_nPixels = 0;
	m_nPrimitives = 0;
	m_nLights = 0;

	m_tStartTime = -1;
	m_tEndTime = -1;

	return true;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::incIntersects()
{
	m_nIntersects++;
	return true;
}

int RenderStats::getIntersects() const
{
	return m_nIntersects;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::incPrimaryRays()
{
	m_nPrimaryRays++;
	return true;
}

int RenderStats::getPrimaryRays() const
{
	return m_nPrimaryRays;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::incSecondaryRays()
{
	m_nSecondaryRays++;
	return true;
}

int RenderStats::getSecondaryRays() const
{
	return m_nSecondaryRays;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::incTotalRays()
{
	m_nTotalRays++;
	return true;
}

int RenderStats::getTotalRays() const
{
	return m_nTotalRays;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::incShadowRays()
{
	m_nShadowRays++;
	return true;
}

int RenderStats::getShadowRays() const
{
	return m_nShadowRays;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::incPixels()
{
	m_nPixels++;
	return true;
}

int RenderStats::getPixels() const
{
	return m_nPixels;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::setPrimitives(int nPrimitives)
{
	m_nPrimitives = nPrimitives;
	return true;
}

int RenderStats::getPrimitives() const
{
	return m_nPrimitives;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::setLights(int nLights)
{
	m_nLights = nLights;
	return true;
}

int RenderStats::getLights() const
{
	return m_nLights;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::addTraceStats(const TraceStats &tsStats)
{
	m_nIntersects += tsStats.getIntersects();
	m_nPrimaryRays += tsStats.getPrimaryRays();
	m_nSecondaryRays += tsStats.getSecondaryRays();
	m_nTotalRays += tsStats.getTotalRays();
	m_nShadowRays += tsStats.getShadowRays();

	return true;
}

//////////////////////////////////////////////////////////////////////

bool RenderStats::captureStartTime()
{
	m_tStartTime = std::time(0);
	return true;
}

bool RenderStats::captureEndTime()
{
	m_tEndTime = std::time(0);
	return true;
}

int RenderStats::getRenderTime() const
{
	return std::floor(std::difftime(m_tEndTime, m_tStartTime));
}

//////////////////////////////////////////////////////////////////////
