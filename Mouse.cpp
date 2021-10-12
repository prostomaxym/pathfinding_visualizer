#include "Mouse.h"

void mouseHandler(int button, int state, int x, int y)
{
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;
	if (button == GLUT_LEFT_BUTTON) 
	{
		if (state == GLUT_UP) 
		{

		}
		else  // state = GLUT_DOWN
		{
			startNode.setCoordinates(x/field.getScale(), y/ field.getScale());
		}
	}
}