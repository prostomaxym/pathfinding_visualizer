#include "Node.h"

#include "main.h"

Node::Node()
{
	this->x_ = 0;
	this->y_ = 0;

	this->parent=nullptr;
	this->gScore = 9999.0f;
	this->hScore = 9999.0f;
	this->fScore=gScore+hScore;
}

Node::Node(int x, int y)
{
	this->x_ = x;
	this->y_ = y;

	this->parent = nullptr;
	this->gScore = 9999.0f;
	this->hScore = 9999.0f;
	this->fScore = gScore + hScore;
}

Node::Node(const Node &a)
{
	this->x_ = a.x_;
	this->y_ = a.y_;
	this->parent=a.parent;
	this->neighbours = a.neighbours;
	this->gScore=a.gScore;
	this->hScore = a.hScore;
	this->fScore = a.fScore;
}

Node::Node(const Node* a)
{
	this->x_ = a->x_;
	this->y_ = a->y_;
	this->parent = a->parent;
	this->neighbours = a->neighbours;
	this->gScore = a->gScore;
	this->hScore = a->hScore;
	this->fScore = a->fScore;
}

void Node::drawNode()
{
	glColor3f(0.8f, 0.8f, 0.8f);
	glRectf(/*x1 point*/this->x_ * field.getScale(), /*y1 point*/this->y_ * field.getScale(),
		/*x2 point*/(this->x_ + 1) * field.getScale(), /*y2 point*/(this->y_ + 1) * field.getScale());
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

std::list <Node*> Node::getNeighbours()
{
	/*int direction[8][2] =    //8 way move direction
	{
		{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}
	};*/

	int direction[4][2] =
	{
		{-1,0},{0,1},{1,0},{0,-1}
	};

	for (int i = 0; i < 4; i++)
	{
		if (goal.getCoortinates() == std::make_pair(x_ + direction[i][0], y_ + direction[i][1]))
		{
			neighbours.push_back(new Node(x_ + direction[i][0], y_ + direction[i][1]));
		}
		else if (!intersect(std::make_pair(x_ + direction[i][0], y_ + direction[i][1]))) //check walls
		{
			if ((x_ + direction[i][0] >= 0 && y_ + direction[i][1]>=0)  //check borders
				&& x_ + direction[i][0] <= glutGet(GLUT_WINDOW_WIDTH) / field.getScale()
				&& y_ + direction[i][1] <= glutGet(GLUT_WINDOW_HEIGHT) / field.getScale())
			{
				neighbours.push_back(new Node(x_ + direction[i][0], y_ + direction[i][1]));
			}
		}
	}
	return this->neighbours;
}

void Node::setParent(Node* A)
{
	this->parent = A;
}

void Node::setGscore(float g)
{
	this->gScore = g;
}

void Node::setHscore(float h)
{
	this->hScore = h;
}

void Node::setFscore()
{
	this->fScore = gScore+hScore;
}

Node* Node::getParent()
{
	return this->parent;
}

float Node::getGscore()
{
	return this->gScore;
}

float Node::getHscore()
{
	return this->hScore;
}

float Node::getFscore()
{
	return this->fScore;
}

bool Node::operator==(const Node* A)
{
	if ((this->x_ == A->x_) && (this->y_ == A->y_))
	{
		return true;
	}
	else return false;
}