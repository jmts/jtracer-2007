
#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

class RayTracer
{
	private:
	Scene m_sScene;
	Color m_cInfinity;

	public:
	RayTracer() {}

	bool intersect(const Ray &rRay, const Primitive *pPrimitive, Intersect &iIntersect)
	{
		Transform tForward = pPrimitive->getTransform();
		Transform tInverse = tForward.inverse();
	
		Ray rRayInverse = tInverse * rRay;
	
		Intersect iIntersectInverse;
		if (pPrimitive->intersect(rRayInverse, iIntersectInverse))
		{
			iIntersect = tForward * iIntersectInverse;
			return true;
		}
	
		return false;
	}

	Color traceRay(Ray rRay, int nRecursions)
	{
		return Color(m_cInfinity);
	}

	bool setScene(const Scene &sScene)
	{
		m_sScene = sScene;

		return true;
	}

	bool setInfinityColor(const Color &cInfinity)
	{
		m_cInfinity = cInfinity;

		return true;
	}
};

#endif
