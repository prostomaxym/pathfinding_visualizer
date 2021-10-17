#include <algorithm>
#include <list>
#include <queue>
#include <vector>

#include <glut.h>

#include "A_star.h"
#include "Node.h"
#include "main.h"

bool A_star::compare_fScore(Node* n1, Node* n2)
{
	if (n1->getFscore() > n2->getFscore())
		return true;
	else
		return false;
}


bool A_star::Astar(Node* start, Node* goal, float (*h)(Node*, Node*))
{
	std::vector <Node*> pq;

	start->setGscore(0);
	start->setHscore(h(goal, start));
	start->setFscore();
	pq.push_back(start);

	while (!pq.empty())
	{
		Node* current_node = pq.front();
		if (current_node->getCoordinates() == goal->getCoordinates())
		{
			goal->setParent(current_node);
			reconstructPath(start, goal);
			return true;
		}
		std::pop_heap(pq.begin(), pq.end(), compare_fScore);
		pq.pop_back();
		for (auto n : current_node->getNeighbours())
		{
			float tentative_gScore = current_node->getGscore() + 1; //1 - default graph weight
			if (tentative_gScore < n->getGscore())
			{
				n->setParent(current_node);
				n->setGscore(tentative_gScore);
				n->setHscore(h(goal, n));
				n->setFscore();
				if (std::find_if(pq.begin(), pq.end(), //check if node already present in heap
					[&](Node * p) { return p->getCoordinates()==n->getCoordinates(); }) == pq.end())
				{
					pq.push_back(n);
					std::push_heap(pq.begin(), pq.end(), compare_fScore);
				}
			}
		}
	}
	return false;
}

std::list <Node*> A_star::getPath()
{
	return path;
}

void A_star::reconstructPath(Node* start, Node* goal)
{
	path.clear();
	Node *current(goal->getParent());
	path.push_back(current);
	while (current != start)
	{
		current = current->getParent();
		path.push_back(current);
	}
	path.reverse();
	path.pop_back();
}

