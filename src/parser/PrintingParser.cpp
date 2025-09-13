
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    PrintingParser.cpp                                      //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Parser That Outputs Input Tokens To STDOUT //
//          For Debugging Purposes.                                 //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "PrintingParser.h"

#include "VectorToken.h"
#include "RenderSettingsToken.h"
#include "PerspectiveCameraToken.h"
#include "CameraListToken.h"
#include "MaterialToken.h"
#include "SphereToken.h"
#include "PointLightToken.h"
#include "SceneToken.h"

#include <iostream>

//////////////////////////////////////////////////////////////////////

const char* getTypeString(TokenType ttType)
{
	switch (ttType)
	{
		case T_EMPTY: return "T_EMPTY";
		case T_IDENTIFIER: return "T_IDENTIFIER";
		case T_NUMBER: return "T_NUMBER";
		case T_STRING: return "T_STRING";
		case T_OPENBRACE: return "T_OPENBRACE";
		case T_CLOSEBRACE: return "T_CLOSEBRACE";
		case T_OPENVECTOR: return "T_OPENVECTOR";
		case T_CLOSEVECTOR: return "T_CLOSEVECTOR";
		case T_SEPARATOR: return "T_SEPARATOR";
		case T_ASSIGNMENT: return "T_ASSIGNMENT";
		case T_ENDSTATEMENT: return "T_ENDSTATEMENT";
		case T_EOF: return "T_EOF";
		case T_ERROR: return "T_ERROR";
		case T_VECTOR: return "T_VECTOR";
		case T_RENDERSETTINGS: return "T_RENDERSETTINGS";
		case T_PERSPECTIVECAMERA: return "T_PERSPECTIVECAMERA";
		case T_CAMERALIST: return "T_CAMERALIST";
		case T_MATERIAL: return "T_MATERIAL";
		case T_SPHERE: return "T_SPHERE";
		case T_POINTLIGHT: return "T_POINTLIGHT";
		case T_SCENE: return "T_SCENE";
		default: return "UNKNOWN";
	}
}

//////////////////////////////////////////////////////////////////////

ParseResult PrintingParser::handleToken(const Token *tToken)
{
	std::cout << tToken->getLineNumber() << " ";

	std::cout << getTypeString(tToken->getType()) << " ";

	if (tToken->getString())
	{
		std::cout << tToken->getString();
	}

	if (tToken->getType() == T_VECTOR)
	{
		VectorToken *tVectorToken = (VectorToken*)tToken;

		Vector3 v = tVectorToken->getVector();

		std::cout << v;
	}

	if (tToken->getType() == T_RENDERSETTINGS)
	{
		std::cout << std::endl;

		RenderSettingsToken *tSettings = (RenderSettingsToken*)tToken;

		RenderSettings rsSettings = tSettings->getRenderSettings();

		std::cout << rsSettings;
	}

	if (tToken->getType() == T_PERSPECTIVECAMERA)
	{
		std::cout << std::endl;

		PerspectiveCameraToken *tCamera = (PerspectiveCameraToken*)tToken;

		PerspectiveCamera cCamera = tCamera->getPerspectiveCamera();

		std::cout << cCamera;
	}

	if (tToken->getType() == T_CAMERALIST)
	{
		std::cout << std::endl;
		CameraListToken *tCameras = (CameraListToken*)tToken;
		CameraList cCameras = tCameras->getCameraList();
		std::cout << cCameras;
	}

	if (tToken->getType() == T_MATERIAL)
	{
		std::cout << std::endl;
		MaterialToken *tMaterial = (MaterialToken*)tToken;
		Material mMaterial = tMaterial->getMaterial();
		std::cout << mMaterial;
	}

	if (tToken->getType() == T_SPHERE)
	{
		std::cout << std::endl;
		SphereToken *tSphere = (SphereToken*)tToken;
		Sphere sSphere = tSphere->getSphere();
		std::cout << sSphere;
	}

	if (tToken->getType() == T_POINTLIGHT)
	{
		std::cout << std::endl;
		PointLightToken *tPointLight = (PointLightToken*)tToken;
		PointLight lPointLight = tPointLight->getPointLight();
		std::cout << lPointLight;
	}

	if (tToken->getType() == T_SCENE)
	{
		std::cout << std::endl;
		SceneToken *tScene = (SceneToken*)tToken;
		Scene sScene = tScene->getScene();
		std::cout << sScene;
	}

	std::cout << std::endl;

	return P_OK;
}

//////////////////////////////////////////////////////////////////////

const Token* PrintingParser::getToken()
{
	return 0;
}

//////////////////////////////////////////////////////////////////////

bool PrintingParser::setTokenLineNumber(int iLineNumber)
{
	return true;
}

//////////////////////////////////////////////////////////////////////
