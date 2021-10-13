#include "Heuristic.h"

float Heuristic::getDX(Node* a, Node* b)
{
	return a->getX() - b->getX();
}
float Heuristic::getDY(Node* a, Node* b)
{
	return a->getY() - b->getY();
}

float Heuristic::manhattan(Node* a, Node* b)
{
	float dx = getDX(a, b);
	float dy= getDY(a, b);
	return dx + dy;
}

float Heuristic::euclidean(Node* a, Node* b)
{
	float dx = getDX(a, b);
	float dy = getDY(a, b);
	return sqrt(dx * dx + dy * dy);
}

float Heuristic::octile(Node* a, Node* b)
{
	float dx = getDX(a, b);
	float dy = getDY(a, b);
	double F = sqrt(2) - 1;
	return (dx < dy) ? (F * dx + dy ) : (F * dy + dx);
}

float Heuristic::chebyshev(Node* a, Node* b)
{
	float dx = getDX(a, b);
	float dy = getDY(a, b);
	return (dx > dy) ? dx : dy;
}