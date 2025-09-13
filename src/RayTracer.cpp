
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    RayTracer.cpp                                           //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements The Core Ray Tracing System. Provides Traces //
//          Of Primary (And Subsequent Secondary) Rays Throughout   //
//          A Scene.                                                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "RayTracer.h"

#include "Vector3.h"
#include "Transform.h"

//////////////////////////////////////////////////////////////////////
// traceShadowRay - Trace A Shadow Ray To Find Occlusions ////////////
//////////////////////////////////////////////////////////////////////

Color RayTracer::traceShadowRay(const Ray &rRay, const Light *lLight, const IntersectConditions &icExclude)
{
	m_tsStats.incTotalRays();
	m_tsStats.incShadowRays();

	Intersect iTest;
	for (int i = 0; i < m_sScene.getNumPrimitives(); i++)
	{
		Primitive *pPrimitive = m_sScene.getPrimitive(i);

		// Test Intersection Of Ray With Primitive
		m_tsStats.incIntersects();
		Ray rRayInverse = pPrimitive->getTransform().inverse() * rRay;
		if (pPrimitive->intersect(rRayInverse, iTest, icExclude) && (iTest.getT() > 0.0 && iTest.getT() <= 1.0))
			return Color(0.0, 0.0, 0.0);
	}

	return lLight->getIntensity(rRay.getOrigin());
}

//////////////////////////////////////////////////////////////////////
// calcReflectionRay - Determine Direction Of Ray After Reflection ///
//////////////////////////////////////////////////////////////////////

Ray RayTracer::calcReflectionRay(const Vector3 &vPoint, const Vector3 &vIncident, const Vector3 &vNormal)
{
	Vector3 vReflect = vIncident - (vNormal * (2.0f * vIncident.dot(vNormal)));

	return Ray(vPoint, vReflect.unit());
}

//////////////////////////////////////////////////////////////////////
// traceRay - Trace A Primary Ray Through A Scene ////////////////////
//////////////////////////////////////////////////////////////////////

Color RayTracer::traceRay(const Ray &rRay, int nRecursions)
{
	m_tsStats.zeroStats();		// Zero Stats For This Trace

	m_tsStats.incPrimaryRays();	// Increment Total Rays

	// Trace It
	return traceRay(rRay, nRecursions, IntersectConditions());
}

//////////////////////////////////////////////////////////////////////
// traceRay - Trace A Ray Through A Scene, With Exclusions ///////////
//////////////////////////////////////////////////////////////////////

Color RayTracer::traceRay(const Ray &rRay, int nRecursions, const IntersectConditions &icExclude)
{
	m_tsStats.incTotalRays();	// Increment Total Rays Traced


	// Find The Primitive With Smallest t
	bool bFound = false;
	Intersect iCurrent;			// Current Intersection Data

	Intersect iTest;
	for (int i = 0; i < m_sScene.getNumPrimitives(); i++)
	{
		Primitive *pPrimitive = m_sScene.getPrimitive(i);

		// Transform Ray
		Ray rRayInverse = pPrimitive->getTransform().inverse() * rRay;

		// Increment Intersect Test Count
		m_tsStats.incIntersects();

		// Test Intersects For Smallest t
		if (pPrimitive->intersect(rRayInverse, iTest, icExclude))
		{
			if (!bFound)
			{
				iCurrent = iTest;
				bFound = true;
			}
			else if (iTest.getT() > 0.0 && iTest.getT() < iCurrent.getT())
			{
				iCurrent = iTest;
			}
		}
	}

	// Return Background Color For Infinite Rays
	if (!bFound)
		return Color(m_cInfinity);

	// Transform The Intersection Data Back To World Space
	iCurrent = iCurrent.getPrimitive()->getTransform() * iCurrent;

	// Fetch The Primitive's Material
	Material mMaterial = iCurrent.getPrimitive()->getMaterial();

	// Calculate The Ambient Light
	Color cAmbient = mMaterial.getPigment() * mMaterial.getAmbientColor() * m_cAmbient;

	Color cDiffuse(0,0,0);
	Color cSpecular(0,0,0);

	// Calculate Ray Diffuse & Specular Components
	for (int i = 0; i < m_sScene.getNumLights(); i++)
	{
		Light *lLight = m_sScene.getLight(i);

		// Get Lighting Vector
		Vector3 vLight = (lLight->getPosition() - iCurrent.getPoint());

		// Create Shadow Ray
		Ray rShadow(iCurrent.getPoint(), vLight);

		// Trace Shadow Ray To Find Occlusions
		Color cIntensity = traceShadowRay(rShadow, lLight, IntersectConditions(iCurrent.getPrimitive(), ISECT_OUT));
		if (cIntensity.nonZero())
		{
			vLight = vLight.unit();

			// Calculate Diffuse Reflection
			if (mMaterial.getDiffuseColor().nonZero())
			{
				float fDiffuseDot = vLight.dot(iCurrent.getNormal());

				if (fDiffuseDot > 0.0f)
					cDiffuse  += cIntensity * mMaterial.getPigment() * mMaterial.getDiffuseColor() * std::pow(fDiffuseDot, mMaterial.getDiffuseK());
			}

			// Calculate Specular Highlighting
			if (mMaterial.getSpecularColor().nonZero())
			{
				Vector3 vHalfway = (vLight - rRay.getDirection()).unit();
				float fSpecularDot = vHalfway.dot(iCurrent.getNormal());

				if (fSpecularDot > 0.0f)
					cSpecular += cIntensity * mMaterial.getSpecularColor() * std::pow(fSpecularDot, mMaterial.getSpecularK());
			}
		}
	}

	// Calculate Reflection Colour
	Color cReflect(0,0,0);
	if ((mMaterial.getReflectionK() > 0.0f) && (nRecursions > 0))
	{
		m_tsStats.incSecondaryRays();

		Ray rReflect = calcReflectionRay(iCurrent.getPoint(), rRay.getDirection(), iCurrent.getNormal());

		cReflect = traceRay(rReflect, (nRecursions-1), IntersectConditions(iCurrent.getPrimitive(), ISECT_OUT));

		cReflect *= mMaterial.getReflectionK();
	}

	return (cAmbient + cDiffuse + cSpecular + cReflect).clip();
}

//////////////////////////////////////////////////////////////////////

bool RayTracer::setScene(const Scene &sScene)
{
	m_sScene = sScene;

	return true;
}

bool RayTracer::setAmbientLight(const Color &cAmbient)
{
	m_cAmbient = cAmbient;

	return true;
}

bool RayTracer::setInfinityColor(const Color &cInfinity)
{
	m_cInfinity = cInfinity;

	return true;
}

//////////////////////////////////////////////////////////////////////

const TraceStats& RayTracer::getStats() const
{
	return m_tsStats;
}

//////////////////////////////////////////////////////////////////////
