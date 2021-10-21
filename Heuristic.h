#ifndef PATHFINDING_VISUALIZER_HEURISTIC_H_
#define PATHFINDING_VISUALIZER_HEURISTIC_H_

#include "Node.h"

	float getDX(Node* A, Node* B);
	float getDY(Node* A, Node* B);

	float manhattan(Node* A, Node* B);
	float euclidean(Node* A, Node* B);
	float octile(Node* A, Node* B);
	float chebyshev(Node* A, Node* B);
	float hZero(Node* A, Node* B);

#endif  // PATHFINDING_VISUALIZER_HEURISTIC_H_
