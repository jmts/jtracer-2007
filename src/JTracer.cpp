
//////////////////////////////////////////////////////////////////////
//                                                                  //
// File:    JTracer.cpp                                             //
// Author:  Joel Sheehan (11334071)                                 //
// Date:    November 12, 2007                                       //
// Purpose: Contains Program Entry Point. Sends Input File To The   //
//          Scene Parser, Renderer, And Output System.              //
//                                                                  //
//////////////////////////////////////////////////////////////////////

//#include "RenderSettings.h"
//#include "Color.h"

//#include "CameraList.h"
//#include "PerspectiveCamera.h"

//#include "Scene.h"
//#include "Sphere.h"
//#include "Plane.h"
//#include "Cylinder.h"
//#include "PointLight.h"

#include "parser\SceneFileParser.h"

#include "RenderContext.h"

#include "Renderer.h"

#include "RenderStats.h"

#include "writers\BitmapWriter.h"

#include <iostream>

//#include <cmath>

int main(int argc, char **argv)
{
	// Handle Invalid Command Lines
	if (argc != 2)
	{
		std::cout << "Usage: jtracer.exe scene.jts" << std::endl;

		return 1;
	}

	// Parse The Scene
	std::cout << "Parsing Scene..." << std::endl << std::endl;
	SceneFileParser pParser;
	if (!pParser.parse(argv[1]))
	{
		return 2;
	}

	RenderContext rcContext = pParser.getRenderContext();

	// Initialise The Scene
	Renderer rRenderer;
	if (!rRenderer.create(pParser.getRenderContext()))
	{
		std::cout << "Initialisation Failed: " << rRenderer.getErrorString() << std::endl;
		return 3;
	}

	std::cout << "Initialised..." << std::endl << std::endl;

	std::cout << "Rendering Scene..." << std::endl << std::endl;

	// Render The Scene
	rRenderer.render();

	// Output Results
	const char *szFileName;
	if (rcContext.getRenderSettings().getFileName())
		szFileName = rcContext.getRenderSettings().getFileName();
	else
		szFileName = "jtracer.bmp";

	std::cout << "Writing Image '" << szFileName << "'..."<< std::endl << std::endl;

	if (!BitmapWriter::write(rRenderer.getSurface(), szFileName))
		std::cout << "Image Write Failed..." << std::endl;

	// Print Statistics
	RenderStats rsStats = rRenderer.getStats();
	std::cout << "Render Statistics:" << std::endl;
	std::cout << "    " << rsStats.getRenderTime() << " Seconds" << std::endl;
	std::cout << "    " << rsStats.getPrimitives() << " Primitives" << std::endl;
	std::cout << "    " << rsStats.getLights() << " Lights" << std::endl;
	std::cout << "    " << rsStats.getPrimaryRays() << " Primary Rays" << std::endl;
	std::cout << "    " << rsStats.getSecondaryRays() << " Secondary Rays" << std::endl;
	std::cout << "    " << rsStats.getShadowRays() << " Shadow Rays" << std::endl;
	std::cout << "    " << rsStats.getTotalRays() << " Total Rays" << std::endl;
	std::cout << "    " << rsStats.getIntersects() << " Intersects" << std::endl;
	std::cout << "    " << rsStats.getPixels() << " Pixels" << std::endl << std::endl;

	// Clean Up
	std::cout << "Cleaning Up..." << std::endl;

	rcContext.destroy();

	return 0;
}
