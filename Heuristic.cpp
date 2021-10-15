#include "Heuristic.h"

float Heuristic::getDX(Node* A, Node* B)
{
	return A->getX() - B->getX();
}

float Heuristic::getDY(Node* A, Node* B)
{
	return A->getY() - B->getY();
}

float Heuristic::manhattan(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	return dx + dy;
}

float Heuristic::euclidean(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	return sqrt(dx * dx + dy * dy);
}

float Heuristic::octile(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	float F = sqrt(2) - 1;
	return (dx < dy) ? (F * dx + dy ) : (F * dy + dx);
}

float Heuristic::chebyshev(Node* A, Node* B)
{
	float dx = getDX(A, B);
	float dy = getDY(A, B);
	return (dx > dy) ? dx : dy;
}