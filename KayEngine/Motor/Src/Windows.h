#ifndef WINDOWS_H
#define WINDOWS_H
#define TAM 100

#include "PrivateClass/Export.h"
#include <glew.h>
#include <GLFW/glfw3.h>
//#include "GLFW/glfw3.h"

class ENGINE_API Windows{
private:
	int sizeX;
	int sizeY;
	char nameWindows[TAM];
	bool fullscreen;
public:
	Windows();
	Windows(int x, int y, const char* name);
	~Windows();
	int CheckCreateWindows();
	void CreateContextWindows();
	bool CheckGLFWwindowShouldClose();
	//void ClearWindows();
	void SwapBuffersWindows();
};
#endif