#include "Mouse.h"

bool intersect(std::pair <int, int> mouseGet)
{
	if (start.getCoortinates() == mouseGet) return true;
	if (goal.getCoortinates() == mouseGet) return true;
	for (size_t i = 0; i < wall.size(); i++)
	{
		if (wall[i].getCoortinates() == mouseGet) return true;
	}
	return false;
}

void ClickMouseHandler(int button, int state, int x, int y)
{
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;
	std::pair <int,int> mouseGet(x / field.getScale(), y / field.getScale());

	if (button == GLUT_LEFT_BUTTON) 
	{
		glutMotionFunc(0);
		if (state == GLUT_DOWN && !intersect(mouseGet))
		{
			start.setCoordinates(x / field.getScale(), y / field.getScale());
		}
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		glutMotionFunc(0);
		if (state == GLUT_DOWN && !intersect(mouseGet))
		{
			goal.setCoordinates(x / field.getScale(), y / field.getScale());
		}
	}
	else if (button == GLUT_MIDDLE_BUTTON)
	{
		if (state == GLUT_DOWN && !intersect(mouseGet))
		{
			wall.push_back(WallNode(x / field.getScale(), y / field.getScale()));
			glutMotionFunc(MotionMouseHandler);
		}
	}
}

void MotionMouseHandler(int x, int y)
{
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;
	std::pair <int, int> mouseGet(x / field.getScale(), y / field.getScale());

	if (!intersect(mouseGet))
	{
		wall.push_back(WallNode(x / field.getScale(), y / field.getScale()));
	}
}