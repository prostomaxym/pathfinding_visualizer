#include "Heuristic.h"

float getDX(Node* A, Node* B)
{
	return A->getX() - B->getX();
}

float getDY(Node* A, Node* B)
{
	return A->getY() - B->getY();
}

float manhattan(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	return abs(dx) + abs(dy);
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
	return (abs(dx) < abs(dy)) ? (F * abs(dx) + abs(dy)) : (F * abs(dy) + abs(dx));
}

float chebyshev(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	return (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
}

//Special case h(x)=0 for turning A* into Dijkstra
float hZero(Node* A, Node* B) 
{
	return NULL;
}