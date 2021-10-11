#ifndef PATHFINDING_VISUALIZER_FIELD_H_
#define PATHFINDING_VISUALIZER_FIELD_H_

#include <glut.h>

class Field
{
public:
	Field();
	Field(int w, int h, int sc);
	void drawField();

private:
	int width, height;
	int scale;
};
#endif  // PATHFINDING_VISUALIZER_FIELD_H_

