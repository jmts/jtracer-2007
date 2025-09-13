
#include "Light.h"
#include "Primitive.h"

#ifndef _SCENE_H_
#define _SCENE_H_

class Scene
{
	private:
	std::vector<Light*> m_vLights;
	std::vector<Primitive*> m_vPrimitives;

	public:
	Scene()
	{
		m_vLights.clear();

		m_vPrimitives.clear();
	}

	Scene(const Scene &s) : m_vLights(s.m_vLights), m_vPrimitives(s.m_vPrimitives) {}

	~Scene()
	{
		
	}

	bool destroy()
	{
		for (unsigned int i = 0; i < m_vLights.size(); i++)
			delete m_vLights.at(i);

		for (unsigned int i = 0; i < m_vPrimitives.size(); i++)
			delete m_vPrimitives.at(i);

		return true;
	}

	int addLight(Light *p)
	{
		m_vLights.push_back(p);
	
		return 0;
	}

	int getNumLights()
	{
		return m_vLights.size();
	}

	Light* getLight(int i)
	{
		return m_vLights.at(i);
	}

	bool addPrimitive(Primitive *p)
	{
		m_vPrimitives.push_back(p);
	
		return true;
	}

	int getNumPrimitives()
	{
		return m_vPrimitives.size();
	}

	Primitive* getPrimitive(int i)
	{
		return m_vPrimitives.at(i);
	}
};

#endif
