#ifndef PATHFINDING_VISUALIZER_ASTAR_H_
#define PATHFINDING_VISUALIZER_ASTAR_H_

#include <list>
#include <queue>
#include <vector>

#include <glut.h>

#include "Heuristic.h"
#include "Node.h"
#include "main.h"

struct nodeDistance;
class CompareDist;
std::list <Node*> A_star(Node* start, Node* goal, Heuristic func);
#endif  // PATHFINDING_VISUALIZER_ASTAR_H_