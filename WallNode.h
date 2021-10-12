#ifndef PATHFINDING_VISUALIZER_WALLNODE_H_
#define PATHFINDING_VISUALIZER_WALLNODE_H_

#include <glut.h>

#include "Field.h"
#include "main.h"
#include "Node.h"

class WallNode : public Node
{
public:
	using Node::Node;

	void drawNode() override;

private:
	const float r = 0.1f, g = 0.1f, b = 0.1f;  // Node color
};
#endif  // PATHFINDING_VISUALIZER_WALLNODE_H_

