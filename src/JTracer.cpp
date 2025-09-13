
#include "RenderSettings.h"
#include "Color.h"

#include "Cameras.h"
#include "PerspectiveCamera.h"

#include "Scene.h"
#include "Sphere.h"

#include "RenderContext.h"

#include "Renderer.h"

#include "BitmapWriter.h"

#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
	RenderSettings rsRenderSettings;
	rsRenderSettings.setWidth(640);
	rsRenderSettings.setHeight(480);
	rsRenderSettings.setActiveCamera("Camera 1");
	rsRenderSettings.setFileName("output.bmp");
	rsRenderSettings.setInfinityColor(Color(1.0f, 1.0f, 0.0f));

	Cameras cCameras;
	cCameras.addCamera(new PerspectiveCamera("Camera 1", Vector3(0,0,0), Vector3(0,0,1), Vector3(0,1,0), M_PI/4.0f, 4.0f/3.0f));
	cCameras.addCamera(new PerspectiveCamera("Camera 2", Vector3(0,0,0), Vector3(0,0,1), Vector3(0,1,0), M_PI/3.0f, 1.0f));

	Scene sScene;
	sScene.addPrimitive(new Sphere(Vector3(0.0, 0.0, 0.0), 1.0f, Material(Color(1.0f, 1.0f, 1.0f), Color(1.0f, 0.0f, 0.0f), Color(0.0f, 1.0f, 0.0f), Color(0.0f, 0.0f, 1.0f))));
	sScene.addPrimitive(new Sphere(Vector3(1.0, 1.0, 0.0), 0.5f));

	RenderContext rcRenderContext(rsRenderSettings, cCameras, sScene);

	Renderer rRenderer;
	rRenderer.create(rcRenderContext);
	rRenderer.render();

	BitmapWriter::write(rRenderer.getSurface(), rsRenderSettings.getFileName());

	rcRenderContext.destroy();

	return 0;
}
