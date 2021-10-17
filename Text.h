#ifndef PATHFINDING_VISUALIZER_TEXT_H_
#define PATHFINDING_VISUALIZER_TEXT_H_

#include <string>
#include "main.h"

class Text
{
public:
	void drawAlgName(int x, int y); //Bind to left top corner
	void drawNodeCount(float x, float y, int count); //Bind to top left  corner
	void drawCostCount(float x, float y, int count); //Bind to top left  corner
	void drawKeyGuide(int x, int y); //Bind to top center 
	void drawActiveHeuristic(int x, int y, HeuristicFunc h); //Bind to top right  corner
	void drawRenderSpeed(int x, int y, bool slow); ////Bind to top right corner

private:
	void glWrite(float x, float y, int* font, std::string text);
};
#endif  // PATHFINDING_VISUALIZER_TEXT_H_