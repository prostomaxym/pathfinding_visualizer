#ifndef PATHFINDING_VISUALIZER_ASTAR_H_
#define PATHFINDING_VISUALIZER_ASTAR_H_

#include <list>
#include <queue>
#include <vector>

#include <glut.h>

#include "Node.h"

class A_star
{
public:
	bool Astar(Node* start, Node* goal, float (*h)(Node*, Node*));
	std::list <Node*> getPath();

private:

	std::list <Node*> path;

	static bool compare_fScore(Node* n1, Node* n2);
	void reconstructPath(Node* start, Node* goal);
};
#endif  // PATHFINDING_VISUALIZER_ASTAR_H_
