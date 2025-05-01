#include <iostream>
#include "window.h"
#include "canvas3d.h"
#include "canvas2d.h"

const int WIDTH = 900; //900
const int HEIGHT = 533;//533

int main() {
	Window window(WIDTH, HEIGHT, 60.0f);
	Canvas3d modelCanvas(WIDTH, HEIGHT);
	Canvas2d uiCanvas(&modelCanvas, WIDTH, HEIGHT);

	while (!window.ShouldClose()) {
		window.SetFrameRate();
        window.Clear(0.0392f, 0.0392f, 0.0392f, 1.0f);
        window.PollEvents();

		uiCanvas.HandleInput(window.GetGLFWwindow(), window.GetDeltaTime());
		modelCanvas.HandleInput(window.GetGLFWwindow(), window.GetDeltaTime());

		uiCanvas.Update();

		glEnable(GL_DEPTH_TEST);
		modelCanvas.Render();
		glDisable(GL_DEPTH_TEST);
		uiCanvas.Render();
		
        window.SwapBuffers();
    }

	modelCanvas.Clean();
	uiCanvas.Clean();

    return 0;
}