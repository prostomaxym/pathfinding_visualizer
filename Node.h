#ifndef PATHFINDING_VISUALIZER_NODE_H_
#define PATHFINDING_VISUALIZER_NODE_H_

#include <utility>
#include <list>


class Node
{
public:
	Node();
	Node(int x, int y);
	Node(const Node &a);

	bool operator==(Node & obj);

	virtual void drawNode();
	void drawNode(float r, float g, float b);

	void setCoordinates(int x, int y);
	void setParent(Node* A);
	void setGscore(float g);
	void setHscore(float h);
	void setFscore();

	std::pair <int, int> getCoordinates();
	int getX();
	int getY();
	Node* getParent();
	std::list <Node*> getNeighbours();
	float getGscore();
	float getHscore();
	float getFscore();

protected:
	int x_, y_;  //node coordinates
	Node* parent;  //came from node
	std::list <Node*> neighbours;  //surrounding nodes
	float gScore;
	float hScore;
	float fScore;
};
#endif  // PATHFINDING_VISUALIZER_NODE_H_
