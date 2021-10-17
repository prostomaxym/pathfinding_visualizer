#include <ctime>
#include <Windows.h>

#include <random>
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
bool fullscreen = false;  //default screen mode

int kNumRandWall = 750;  //number of random wall nodes
int frametime = 10;  //frametime in milliseconds
int cell_size = 20;  //length of single field cell

Window window(kWidth, kHeight, "Pathfinding visualizer");
Field field(kWidth, kHeight, cell_size);
StartNode start;
GoalNode goal;
std::vector <WallNode> wall;
A_star astar;
std::list <Node*> graph;


bool intersect(std::pair <int, int> coord)
{
	if (start.getCoordinates() == coord) return true;
	if (goal.getCoordinates() == coord) return true;
	for (size_t i = 0; i < wall.size(); i++)
	{
		if (wall[i].getCoordinates() == coord) return true;
	}
	return false;
}

void generateRandomWalls(int number)
{
	int x, y;
	std::pair <int, int> coord;
	for (int i = 0; i < number; i++)
	{
		x = (rand() % glutGet(GLUT_WINDOW_WIDTH)) / field.getScale();
		y = (rand() % glutGet(GLUT_WINDOW_HEIGHT)) / field.getScale();
		coord = std::make_pair(x, y);
		if (!intersect(coord))
		{
			wall.push_back(WallNode(x, y));
		}
		else i--;
	}
}

//TODO memory leak
int main()
{
	srand(time(NULL));
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
	if (!graph.empty())
	{
		for (auto n : astar.getPath())
		{
			n->drawNode();
		}
	}
	glFlush();
}

void update()
{

}