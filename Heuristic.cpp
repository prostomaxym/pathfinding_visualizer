#include "Heuristic.h"

double Heuristic::manhattan(int dx, int dy)
{
	return dx + dy;
}

double Heuristic::euclidean(int dx, int dy)
{
	return sqrt(dx * dx + dy * dy);
}

double Heuristic::octile(int dx, int dy)
{
	double F = sqrt(2) - 1;
	return (dx < dy) ? (F * dx + dy ) : (F * dy + dx);
}

double Heuristic::octile(int dx, int dy)
{
	return (dx > dy) ? dx : dy;
}