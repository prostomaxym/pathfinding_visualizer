#ifndef PATHFINDING_VISUALIZER_ASTAR_H_
#define PATHFINDING_VISUALIZER_ASTAR_H_

#include <list>
#include <queue>
#include <vector>

#include <glut.h>

#include "Node.h"

float d(Node* A, Node* B);

class A_star
{
public:
	int numNodesVisited;  //number of nodes visited

	A_star();
	void rebuild();

	bool tick(Node* start, Node* goal, float (*h)(Node*, Node*)); //h - Heuristic function
	std::list <Node*> getPath();

private:
	std::vector <Node*> pq;  //priority queue or min heap
	std::list <Node*> path; //final path from star to goal

	static bool compare_fScore(Node* n1, Node* n2);
	void reconstructPath(Node* start, Node* goal);
};
#endif  // PATHFINDING_VISUALIZER_ASTAR_H_
