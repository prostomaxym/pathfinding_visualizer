#ifndef PATHFINDING_VISUALIZER_MOUSE_H_
#define PATHFINDING_VISUALIZER_MOUSE_H_

#include <utility>

#include <glut.h>

#include "main.h"

bool intersect(std::pair <int, int> mouseGet);
void ClickMouseHandler(int button, int state, int x, int y);
void MotionMouseHandler(int x, int y);
#endif  // PATHFINDING_VISUALIZER_MOUSE_H_
