#ifndef GAMEBASE_H
#define GAMEBASE_H

#include "PrivateClass/Export.h"
#include "Windows.h"
#include "Renderer.h"
#include "Shape.h"
#include <time.h>
#include <stdlib.h>


class ENGINE_API GameBase {
private:
	Windows* windows;
	Renderer* render;
	
	Shape* quad;
	Shape* tri;
public:
	GameBase();
	~GameBase();
	int Init();
};
#endif