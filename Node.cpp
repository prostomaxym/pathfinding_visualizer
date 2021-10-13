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

void Node::drawNode()
{

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

int Node::getX()
{
	return this->x_;
}

int Node::getY()
{
	return this->y_;
}

float Node::getCost()
{
	return this->cost;
}

std::list <Node*> Node::getNeighbours()
{
	return this->neighbours;
}