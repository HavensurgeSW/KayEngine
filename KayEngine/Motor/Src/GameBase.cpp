#include "GameBase.h"
#include "fragmentShader.h"
#include "vertexShader.h"
GameBase::GameBase()
{
	glfwInit();

	windows = new Windows(800, 450, "KayEngine");
	render = new Renderer();
	quad = new Shape(render);
	tri = new Shape(render);
}
GameBase::~GameBase() 
{
	if (windows != NULL) 
		delete windows;
	if (quad != NULL)
		delete quad;
	if (tri != NULL)
		delete tri;
	if (render != NULL)
		delete render;
}
int GameBase::Init()
{ 
	if (!glfwInit() || windows == NULL)
		return -1;

	windows->CheckCreateWindows();
	windows->CreateContextWindows();
	render->GLEWInit();
	
	tri->InitShape(GL_TRIANGLES);

	render->SetShader(vertexShader, fragmentShader);

	tri->SetVertexsAttrib(render->GetShader());

	glUseProgram(render->GetShader());

	render->ClearShader();
	render->UnbindBuffer();

	//VALORES DE TESTEO
	float posX = 0;
	float posY = 0;
	float speed = 0.02f;
	const float posZ = 1;

	float rotX = 0;
	float rotY = 0;
	float rotZ = 0.5f;
	float speedRotation = 0.02f;

	float scalX = 0.1f;
	float scalY = 0.5f;
	float scalZ = 0.2f;
	float speedScale = 0.02f;

	float r = 1.0f;
	float g = 0.5f;
	float b = 0.0f;
	float a = 1.0f;
	bool enableSetSolidColor = true;

	while (!windows->CheckGLFWwindowShouldClose()){	
		if (enableSetSolidColor){
			tri->SetSolidColor(r, g, b, a, vertexShader, fragmentShader);
			if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_ENTER) == GLFW_PRESS) {
				r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				a = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			}
		}

		tri->Draw(GL_TRIANGLES, 3, render->GetShader(), windows, tri->GetInternalData().model);
		
		if (glfwGetKey(windows->GetWindowsPtr(),GLFW_KEY_1) == GLFW_PRESS) {
			tri->SetPosition(0.05f,0.02f, 0.08f);
		}
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_2) == GLFW_PRESS) {
			tri->SetRotationZ(rotZ);
		}
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_3) == GLFW_PRESS){
			tri->SetScale(scalX, scalY, scalZ);
		}
		
		glfwPollEvents();
	}

	glDeleteProgram(render->GetShader());
	glfwTerminate();
	return 0; 
}