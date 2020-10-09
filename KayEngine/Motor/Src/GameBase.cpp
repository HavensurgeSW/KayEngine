#include "GameBase.h"
#include "fragmentShader.h"
#include "vertexShader.h"

GameBase::GameBase() {
	windows = new Windows(1080, 720, "KayEngine");
	render = new Renderer();
}
GameBase::~GameBase() {
	
}

int GameBase::Init() {		

	if (!glfwInit() || windows == NULL)
		return -1;

	windows->CheckCreateWindows();
	windows->CreateContextWindows();

	while (!windows->CheckGLFWwindowShouldClose()) {

		glClear(GL_COLOR_BUFFER_BIT);

		windows->SwapBuffersWindows();

		glfwPollEvents();
	}

	delete windows;
	return 0;
	
}