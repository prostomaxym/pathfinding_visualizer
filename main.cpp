#include <glut.h>

#include "Keyboard.h"
#include "Window.h"

void gameloop(int);
void render();
void update();

Window win(1280, 720, "Pathfinding visualizer");

const int frametime = 10;  //frametime in milliseconds

int main()
{
	//GLut func initialization
	glutDisplayFunc(render);
	glutTimerFunc(frametime, gameloop, 0);
	glutKeyboardUpFunc(ReleaseKeyHandler);
	glutKeyboardFunc(PressKeyHandler);

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

}

void update()
{

}