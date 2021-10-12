#include "Mouse.h"

void ClickMouseHandler(int button, int state, int x, int y)
{
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;

	if (button == GLUT_LEFT_BUTTON) 
	{
		glutMotionFunc(0);
		if (state == GLUT_DOWN)
		{
			start.setCoordinates(x / field.getScale(), y / field.getScale());
		}
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		glutMotionFunc(0);
		if (state == GLUT_DOWN)
		{
			goal.setCoordinates(x / field.getScale(), y / field.getScale());
		}
	}
	else if (button == GLUT_MIDDLE_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			glutMotionFunc(MotionMouseHandler);
		}
	}
}

void MotionMouseHandler(int x, int y)
{
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;
	std::pair <int, int> mouseGet(x / field.getScale(), y / field.getScale());

	//ignore creating walls with same coordinates
	if (start.getCoortinates() == mouseGet) return;
	if (goal.getCoortinates() == mouseGet) return;
	for (auto i = 0; i < wall.size(); i++)
	{
		if (wall[i].getCoortinates() == mouseGet) return;
	}
	wall.push_back(WallNode(x / field.getScale(), y / field.getScale()));
}