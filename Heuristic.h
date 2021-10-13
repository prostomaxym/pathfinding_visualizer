#ifndef PATHFINDING_VISUALIZER_HEURISTIC_H_
#define PATHFINDING_VISUALIZER_HEURISTIC_H_

#include <cmath>

#include "Node.h"

class Heuristic
{
public:
	float manhattan(Node* a, Node* b);
	float euclidean(Node* a, Node* b);
	float octile(Node* a, Node* b);
	float chebyshev(Node* a, Node* b);

private:
	float getDX(Node* a, Node* b);
	float getDY(Node* a, Node* b);
};
#endif  // PATHFINDING_VISUALIZER_HEURISTIC_H_
