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
#include "Text.h"
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
int frametime = 1;  //frametime in milliseconds
int cell_size = 20;  //length of single field cell
bool finding = false;  //pathfinding state
bool slowmode = false;  //toggle update time 1X-5X

Window window(kWidth, kHeight, "Pathfinding visualizer");
Field field(kWidth, kHeight, cell_size);
StartNode start;
GoalNode goal;
std::vector <WallNode> wall;
A_star pathfind;
std::list <Node*> graph;
HeuristicFunc func = HeuristicFunc::manhattan;
Text ui;

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

//TODO 
//Make UI
//Make operation counter
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

	if (!graph.empty())  //draw visited nodes
	{
		for (auto n : graph)
		{
			n->drawNode();
		}
	}
	for (size_t i = 0; i < wall.size(); i++)  //draw wall
	{
		wall[i].drawNode();
	}
	start.drawNode();
	goal.drawNode();
	if (!(pathfind.getPath()).empty() && finding==false)  //draw path
	{
		for (auto n : pathfind.getPath())
		{
			n->drawNode(1.0f, 1.0f, 0.0f);
		}
	}
	field.drawField();

	ui.drawAlgName(25, 40);
	ui.drawNodeCount(35, 100, pathfind.numNodesVisited);
	ui.drawCostCount(35, 175, pathfind.numCostAssign);
	ui.drawKeyGuide(-200, 60);
	ui.drawActiveHeuristic(300, 50, func);
	ui.drawRenderSpeed(300, 125, slowmode);

	glFlush();
}

void update()
{
	if (finding == true)
	{
		switch (func)
		{
		case HeuristicFunc::manhattan:
			finding = pathfind.tick(&start, &goal, manhattan);
			break;
		case HeuristicFunc::euclidean:
			finding = pathfind.tick(&start, &goal, euclidean);
			break;
		case HeuristicFunc::octile:
			finding = pathfind.tick(&start, &goal, octile);
			break;
		case HeuristicFunc::chebyshev:
			finding = pathfind.tick(&start, &goal, chebyshev);
			break;
		case HeuristicFunc::hZero:
			finding = pathfind.tick(&start, &goal, hZero);
			break;
		}
	}
}