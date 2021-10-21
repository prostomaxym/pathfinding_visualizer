#include "Keyboard.h"

void PressKeyHandler(unsigned char key, int x, int y)
{
	if (finding && key == 'r')
	{
		resetGraph();
		finding = false;
	}
	else 
	{
		switch (key)
		{
		case 'e':
			resetGraph();
			wall.clear();
			walls.clear();
			reserveWalls();
			break;
		case 'w':
			wall.clear();
			walls.clear();
			generateRandomWalls(kNumRandWall);
			resetGraph();
			break;
		case 'a':
			resetGraph();
			finding = true;
			break;
		case 'r':
			resetGraph();
			finding = false;
			break;
		case 49:
			resetGraph();
			func = HeuristicFunc::manhattan;
			break;
		case 50:
			resetGraph();
			func = HeuristicFunc::euclidean;
			break;
		case 51:
			resetGraph();
			func = HeuristicFunc::octile;
			break;
		case 52:
			resetGraph();
			func = HeuristicFunc::chebyshev;
			break;
		case 53:
			resetGraph();
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
		walls.clear();
		start.setCoordinates(0, 0);
		goal.setCoordinates(0, 0);
		if (fullscreen)
		{
			fullscreen = false;
			window.leaveFullscreen(kWidth, kHeight);
			field.resizeField(kWidth, kHeight);
			reserveWalls(kWidth, kHeight);
		}
		else
		{
			fullscreen = true;
			window.enterFullscreen(kFullWidth, kFullHeight);
			field.resizeField(kFullWidth, kFullHeight);	
			reserveWalls(kFullWidth, kFullHeight);
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