#include "Keyboard.h"

void PressKeyHandler(unsigned char key, int x, int y)
{

}

void ReleaseKeyHandler(unsigned char key, int x, int y)
{
	if (key == 'f')
	{
		if (fullscreen)
		{
			//glutReshapeWindow(w, h);
			fullscreen = false;
		}
		else
		{
			glutFullScreen();
			fullscreen = true;
		}
	}
}