#include <Windows.h>

#include <vector>

#include <glut.h>

#include "main.h"
#include "Field.h"
#include "GoalNode.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "StartNode.h"
#include "WallNode.h"
#include "Window.h"

//Resolution related variables
//96 DPI - Windows constant
float DPIscale = (float)GetDpiFromDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE) / 96;
const int kFullWidth = glutGet(GLUT_SCREEN_WIDTH) * DPIscale;  //fullscreen width resolution
const int kFullHeight= glutGet(GLUT_SCREEN_HEIGHT) * DPIscale;  //fullscreen height resolution
const int kWidth = 1280, kHeight = 720;  //default window resolution
bool fullscreen = false; //default screen mode

int frametime = 10;  //frametime in milliseconds
int cell_size = 20;  //length of single field cell

Window window(kWidth, kHeight, "Pathfinding visualizer");
Field field(kWidth, kHeight, cell_size);
StartNode start;
GoalNode goal;
std::vector <WallNode> wall;

int main()
{
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);

	//GLut func initialization
	glutDisplayFunc(render);
	glutTimerFunc(frametime, gameloop, 0);
	glutKeyboardUpFunc(ReleaseKeyHandler);
	glutKeyboardFunc(PressKeyHandler);
	glutMouseFunc(ClickMouseHandler);
	glutMotionFunc(MotionMouseHandler);

	//Game loop
	glutMainLoop();
	return 0;
}

void gameloop(int = 0)
{
	render();
	update();
	glutTimerFunc(frametime, gameloop, 0);
}

void render()
{
	glClearColor(0.95f, 0.95f, 0.95f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	field.drawField();
	start.drawNode();
	goal.drawNode();
	for (size_t i = 0; i < wall.size(); i++)
	{
		wall[i].drawNode();
	}

	glFlush();
}

void update()
{

}