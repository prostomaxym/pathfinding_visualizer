#include "A_star.h"

struct nodeDistance
{
	Node* node;
	float distance;
};

class CompareDist
{
public:
	bool operator()(nodeDistance& n1, nodeDistance& n2)
	{
		if (n1.distance > n2.distance)
			return true;
		else
			return false;
	}
};

std::list <Node*> A_star(Node* start, Node* goal, Heuristic func)
{
	std::priority_queue <nodeDistance, std::vector< nodeDistance>, CompareDist> pq;
	std::vector <Node*> cameFrom;
	std::vector <float> costTotal;
	const int kXCellNum = glutGet(GLUT_SCREEN_WIDTH) / field.getScale();
	const int kYCellNum = glutGet(GLUT_SCREEN_WIDTH) / field.getScale();

	nodeDistance first;
	first.node = start;
	first.distance = 0.0f;
	pq.push(first);

	costTotal.resize(kXCellNum * kYCellNum);
	costTotal[start->getX() + kYCellNum * start->getY()] = 0.0f;

	int i = 0;
	while (!pq.empty())
	{
		nodeDistance temp = pq.top();
		pq.pop();
		Node* current_node = temp.node;
		//current_node = get_node(current_node->getX(), current_node->getY());

		if (current_node == goal) break;

		for (auto n : current_node->getNeighbours())
		{
			float new_cost = costTotal[current_node->getX() + kYCellNum * current_node->getY()] + n->getCost();

			if (new_cost < costTotal[n->getX() + kYCellNum * n->getY()])
			{
				costTotal[n->getX() + kYCellNum * n->getY()] = new_cost;
				cameFrom[n->getX() + kYCellNum * n->getY()] = current_node;

				nodeDistance newNode;
				newNode.node = n;
				newNode.distance = new_cost + func.manhattan(n, goal);
				pq.push(newNode);
			}
		}
	}
	
	Node* current = new Node();
	current = goal;
	std::list<Node*> path;
	path.push_back(current);
	while (current != start)
	{
		current = cameFrom[current->getX() + kYCellNum * current->getY()];

		path.push_back(current);
	}
	path.reverse();

	return path;
}
