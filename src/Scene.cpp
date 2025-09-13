
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Scene.cpp                                               //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Acts As A Container Class For The Light Sources And     //
//          Primitive Objects That Describe A Scene.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "Scene.h"

//////////////////////////////////////////////////////////////////////

Scene::Scene()
{
	m_vLights.clear();

	m_vPrimitives.clear();
}

//////////////////////////////////////////////////////////////////////

Scene& Scene::operator=(const Scene& s)
{
	if (&s == this)
		return *this;

	m_vLights = s.m_vLights;
	m_vPrimitives = s.m_vPrimitives;

	return *this;
}

//////////////////////////////////////////////////////////////////////

bool Scene::destroy()
{
	for (unsigned int i = 0; i < m_vLights.size(); i++)
		delete m_vLights.at(i);

	for (unsigned int i = 0; i < m_vPrimitives.size(); i++)
		delete m_vPrimitives.at(i);

	return true;
}

//////////////////////////////////////////////////////////////////////

int Scene::addLight(Light *p)
{
	m_vLights.push_back(p);

	return 0;
}

int Scene::getNumLights() const
{
	return m_vLights.size();
}

Light* Scene::getLight(int i)
{
	return m_vLights.at(i);
}

//////////////////////////////////////////////////////////////////////

bool Scene::addPrimitive(Primitive *p)
{
	m_vPrimitives.push_back(p);

	return true;
}

int Scene::getNumPrimitives() const
{
	return m_vPrimitives.size();
}

Primitive* Scene::getPrimitive(int i)
{
	return m_vPrimitives.at(i);
}

//////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Scene &s)
{
	os << "Lights: " << s.getNumLights() << std::endl;
	os << "Primitives: " << s.getNumPrimitives() << std::endl;

	return os;
}

//////////////////////////////////////////////////////////////////////
