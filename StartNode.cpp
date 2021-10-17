#include "StartNode.h"

#include "main.h"

void StartNode::drawNode()
{
	glColor3f(r, g, b);
	glRectf(/*x1 point*/this->x_ * field.getScale(), /*y1 point*/this->y_ * field.getScale(),
		/*x2 point*/(this->x_+1)*field.getScale(), /*y2 point*/(this->y_+1) * field.getScale());
}
