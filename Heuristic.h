#ifndef PATHFINDING_VISUALIZER_HEURISTIC_H_
#define PATHFINDING_VISUALIZER_HEURISTIC_H_

#include <cmath>

class Heuristic
{
public:
	double manhattan(int dx, int dy);
	double euclidean(int dx, int dy);
	double octile(int dx, int dy);
	double chebyshev(int dx, int dy);
};
#endif  // PATHFINDING_VISUALIZER_HEURISTIC_H_
