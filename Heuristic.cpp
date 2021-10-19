#include "Heuristic.h"

float getDX(Node* A, Node* B)
{
	return abs(A->getX() - B->getX());
}

float getDY(Node* A, Node* B)
{
	return abs(A->getY() - B->getY());
}

float manhattan(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	return dx + dy;
}

float euclidean(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	return sqrt(dx * dx + dy * dy);
}

float octile(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	float F = sqrt(2) - 1;
	return (dx < dy) ? (F * dx + dy) : (F * dy + dx);
}

float chebyshev(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	return (dx > dy) ? dx : dy;
}

//Special case h(x)=0 for turning A* into Dijkstra
float hZero(Node* A, Node* B) 
{
	return NULL;
}