
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    Scene.h                                                 //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Acts As A Container Class For The Light Sources And     //
//          Primitive Objects That Describe A Scene.                //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _SCENE_H_
#define _SCENE_H_

//////////////////////////////////////////////////////////////////////

#include "Light.h"
#include "Primitive.h"

#include <vector>

#include <ostream>

//////////////////////////////////////////////////////////////////////

class Scene
{
	private:
	std::vector<Light*> m_vLights;
	std::vector<Primitive*> m_vPrimitives;

	public:
	Scene();
	Scene(const Scene &s) : m_vLights(s.m_vLights), m_vPrimitives(s.m_vPrimitives) {}
	Scene& operator=(const Scene& s);

	~Scene() { }

	bool destroy();

	int addLight(Light *p);
	int getNumLights() const;
	Light* getLight(int i);

	bool addPrimitive(Primitive *p);
	int getNumPrimitives() const;
	Primitive* getPrimitive(int i);

	friend std::ostream& operator<<(std::ostream& os, const Scene &s);
};

//////////////////////////////////////////////////////////////////////

#endif

//////////////////////////////////////////////////////////////////////
