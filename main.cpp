#include <Windows.h>

#include <glut.h>

#include "main.h"
#include "Field.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "StartNode.h"
#include "Window.h"

//Resolution related variables
//96 DPI - Windows constant
float DPIscale = (float)GetDpiFromDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE) / 96;
const int kFullWidth = glutGet(GLUT_SCREEN_WIDTH) * DPIscale;  //fullscreen width resolution
const int kFullHeight= glutGet(GLUT_SCREEN_HEIGHT) * DPIscale;  //fullscreen height resolution
const int kWidth = 1280, kHeight = 720;  //default window resolution
bool fullscreen = false; //default screen mode

const int frametime = 10;  //frametime in milliseconds
const int cell_size = 20;  //length of single field cell

Window window(kWidth, kHeight, "Pathfinding visualizer");
Field field(kWidth, kHeight, cell_size);
StartNode startNode;

int main()
{
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);

	//GLut func initialization
	glutDisplayFunc(render);
	glutTimerFunc(frametime, gameloop, 0);
	glutKeyboardUpFunc(ReleaseKeyHandler);
	glutKeyboardFunc(PressKeyHandler);
	glutMouseFunc(mouseHandler);

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
	glClearColor(0.95, 0.95, 0.95, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	//field.drawField();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);

	for (int i = 0; i < 1920; i += 20)
	{
		glVertex2f(i, 0);
		glVertex2f(i, 1080);
	}

	for (int j = 0; j < 1080; j += 20)
	{
		glVertex2f(0, j);
		glVertex2f(1920, j);
	}
	glEnd();
	startNode.drawNode();

	glFlush();
}

void update()
{

}