#include "Text.h"

#include <glut.h>

#include "main.h"

void Text::glWrite(float x, float y, int* font, std::string text)
{
	glRasterPos2f(x, y);
	for (unsigned i = 0; i < text.size(); i++)
		glutBitmapCharacter(font, (int)text[i]);
}

void Text::drawAlgName(int x, int y)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(x, glutGet(GLUT_WINDOW_HEIGHT) - y - 12, x + 150, glutGet(GLUT_WINDOW_HEIGHT) - y + 24);

	glColor3f(1.0f, 0.4f, 0.3f);
	this->glWrite(x, glutGet(GLUT_WINDOW_HEIGHT)-y,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "A* Pathfinding");
}

void Text::drawNodeCount(float x, float y, int count)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(x, glutGet(GLUT_WINDOW_HEIGHT) - y - 40, x + 250, glutGet(GLUT_WINDOW_HEIGHT) - y + 24);

	glColor3f(0.2f, 0.2f, 0.2f);
	this->glWrite(x, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Number of nodes visited:");

	glColor3f(0.4f, 0.3f, 0.8f);
	this->glWrite(x + 100, glutGet(GLUT_WINDOW_HEIGHT) - y - 30,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(count));
}

void Text::drawPathLength(float x, float y, int count)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(x, glutGet(GLUT_WINDOW_HEIGHT) - y - 40, x + 120, glutGet(GLUT_WINDOW_HEIGHT) - y + 24);

	glColor3f(0.2f, 0.2f, 0.2f);
	this->glWrite(x, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Path length:");

	glColor3f(0.4f, 0.3f, 0.8f);
	this->glWrite(x + 50, glutGet(GLUT_WINDOW_HEIGHT) - y - 30,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(count));
}

void Text::drawKeyGuide(int x, int y)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(glutGet(GLUT_WINDOW_WIDTH) / 2 + x - 100, glutGet(GLUT_WINDOW_HEIGHT) - y - 135, 
		glutGet(GLUT_WINDOW_WIDTH) / 2 + x + 450, glutGet(GLUT_WINDOW_HEIGHT) - y + 24);

	glColor3f(0.2f, 0.2f, 0.2f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH)/2 + x - 100, glutGet(GLUT_WINDOW_HEIGHT) - y - 37,
		(int*)GLUT_BITMAP_HELVETICA_18, "Key Guide:");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_HELVETICA_18, "A - Start pathfinding");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x, glutGet(GLUT_WINDOW_HEIGHT) - y - 25,
		(int*)GLUT_BITMAP_HELVETICA_18, "W - Generate random walls");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x, glutGet(GLUT_WINDOW_HEIGHT) - y - 50,
		(int*)GLUT_BITMAP_HELVETICA_18, "E - Clear walls");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x, glutGet(GLUT_WINDOW_HEIGHT) - y - 75,
		(int*)GLUT_BITMAP_HELVETICA_18, "R - Stop pathfinding");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x, glutGet(GLUT_WINDOW_HEIGHT) - y - 100,
		(int*)GLUT_BITMAP_HELVETICA_18, "F - Enter/Exit fullscreen");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x, glutGet(GLUT_WINDOW_HEIGHT) - y - 125,
		(int*)GLUT_BITMAP_HELVETICA_18, "D - Allow diagonal movement");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x + 250, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_HELVETICA_18, "1 - Manhattan heuristic");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x + 250, glutGet(GLUT_WINDOW_HEIGHT) - y - 25,
		(int*)GLUT_BITMAP_HELVETICA_18, "2 - Euclidean heuristic");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x + 250, glutGet(GLUT_WINDOW_HEIGHT) - y - 50,
		(int*)GLUT_BITMAP_HELVETICA_18, "3 - Octile heuristic");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x + 250, glutGet(GLUT_WINDOW_HEIGHT) - y - 75,
		(int*)GLUT_BITMAP_HELVETICA_18, "4 - Chebyshev heuristic");
	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x + 250, glutGet(GLUT_WINDOW_HEIGHT) - y - 100,
		(int*)GLUT_BITMAP_HELVETICA_18, "5 - h(x)=0 heuristic");
}

void Text::drawMouseKeyGuide(int x, int y)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(glutGet(GLUT_WINDOW_WIDTH) / 2 + x - 80, glutGet(GLUT_WINDOW_HEIGHT) - y - 10,
		glutGet(GLUT_WINDOW_WIDTH) / 2 + x + 500, glutGet(GLUT_WINDOW_HEIGHT) - y + 25);

	glColor3f(0.2f, 0.2f, 0.2f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x - 75, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_HELVETICA_18, "Mouse:");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_HELVETICA_18, "LMB - Place start");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x + 175, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_HELVETICA_18, "MMB - Place wall");

	glColor3f(0.1f, 0.1f, 0.9f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) / 2 + x + 350, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_HELVETICA_18, "RMB - Place goal");
}
void Text::drawActiveHeuristic(int x, int y, HeuristicFunc h)
{
	std::string enumStr;
	switch (h)
	{
	case HeuristicFunc::manhattan:
		enumStr = "Manhattan";
		break;
	case HeuristicFunc::euclidean:
		enumStr = "Euclidean";
		break;
	case HeuristicFunc::octile:
		enumStr = "Octile";
		break;
	case HeuristicFunc::chebyshev:
		enumStr = "Chebyshev";
		break;
	case HeuristicFunc::hZero:
		enumStr = "Dijkstra case";
		break;
	}

	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(glutGet(GLUT_WINDOW_WIDTH) - x, glutGet(GLUT_WINDOW_HEIGHT) - y - 35,
		glutGet(GLUT_WINDOW_WIDTH) - x + 180, glutGet(GLUT_WINDOW_HEIGHT) - y + 24);

	glColor3f(0.2f, 0.2f, 0.2f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) - x, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Selected heuristic:");

	glColor3f(0.4f, 0.3f, 0.8f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) - x + 40, glutGet(GLUT_WINDOW_HEIGHT) - y - 30,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, enumStr);
}

void Text::drawRenderSpeed(int x, int y, bool slow)
{
	std::string mode(slow? "5X":"1X");

	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(glutGet(GLUT_WINDOW_WIDTH) - x, glutGet(GLUT_WINDOW_HEIGHT) - y - 35,
		glutGet(GLUT_WINDOW_WIDTH) - x + 130, glutGet(GLUT_WINDOW_HEIGHT) - y + 24);

	glColor3f(0.2f, 0.2f, 0.2f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) - x, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Update time");

	glColor3f(0.4f, 0.3f, 1.0f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) - x + 50, glutGet(GLUT_WINDOW_HEIGHT) - y - 30,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, mode);

}

void Text::drawAllowDiagonal(int x, int y, bool diag)
{
	std::string mode(diag ? "TRUE" : "FALSE");

	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(glutGet(GLUT_WINDOW_WIDTH) - x, glutGet(GLUT_WINDOW_HEIGHT) - y - 35,
		glutGet(GLUT_WINDOW_WIDTH) - x + 270, glutGet(GLUT_WINDOW_HEIGHT) - y + 24);

	glColor3f(0.2f, 0.2f, 0.2f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) - x, glutGet(GLUT_WINDOW_HEIGHT) - y,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Allow diagonal movement");

	glColor3f(0.4f, 0.3f, 1.0f);
	this->glWrite(glutGet(GLUT_WINDOW_WIDTH) - x + 80, glutGet(GLUT_WINDOW_HEIGHT) - y - 30,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, mode);
}
