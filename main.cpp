#include <ctime>
#include <Windows.h>

#include <map>
#include <list>
#include <vector>

#include <glut.h>

#include "main.h"
#include "Field.h"
#include "GoalNode.h"
#include "Heuristic.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "StartNode.h"
#include "Text.h"
#include "WallNode.h"
#include "Walls.h"
#include "Window.h"

//Resolution related variables
//96 DPI - Windows constant
float DPIscale = (float)GetDpiFromDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE) / 96;
const int kFullWidth = glutGet(GLUT_SCREEN_WIDTH) * DPIscale;  //fullscreen width resolution
const int kFullHeight= glutGet(GLUT_SCREEN_HEIGHT) * DPIscale;  //fullscreen height resolution
const int kWidth = 1280, kHeight = 720;  //default window resolution
bool fullscreen = false;  //default screen mode

int kNumRandWall = 750;  //number of random wall nodes
int frametime = 1;  //delay between frames in milliseconds
int cell_size = 20;  //length of single field cell
bool finding = false;  //pathfinding state
bool slowmode = false;  //toggle update time 1X-5X
bool allowDiagonal = true;  // allow diagonal movement

Window window(kWidth, kHeight, "Pathfinding visualizer");
Field field(kWidth, kHeight, cell_size);
StartNode start;
GoalNode goal;
std::vector <std::vector <WallNode>> wall;  //2d wall container for fast collision check
std::list <WallNode*> walls;  //1d wall ptr list for fast node draw
A_star pathfind;
std::map < std::pair <int, int>, Node*> graph;
HeuristicFunc func = HeuristicFunc::manhattan;
Text ui;

void resetGraph()
{
	for (auto n : graph)
	{
		delete n.second;
	}
	graph.clear();
	pathfind.rebuild();
}

int main()
{
	srand(time(NULL));
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);

	reserveWalls();

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

	//draw visited nodes
	if (!graph.empty())  
	{
		for (auto n : graph)
		{
			n.second->drawNode();
		}
	}

	//draw wall
	for (auto n: walls)  
	{
		n->drawNode();
	}
	start.drawNode();
	goal.drawNode();

	//draw path
	if (!(pathfind.getPath()).empty() && finding == false)  
	{
		for (auto n : pathfind.getPath())
		{
			n->drawNode(1.0f, 1.0f, 0.0f);
		}
		glLineWidth(5.0f);
		glBegin(GL_LINE_STRIP);
		glColor3f(0.5f, 0.0f, 0.5f);
		glVertex2f((start.getX() + 0.5) * field.getScale(), (start.getY() + 0.5) * field.getScale());
		for (auto n : pathfind.getPath())
		{
			glVertex2f((n->getX() + 0.5) * field.getScale(), (n->getY() + 0.5) * field.getScale());
		}
		glVertex2f((goal.getX() + 0.5) * field.getScale(), (goal.getY() + 0.5) * field.getScale());
		glEnd();
		glLineWidth(1.0f);
	}

	field.drawField();
	ui.drawAlgName(25, 40);
	ui.drawNodeCount(35, 100, pathfind.numNodesVisited);
	ui.drawPathLength(80, 175, pathfind.getPath().size());
	ui.drawKeyGuide(-200, 60);
	ui.drawMouseKeyGuide(-235, 225);
	ui.drawActiveHeuristic(300, 50, func);
	ui.drawRenderSpeed(280, 125, slowmode);
	ui.drawAllowDiagonal(320, 200, allowDiagonal);

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