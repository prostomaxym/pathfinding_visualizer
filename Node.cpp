#include "Node.h"

Node::Node()
{
	this->x_ = 0;
	this->y_ = 0;
}

Node::Node(int x, int y)
{
	this->x_ = x;
	this->y_ = y;
}

void Node::setCoordinates(int x, int y)
{
	this->x_ = x;
	this->y_ = y;
}

std::pair <int,int> Node::getCoortinates()
{
	std::pair <int, int> coord(this->x_, this->y_);
	return coord;
}