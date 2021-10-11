#include "Field.h"

Field::Field()
{
	this->width = 1280;
	this->height = 720;
	this->scale = 20;
}

Field::Field(int w, int h, int sc)
{
	this->width = w;
	this->height = h;
	this->scale = sc;
}

void Field::drawField()
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);

	for (int i = 0; i < width; i += scale)
	{
		glVertex2f(i, 0);
		glVertex2f(i, height);
	}

	for (int j = 0; j < height; j += scale)
	{
		glVertex2f(0, j);
		glVertex2f(width, j);
	}
	glEnd();
}