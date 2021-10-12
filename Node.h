#ifndef PATHFINDING_VISUALIZER_NODE_H_
#define PATHFINDING_VISUALIZER_NODE_H_

class Node
{
public:
	Node();
	Node(int x, int y);

	virtual void drawNode()=0;
	void setCoordinates(int x, int y);

protected:
	int x_, y_; //node coordinates
};
#endif  // PATHFINDING_VISUALIZER_NODE_H_
