#ifndef PATHFINDING_VISUALIZER_NODE_H_
#define PATHFINDING_VISUALIZER_NODE_H_

#include <list>
#include <utility>

class Node
{
public:
	Node();  //default constructor
	Node(int x, int y);  //init coordinates constructor
	Node(const Node &a);  //copy construstor

	bool operator==(const Node& obj);  //same coordinates comparison

	virtual void drawNode();
	void drawNode(float r, float g, float b);
	void clear();  //reset all fields except coordinates

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

private:
	Node* parent;  //came from node
	std::list <Node*> neighbours;  //surrounding nodes
	float gScore;
	float hScore;
	float fScore;
};
#endif  // PATHFINDING_VISUALIZER_NODE_H_
