#ifndef PATHFINDING_VISUALIZER_MAIN_H_
#define PATHFINDING_VISUALIZER_MAIN_H_

#include <vector>

#include "A_star.h"
#include "Field.h"
#include "GoalNode.h"
#include "StartNode.h"
#include "WallNode.h"
#include "Window.h"

void gameloop(int);
void render();
void update();

enum class HeuristicFunc
{
	manhattan,
	euclidean,
	octile,
	chebyshev,
	hZero
};

extern HeuristicFunc func;

extern float DPIscale;  //Windows DPIscale
extern const int kFullWidth, kFullHeight;  //fullscreen window resolution
extern const int kWidth,kHeight;  //default window resolution
extern bool fullscreen;  //window mode
extern int kNumRandWall;  //number of random wall nodes

extern int frametime;  //frametime in milliseconds
extern int cell_size;  //length of single field cell
extern bool finding;  //pathfinding state
extern bool slowmode; //toggle render speed 1X - 5X

extern Window window;
extern Field field;
extern StartNode start;
extern GoalNode goal;
extern std::vector <WallNode> wall;
extern A_star pathfind;
extern std::list <Node*> graph;


bool intersect(std::pair <int, int> coord);
void generateRandomWalls(int number);
#endif  // PATHFINDING_VISUALIZER_MAIN_H_