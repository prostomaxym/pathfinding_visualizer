#include "Node.h"

#include "main.h"


Node::Node()
{
	this->x_ = 0;
	this->y_ = 0;

	this->parent = nullptr;
	this->gScore = 9999.0f;  //much bigger than graph max distance - 9999.0f instead of INF
	this->hScore = 9999.0f;  //much bigger than graph max distance - 9999.0f instead of INF
	this->fScore=gScore+hScore;
}

Node::Node(int x, int y)
{
	this->x_ = x;
	this->y_ = y;

	this->parent = nullptr;
	this->gScore = 9999.0f;  //much bigger than  graph max distance - 9999.0f instead of INF
	this->hScore = 9999.0f;  //much bigger than  graph max distance - 9999.0f instead of INF
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

bool Node::operator==(const Node& obj)
{
	return (this->x_==obj.x_) && (this->y_ == obj.y_);
}

void Node::drawNode()
{
	glColor3f(0.0f, 0.7f, 0.95f);
	glRectf(/*x1 point*/this->x_ * field.getScale(), /*y1 point*/this->y_ * field.getScale(),
		/*x2 point*/(this->x_ + 1) * field.getScale(), /*y2 point*/(this->y_ + 1) * field.getScale());
}

void Node::drawNode(float r, float g, float b)
{
	glColor3f(r, g, b);
	glRectf(/*x1 point*/this->x_ * field.getScale(), /*y1 point*/this->y_ * field.getScale(),
		/*x2 point*/(this->x_ + 1) * field.getScale(), /*y2 point*/(this->y_ + 1) * field.getScale());
}

void Node::clear()
{
	this->parent = nullptr;
	this->neighbours.clear();
	this->gScore = 9999.0f;
	this->hScore = 9999.0f;
	this->fScore = gScore + hScore;
}

void Node::setCoordinates(int x, int y)
{
	this->x_ = x;
	this->y_ = y;
}

std::pair <int,int> Node::getCoordinates()
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
	//8 way move direction. 
	int direction[8][2] =
	{
		{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}
	};

	//4 way move direction
	/*int direction[4][2] =
	{
		{-1,0},{0,1},{1,0},{0,-1}
	};*/

	for (int i = 0; i < sizeof(direction)/(2*sizeof(int)); i++)
	{
		//goal reached
		if (goal.getCoordinates() == std::make_pair(x_ + direction[i][0], y_ + direction[i][1]))
		{
			Node* tmp = new Node(x_ + direction[i][0], y_ + direction[i][1]);
			neighbours.push_back(tmp);
			graph.push_back(tmp);
			return this->neighbours;
		}
		//check borders and walls
		if ((x_ + direction[i][0] < 0) 
			|| (y_ + direction[i][1] < 0)  
			|| (x_ + direction[i][0] > glutGet(GLUT_WINDOW_WIDTH) / field.getScale())
			|| (y_ + direction[i][1] > glutGet(GLUT_WINDOW_HEIGHT) / field.getScale())
			|| (intersect(std::make_pair(x_ + direction[i][0], y_ + direction[i][1]))))
		{
			continue;
		}
		//check cornercrossing
		else if (intersect(std::make_pair(x_ + 1, y_)) && intersect(std::make_pair(x_, y_ + 1))
			|| intersect(std::make_pair(x_ + 1, y_)) && intersect(std::make_pair(x_, y_ - 1))
			|| intersect(std::make_pair(x_, y_ - 1)) && intersect(std::make_pair(x_ - 1, y_))
			|| intersect(std::make_pair(x_ - 1, y_)) && intersect(std::make_pair(x_, y_ + 1)))
		{
			continue;
		}

		//all heap alloc instances are deleted looping through graph after path is found
		Node* tmp = new Node(x_ + direction[i][0], y_ + direction[i][1]);
		
		//if node already exists in grapth -  skip creation
		auto alreadyExistIter = std::find_if(graph.begin(), graph.end(),
			[&](const Node* p) {return *tmp == *p; });
		if (alreadyExistIter != graph.end())
		{
			delete tmp;
			continue;
		}
		// if tmp is not already exist in graph - create new neighbour node 
		else
		{
			neighbours.push_back(tmp);
			graph.push_back(tmp);
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