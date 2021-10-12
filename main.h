#ifndef PATHFINDING_VISUALIZER_MAIN_H_
#define PATHFINDING_VISUALIZER_MAIN_H_

#include "Field.h"
#include "GoalNode.h"
#include "StartNode.h"
#include "WallNode.h"
#include "Window.h"

void gameloop(int);
void render();
void update();

extern float DPIscale;  //Windows DPIscale
extern const int kFullWidth, kFullHeight;  //fullscreen window resolution
extern const int kWidth,kHeight;  //default window resolution
extern bool fullscreen;  //window mode

extern const int frametime;  //frametime in milliseconds
extern const int cell_size;  //length of single field cell

extern Window window;
extern Field field;
extern StartNode start;
extern GoalNode goal;
extern WallNode wall;

#endif  // PATHFINDING_VISUALIZER_MAIN_H_