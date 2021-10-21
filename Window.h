#ifndef PATHFINDING_VISUALIZER_WINDOW_H_
#define PATHFINDING_VISUALIZER_WINDOW_H_

#include <string>

class Window
{
public:
	Window();
	Window(int w, int h, std::string winname);

	void enterFullscreen(int w, int h);
	void leaveFullscreen(int w, int h);

private:
	int width, height; //window resolution
	std::string window_name;
};
#endif  // PATHFINDING_VISUALIZER_WINDOW_H_

