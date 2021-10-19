#ifndef PATHFINDING_VISUALIZER_KEYBOARD_H_
#define PATHFINDING_VISUALIZER_KEYBOARD_H_

#include <random>
#include <list>
#include <utility>

#include <glut.h>

#include "A_star.h"
#include "Field.h"
#include "Heuristic.h"
#include "main.h"
#include "Mouse.h"
#include "WallNode.h"
#include "Window.h"

void PressKeyHandler(unsigned char key, int x, int y);
void ReleaseKeyHandler(unsigned char key, int x, int y);
#endif  // PATHFINDING_VISUALIZER_KEYBOARD_H_
