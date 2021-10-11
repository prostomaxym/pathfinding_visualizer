#include <glut.h>

#include "Field.h"
#include "main.h"
#include "Keyboard.h"
#include "Window.h"

bool fullscreen = false;
const int frametime = 10;  //frametime in milliseconds
const int w = 1280, h = 720;  //window resolution
const int cell_size = 20;  //length of single field cell

Window window(w, h, "Pathfinding visualizer");
Field field(w, h, cell_size);

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
	glClearColor(0.95, 0.95, 0.95, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	field.drawField();

	glFlush();
}

void update()
{

}