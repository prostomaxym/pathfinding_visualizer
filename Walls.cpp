#include "Walls.h"

#include <utility>

#include <glut.h>

#include "main.h"

bool intersect(std::pair <int, int> coord)
{
	if (coord.first < 0 || coord.first >= glutGet(GLUT_WINDOW_WIDTH) / field.getScale()
		|| coord.second < 0 || coord.second >= glutGet(GLUT_WINDOW_HEIGHT) / field.getScale())
		return true;
	if (start.getCoordinates() == coord) return true;
	if (goal.getCoordinates() == coord) return true;
	if (wall[coord.second][coord.first].getCoordinates() == coord) return true;
	return false;
}

void reserveWalls()
{
	int ysize = glutGet(GLUT_WINDOW_HEIGHT) / field.getScale();
	int xsize = glutGet(GLUT_WINDOW_WIDTH) / field.getScale();
	wall.resize(ysize);
	for (size_t i = 0; i < wall.size(); i++)
	{
		wall[i].resize(xsize);
	}
}

void reserveWalls(int glutWinW, int glutwinH)
{
	int ysize = glutwinH / field.getScale();
	int xsize = glutWinW / field.getScale();
	wall.resize(ysize);
	for (size_t i = 0; i < wall.size(); i++)
	{
		wall[i].resize(xsize);
	}
}

void generateRandomWalls(int number)
{
	reserveWalls();
	int ysize = glutGet(GLUT_WINDOW_HEIGHT) / field.getScale();
	int xsize = glutGet(GLUT_WINDOW_WIDTH) / field.getScale();
	int x, y;
	for (int i = 0; i < number; i++)
	{
		x = rand() % xsize;
		y = rand() % ysize;
		if (wall[y][x].getCoordinates() != std::make_pair(x, y))
		{
			wall[y][x].setCoordinates(x, y);
			walls.push_back(&wall[y][x]);
		}
		else i--;
	}
}