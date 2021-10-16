#ifndef PATHFINDING_VISUALIZER_STARTNODE_H_
#define PATHFINDING_VISUALIZER_STARTNODE_H_

#include <glut.h>

#include "Node.h"

class StartNode : public Node
{
public:
	using Node::Node;

	void drawNode() override;

private:
	const float r=0.0f, g=1.0f, b=0.0f;  // Node color
};

//extern StartNode startNode;
#endif  // PATHFINDING_VISUALIZER_STARTNODE_H_

