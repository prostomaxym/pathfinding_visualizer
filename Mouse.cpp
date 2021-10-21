#include "Mouse.h"


void ClickMouseHandler(int button, int state, int x, int y)
{
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;
	std::pair <int,int> mouseGet(x / field.getScale(), y / field.getScale());

	if (button == GLUT_LEFT_BUTTON) 
	{
		glutMotionFunc(0);
		if (state == GLUT_DOWN && !intersect(mouseGet))
		{
			resetGraph();
			start.setCoordinates(x / field.getScale(), y / field.getScale());
		}
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		glutMotionFunc(0);
		if (state == GLUT_DOWN && !intersect(mouseGet))
		{
			resetGraph();
			goal.setCoordinates(x / field.getScale(), y / field.getScale());
		}
	}
	else if (button == GLUT_MIDDLE_BUTTON)
	{
		if (state == GLUT_DOWN && !intersect(mouseGet))
		{
			resetGraph();
			wall[y / field.getScale()][x / field.getScale()].setCoordinates(x / field.getScale(), y / field.getScale());
			walls.push_back(&wall[y / field.getScale()][x / field.getScale()]);
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
		wall[y / field.getScale()][x / field.getScale()].setCoordinates(x / field.getScale(), y / field.getScale());
		walls.push_back(&wall[y / field.getScale()][x / field.getScale()]);
	}
}