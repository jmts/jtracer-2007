
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    TraceStats.cpp                                          //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides Statistical Tallies For Individual Traces.     //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "TraceStats.h"

//////////////////////////////////////////////////////////////////////

TraceStats::TraceStats()
{
	zeroStats();
}

//////////////////////////////////////////////////////////////////////

bool TraceStats::zeroStats()
{
	m_nIntersects = 0;
	m_nPrimaryRays = 0;
	m_nSecondaryRays = 0;
	m_nTotalRays = 0;
	m_nShadowRays = 0;

	return true;
}

//////////////////////////////////////////////////////////////////////

bool TraceStats::incIntersects()
{
	m_nIntersects++;
	return true;
}

int TraceStats::getIntersects() const
{
	return m_nIntersects;
}

//////////////////////////////////////////////////////////////////////

bool TraceStats::incPrimaryRays()
{
	m_nPrimaryRays++;
	return true;
}

int TraceStats::getPrimaryRays() const
{
	return m_nPrimaryRays;
}

//////////////////////////////////////////////////////////////////////

bool TraceStats::incSecondaryRays()
{
	m_nSecondaryRays++;
	return true;
}

int TraceStats::getSecondaryRays() const
{
	return m_nSecondaryRays;
}

//////////////////////////////////////////////////////////////////////

bool TraceStats::incTotalRays()
{
	m_nTotalRays++;
	return true;
}

int TraceStats::getTotalRays() const
{
	return m_nTotalRays;
}

//////////////////////////////////////////////////////////////////////

bool TraceStats::incShadowRays()
{
	m_nShadowRays++;
	return true;
}

int TraceStats::getShadowRays() const
{
	return m_nShadowRays;
}

//////////////////////////////////////////////////////////////////////
