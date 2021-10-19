#include "Node.h"

#include "main.h"

Node::Node()
{
	this->x_ = 0;
	this->y_ = 0;

	this->parent=nullptr;
	this->gScore = 9999.0f;  //much bigger than  graph max distance - 9999.0f instead of INF
	this->hScore = 9999.0f;  //much bigger than  graph max distance - 9999.0f instead of INF
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

bool Node::operator==(Node & obj)
{
	return this->getCoordinates()==obj.getCoordinates();
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
	std::list <Node*> previous_neighbours;
	if (parent!= NULL)
	{
		previous_neighbours = std::list<Node*>(parent->neighbours);
	}

	for (int i = 0; i < sizeof(direction)/(2*sizeof(int)); i++)
	{
		//check cornercrossing
		if (intersect(std::make_pair(x_ + 1, y_)) && intersect(std::make_pair(x_, y_ + 1))
			|| intersect(std::make_pair(x_ + 1, y_)) && intersect(std::make_pair(x_, y_ - 1))
			|| intersect(std::make_pair(x_, y_ - 1)) && intersect(std::make_pair(x_ - 1, y_))
			|| intersect(std::make_pair(x_ - 1, y_)) && intersect(std::make_pair(x_, y_ + 1)))
		{
			continue;
		}

		Node *tmp = new Node(x_ + direction[i][0], y_ + direction[i][1]);
		graph.push_back(tmp);  //all heap alloc instances are deleted looping through graph after path is found

		if (goal.getCoordinates() == std::make_pair(x_ + direction[i][0], y_ + direction[i][1]))
		{
			neighbours.push_back(tmp);
			return this->neighbours;
		}
		else if ((x_ + direction[i][0] >= 0 && y_ + direction[i][1] >= 0)  //check borders
			&& x_ + direction[i][0] <= glutGet(GLUT_WINDOW_WIDTH) / field.getScale()
			&& y_ + direction[i][1] <= glutGet(GLUT_WINDOW_HEIGHT) / field.getScale()
			&& !intersect(std::make_pair(x_ + direction[i][0], y_ + direction[i][1])))  //check walls
		{
			if (parent == NULL)
			{
				neighbours.push_back(tmp);
			}
			// if tmp is not present in parent node's neighbours - create new neighbour node 
			// otherwise - splice neighbour address from parent to this
			else if (std::find_if(previous_neighbours.begin(), previous_neighbours.end(), 
				[&](Node* p) { return *p == *tmp; }) == previous_neighbours.end())
			{
				neighbours.push_back(tmp);
			}
			else
			{
				//splice neighbour node address from parent to child and delete in parent node
				neighbours.splice(neighbours.end(), previous_neighbours, 
					std::find_if(previous_neighbours.begin(), previous_neighbours.end(),
					[&](Node* p) { return *p == *tmp; }));

				delete tmp; //avoid dublicating nodes
				graph.pop_back();
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