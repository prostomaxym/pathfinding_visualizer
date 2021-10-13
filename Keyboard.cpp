#include "Keyboard.h"

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

void PressKeyHandler(unsigned char key, int x, int y)
{
	if (key == 'r')
	{
		wall.clear();
	}
	if (key == 'a')
	{
		wall.clear();
		generateRandomWalls(kNumRandWall);
	}
}

void ReleaseKeyHandler(unsigned char key, int x, int y)
{
	if (key == 'f')
	{
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
}