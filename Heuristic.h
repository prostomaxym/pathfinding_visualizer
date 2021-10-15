#ifndef PATHFINDING_VISUALIZER_HEURISTIC_H_
#define PATHFINDING_VISUALIZER_HEURISTIC_H_

#include <cmath>

#include "Node.h"

class Heuristic
{
public:
	float manhattan(Node* A, Node* B);
	float euclidean(Node* A, Node* B);
	float octile(Node* A, Node* B);
	float chebyshev(Node* A, Node* B);
	
private:
	float getDX(Node* A, Node* B);
	float getDY(Node* A, Node* B);
}func;
#endif  // PATHFINDING_VISUALIZER_HEURISTIC_H_
