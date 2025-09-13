
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    SceneFileParser.cpp                                     //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Implements A Scene Description File Parser. Core Parser //
//          System For Parsing Files And Producing RenderContexts.  //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "SceneFileParser.h"

#include "RenderContextParser.h"
#include "PrintingParser.h"
#include "VectorParser.h"
#include "RenderSettingsParser.h"
#include "PerspectiveCameraParser.h"
#include "CameraListParser.h"
#include "MaterialParser.h"
#include "SphereParser.h"
#include "PointLightParser.h"
#include "SceneParser.h"
#include "PlaneParser.h"
#include "CylinderParser.h"
#include "TransformParser.h"

//////////////////////////////////////////////////////////////////////

SceneFileParser::~SceneFileParser()
{
	emptyTokenStack();

	emptyParserStack();
}

//////////////////////////////////////////////////////////////////////
// copyToken - Copies A Token Properly. Better Way? //////////////////
//////////////////////////////////////////////////////////////////////

Token* SceneFileParser::copyToken(const Token *tToken)
{
	if (tToken->getType() == T_VECTOR)
		return new VectorToken(*((VectorToken*)tToken));

	if (tToken->getType() == T_RENDERSETTINGS)
		return new RenderSettingsToken(*((RenderSettingsToken*)tToken));

	if (tToken->getType() == T_PERSPECTIVECAMERA)
		return new PerspectiveCameraToken(*((PerspectiveCameraToken*)tToken));

	if (tToken->getType() == T_CAMERALIST)
		return new CameraListToken(*((CameraListToken*)tToken));

	if (tToken->getType() == T_MATERIAL)
		return new MaterialToken(*((MaterialToken*)tToken));

	if (tToken->getType() == T_SPHERE)
		return new SphereToken(*((SphereToken*)tToken));

	if (tToken->getType() == T_POINTLIGHT)
		return new PointLightToken(*((PointLightToken*)tToken));

	if (tToken->getType() == T_SCENE)
		return new SceneToken(*((SceneToken*)tToken));

	if (tToken->getType() == T_PLANE)
		return new PlaneToken(*((PlaneToken*)tToken));

	if (tToken->getType() == T_CYLINDER)
		return new CylinderToken(*((CylinderToken*)tToken));

	if (tToken->getType() == T_TRANSFORM)
		return new TransformToken(*((TransformToken*)tToken));

	return new Token(*tToken);
}

//////////////////////////////////////////////////////////////////////

const char* SceneFileParser::typeString(TokenType ttType)
{
	switch (ttType)
	{
		case T_EMPTY: return "T_EMPTY";
		case T_IDENTIFIER: return "Identifier";
		case T_NUMBER: return "Number";
		case T_STRING: return "String";
		case T_OPENBRACE: return "'{'";
		case T_CLOSEBRACE: return "'}'";
		case T_OPENVECTOR: return "'<'";
		case T_CLOSEVECTOR: return "'>'";
		case T_SEPARATOR: return "','";
		case T_ASSIGNMENT: return "':'";
		case T_ENDSTATEMENT: return "';'";
		case T_EOF: return "End Of File";
		case T_ERROR: return "T_ERROR";
		case T_VECTOR: return "Vector";
		case T_RENDERSETTINGS: return "Render Settings";
		case T_PERSPECTIVECAMERA: return "Perspective Camera";
		case T_CAMERALIST: return "Camera List";
		case T_MATERIAL: return "Material";
		case T_SPHERE: return "Sphere";
		case T_POINTLIGHT: return "Point Light";
		case T_SCENE: return "Scene";
		case T_PLANE: return "Plane";
		case T_CYLINDER: return "Cylinder";
		case T_TRANSFORM: return "Transform";

		default: return "UNKNOWN";
	}
}

//////////////////////////////////////////////////////////////////////
// parseKeywords - Handles Keyword Tokens ////////////////////////////
//////////////////////////////////////////////////////////////////////

bool SceneFileParser::parseKeywords(const Token* tToken)
{
	Parser *pParser = 0;

	if (tToken->getType() == T_OPENVECTOR)
		pParser = new VectorParser();

	if (tToken->getType() == T_IDENTIFIER)
	{
		if (strcmp(tToken->getString(), "render_settings") == 0)
			pParser = new RenderSettingsParser();
		else if (strcmp(tToken->getString(), "perspective_camera") == 0)
			pParser = new PerspectiveCameraParser();
		else if (strcmp(tToken->getString(), "cameras") == 0)
			pParser = new CameraListParser();
		else if (strcmp(tToken->getString(), "material") == 0)
			pParser = new MaterialParser();
		else if (strcmp(tToken->getString(), "sphere") == 0)
			pParser = new SphereParser();
		else if (strcmp(tToken->getString(), "point_light") == 0)
			pParser = new PointLightParser();
		else if (strcmp(tToken->getString(), "scene") == 0)
			pParser = new SceneParser();
		else if (strcmp(tToken->getString(), "plane") == 0)
			pParser = new PlaneParser();
		else if (strcmp(tToken->getString(), "cylinder") == 0)
			pParser = new CylinderParser();
		else if (strcmp(tToken->getString(), "transform") == 0)
			pParser = new TransformParser();
	}

	if (pParser)
	{
		pParser->setTokenLineNumber(tToken->getLineNumber());

		m_sParserStack.push(pParser);

		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////
// parse - Parse A Scene File And Produce A Render Context ///////////
//////////////////////////////////////////////////////////////////////

bool SceneFileParser::parse(const char *szFileName)
{
	if (!m_lLexer.open(szFileName))
		return false;

	if (!fillTokenStack())
	{
		std::cout << "Error Tokenising Input File" << std::endl;

		return false;
	}

	/*
	PrintingParser *pPrinter = new PrintingParser();
	m_sParserStack.push(pPrinter);
	*/
	RenderContextParser *pRenderContext = new RenderContextParser();
	m_sParserStack.push(pRenderContext);

	while (!m_sTokenStack.empty())
	{
		// Get The Next Token
		Token *tToken = m_sTokenStack.top();

		// Process New Parsers
		if (parseKeywords(tToken))
		{
			m_sTokenStack.pop();
			delete tToken;
		}

		// Or Dispense Tokens
		else
		{
			ParseResult prResult = m_sParserStack.top()->handleToken(tToken);

			if (prResult == P_UNEXPECTED)
			{
				// Unexpected Token
				std::cout << "Unexpected Token: Expecting ";
				std::cout << typeString(m_sParserStack.top()->getExpecting());
				std::cout << " Got " << typeString(tToken->getType()) << " On Line ";
				std::cout << tToken->getLineNumber() << "." << std::endl;

				return false;
			}
			else if (prResult == P_ERRORVAL)
			{
				std::cout << "Range Error: Input Value Out Of Range On Line ";
				std::cout << tToken->getLineNumber() << "." << std::endl;

				return false;
			}
			else if (prResult == P_UNKNOWN)
			{
				std::cout << "Unknown Token: Unrecognised ";
				if (tToken->getString())
					std::cout << "Token '" << tToken->getString() << "' ";
				else
					std::cout << typeString(tToken->getType()) << " Token ";
				std::cout << "On Line " << tToken->getLineNumber() << "." << std::endl;

				return false;
			}
			else if (prResult == P_OK)
			{
				// Consume Current Token
				m_sTokenStack.pop();
				delete tToken;
			}
			else if (prResult == P_COMPLETE)
			{
				// Consume Current Token
				m_sTokenStack.pop();
				delete tToken;

				// Push New Token
				Parser *pTopParser = m_sParserStack.top();
				Token *tCopy = copyToken(pTopParser->getToken());
				m_sTokenStack.push(tCopy);

				// Remove Old Parser
				m_sParserStack.pop();

				delete pTopParser;
			}
			else
			{
				std::cout << "Shat Itself" << std::endl;
				std::cout << typeString(tToken->getType()) << std::endl;
				std::cout << tToken->getString() << std::endl;
				return false;
			}
		}
	}

	//std::cout << "Stack Size: " << m_sParserStack.size() << std::endl;

	if (m_sParserStack.size() > 1)
	{
		std::cout << "Unexpected End Of File" << std::endl;
		return false;
	}

	/*
	RenderContextParser* rcParser = (RenderContextParser*)m_sParserStack.top();

	RenderContextToken* rcToken = (RenderContextToken*)rcParser->getToken();

	m_rcContext.setRenderSettings(rcToken->getRenderContext().getRenderSettings());
	m_rcContext.setCameraList(rcToken->getRenderContext().getCameraList());
	m_rcContext.setScene(rcToken->getRenderContext().getScene());
	*/

	return true;
}

//////////////////////////////////////////////////////////////////////

bool SceneFileParser::fillTokenStack()
{
	std::stack<Token *> tTempStack;

	const Token *tToken = m_lLexer.getToken();

	while (tToken->getType() != T_ERROR && tToken->getType() != T_EOF)
	{
		tTempStack.push(new Token(*tToken));

		tToken = m_lLexer.getToken();
	}

	if (tToken->getType() == T_ERROR)
	{
		/*
		while (!tTempStack.empty())
		{
			tToken = tTempStack.top();

			if (tToken)
				delete tToken;

			tTempStack.pop();
		}
		*/
		return false;
	}

	while (!tTempStack.empty())
	{
		Token *t = tTempStack.top();

		if (t)
			m_sTokenStack.push(t);

		tTempStack.pop();
	}

	return true;
}

//////////////////////////////////////////////////////////////////////

bool SceneFileParser::emptyTokenStack()
{
	while (!m_sTokenStack.empty())
	{
		Token *t = m_sTokenStack.top();

		if (t)
			delete t;

		m_sTokenStack.pop();
	}

	return true;
}

//////////////////////////////////////////////////////////////////////

bool SceneFileParser::emptyParserStack()
{
	while (!m_sParserStack.empty())
	{
		Parser *p = m_sParserStack.top();

		if (p)
			delete p;

		m_sParserStack.pop();
	}

	return true;
}

//////////////////////////////////////////////////////////////////////

const RenderContext& SceneFileParser::getRenderContext() const
{
	RenderContextParser* rcParser = (RenderContextParser*)m_sParserStack.top();

	RenderContextToken* rcToken = (RenderContextToken*)rcParser->getToken();
	return rcToken->getRenderContext();
}

//////////////////////////////////////////////////////////////////////
