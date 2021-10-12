#include "Keyboard.h"

void PressKeyHandler(unsigned char key, int x, int y)
{
	if (key == 'r')
	{
		wall.clear();
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