
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RayTracer.h                                             //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements The Core Ray Tracing System. Provides Traces //
//          Of Primary (And Subsequent Secondary) Rays Throughout   //
//          A Scene.                                                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

//////////////////////////////////////////////////////////////////////

#include "Scene.h"
#include "Color.h"
#include "Ray.h"
#include "Primitive.h"
#include "Intersect.h"
#include "TraceStats.h"

//////////////////////////////////////////////////////////////////////

class RayTracer
{
	private:
	Scene m_sScene;

	Color m_cAmbient;
	Color m_cInfinity;

	TraceStats m_tsStats;

	public:
	RayTracer() { }

	Color traceRay(const Ray &rRay, int nRecursions);

	Color traceRay(const Ray &rRay, int nRecursions, const IntersectConditions &icExclude);

	Color traceShadowRay(const Ray &rRay, const Light *lLight, const IntersectConditions &icExclude);

	Ray calcReflectionRay(const Vector3 &vPoint, const Vector3 &vIncident, const Vector3 &vNormal);

	bool setScene(const Scene &sScene);
	bool setAmbientLight(const Color &cAmbient);
	bool setInfinityColor(const Color &cInfinity);

	const TraceStats& getStats() const;
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
