#ifndef PATHFINDING_VISUALIZER_FIELD_H_
#define PATHFINDING_VISUALIZER_FIELD_H_

#include <glut.h>

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

extern Field field;
#endif  // PATHFINDING_VISUALIZER_FIELD_H_

