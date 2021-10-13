#ifndef PATHFINDING_VISUALIZER_NODE_H_
#define PATHFINDING_VISUALIZER_NODE_H_

#include <list>
#include <utility>

class Node
{
public:
	Node();
	Node(int x, int y);

	virtual void drawNode();
	void setCoordinates(int x, int y);
	std::pair <int, int> getCoortinates();
	int getX();
	int getY();
	float getCost();
	std::list <Node*> getNeighbours();

protected:
	int x_, y_; //node coordinates
	float cost;
	Node* parent;
	std::list <Node*> neighbours;
};
#endif  // PATHFINDING_VISUALIZER_NODE_H_
