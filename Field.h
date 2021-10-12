#ifndef PATHFINDING_VISUALIZER_FIELD_H_
#define PATHFINDING_VISUALIZER_FIELD_H_

#include <glut.h>

//forward declaration
class StartNode;  
class GoalNode;
class WallNode;

class Field
{
public:
	Field();
	Field(int w, int h, int sc);

	void drawField();
	int getScale();
	void resizeField(int w, int h);

private:
	int width, height;
	int scale;
};
#endif  // PATHFINDING_VISUALIZER_FIELD_H_

