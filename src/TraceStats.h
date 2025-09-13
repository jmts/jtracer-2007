
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    TraceStats.h                                            //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Provides Statistical Tallies For Individual Traces.     //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _TRACESTATS_H_
#define _TRACESTATS_H_

//////////////////////////////////////////////////////////////////////

class TraceStats
{
	private:
	int m_nIntersects;
	int m_nPrimaryRays;
	int m_nSecondaryRays;
	int m_nTotalRays;
	int m_nShadowRays;

	public:
	TraceStats();

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
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
