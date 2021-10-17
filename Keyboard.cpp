#include "Keyboard.h"

void resetGraph()
{
	while (!graph.empty())
	{
		delete graph.back(), graph.pop_back();
	}
}

void PressKeyHandler(unsigned char key, int x, int y)
{
	if (finding && key == 'r')
	{
		resetGraph();
		pathfind.rebuild();
		finding = false;
	}
	else 
	{
		switch (key)
		{
		case 'e':
			resetGraph();
			wall.clear();
			break;
		case 'w':
			wall.clear();
			generateRandomWalls(kNumRandWall);
			resetGraph();
			break;
		case 'a':
			resetGraph();
			pathfind.rebuild();
			finding = true;
			break;
		case 'r':
			resetGraph();
			pathfind.rebuild();
			finding = false;
			break;
		case 49:
			resetGraph();
			pathfind.rebuild();
			func = HeuristicFunc::manhattan;
			break;
		case 50:
			resetGraph();
			pathfind.rebuild();
			func = HeuristicFunc::euclidean;
			break;
		case 51:
			resetGraph();
			pathfind.rebuild();
			func = HeuristicFunc::octile;
			break;
		case 52:
			resetGraph();
			pathfind.rebuild();
			func = HeuristicFunc::chebyshev;
			break;
		case 53:
			resetGraph();
			pathfind.rebuild();
			func = HeuristicFunc::hZero;
			break;
		}
	}
}

void ReleaseKeyHandler(unsigned char key, int x, int y)
{
	if (key == 'f')
	{
		finding = false;
		resetGraph();
		wall.clear();
		pathfind.rebuild();
		start.setCoordinates(0, 0);
		goal.setCoordinates(0, 0);
		if (fullscreen)
		{
			fullscreen = false;
			window.enterFullscreen(kWidth, kHeight);
			field.resizeField(kWidth, kHeight);
		}
		else
		{
			fullscreen = true;
			window.leaveFullscreen(kFullWidth, kFullHeight);
			field.resizeField(kFullWidth, kFullHeight);
		}
	}

	if (key == 's')
	{
		if (slowmode)
		{
			frametime /= 5;
			slowmode = false;
		}
		else
		{
			frametime *= 5;
			slowmode = true;
		}
	}
}