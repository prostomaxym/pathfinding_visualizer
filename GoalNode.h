#ifndef PATHFINDING_VISUALIZER_GOALNODE_H_
#define PATHFINDING_VISUALIZER_GOALNODE_H_

#include <glut.h>

#include "Node.h"

class GoalNode : public Node
{
public:
	using Node::Node;

	void drawNode() override;

private:
	const float r = 1.0f, g = 0.0f, b = 0.0f;  // Node color
};
#endif  // PATHFINDING_VISUALIZER_GOALNODE_H_
