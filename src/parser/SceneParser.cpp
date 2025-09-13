
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SceneParser.cpp                                         //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser For Scene Element Collections.      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "SceneParser.h"
#include "PointLightToken.h"
#include "SphereToken.h"
#include "PlaneToken.h"
#include "CylinderToken.h"

//////////////////////////////////////////////////////////////////////

SceneParser::SceneParser()
{
	setExpecting(T_OPENBRACE);
}

//////////////////////////////////////////////////////////////////////

ParseResult SceneParser::handleToken(const Token *tToken)
{
	if (getExpecting() != T_ANY && getExpecting() != tToken->getType())
		return P_UNEXPECTED;

	if (getExpecting() == T_OPENBRACE)
	{
		setExpecting(T_ANY);
		return P_OK;
	}

	else if (getExpecting() == T_ANY)
	{
		if (tToken->getType() == T_CLOSEBRACE)
		{
			return P_COMPLETE;
		}

		else if (tToken->getType() == T_POINTLIGHT)
		{
			PointLightToken *plToken = (PointLightToken*)tToken;
			PointLight *lLight = new PointLight(plToken->getPointLight());
			m_sScene.addLight(lLight);
			return P_OK;
		}
		else if (tToken->getType() == T_SPHERE)
		{
			SphereToken *sToken = (SphereToken*)tToken;
			Sphere *sSphere = new Sphere(sToken->getSphere());
			m_sScene.addPrimitive(sSphere);
			return P_OK;
		}
		else if (tToken->getType() == T_PLANE)
		{
			PlaneToken *pToken = (PlaneToken*)tToken;
			Plane *pPlane = new Plane(pToken->getPlane());
			m_sScene.addPrimitive(pPlane);
			return P_OK;
		}
		else if (tToken->getType() == T_CYLINDER)
		{
			CylinderToken *cToken = (CylinderToken*)tToken;
			Cylinder *cCylinder = new Cylinder(cToken->getCylinder());
			m_sScene.addPrimitive(cCylinder);
			return P_OK;
		}
	}

	return P_UNKNOWN;
}

//////////////////////////////////////////////////////////////////////

const Token* SceneParser::getToken()
{
	m_tToken.setScene(m_sScene);

	return &m_tToken;
}

//////////////////////////////////////////////////////////////////////

bool SceneParser::setTokenLineNumber(int iLineNumber)
{
	m_tToken.setLineNumber(iLineNumber);

	return true;
}

//////////////////////////////////////////////////////////////////////
