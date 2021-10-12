#ifndef PATHFINDING_VISUALIZER_NODE_H_
#define PATHFINDING_VISUALIZER_NODE_H_

#include <utility>

class Node
{
public:
	Node();
	Node(int x, int y);

	virtual void drawNode()=0;
	void setCoordinates(int x, int y);
	std::pair <int, int> getCoortinates();

protected:
	int x_, y_; //node coordinates
};
#endif  // PATHFINDING_VISUALIZER_NODE_H_
