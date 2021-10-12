#include "Mouse.h"

void mouseHandler(int button, int state, int x, int y)
{
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;

	if (button == GLUT_LEFT_BUTTON) 
	{
		if (state == GLUT_DOWN)
		{
			start.setCoordinates(x / field.getScale(), y / field.getScale());
		}
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			goal.setCoordinates(x / field.getScale(), y / field.getScale());
		}
	}
	else if (button == GLUT_MIDDLE_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			wall.setCoordinates(x / field.getScale(), y / field.getScale());
		}
	}
}