#include <algorithm>
#include <list>
#include <queue>
#include <vector>

#include <glut.h>

#include "A_star.h"
#include "Node.h"
#include "main.h"

A_star::A_star()
{
	numNodesVisited = 0;
	numCostAssign = 0;
	path.clear();
	pq.clear();
	pq.push_back(&start);
	start.setGscore(0);
	start.setFscore();
}

void A_star::rebuild()
{
	numNodesVisited = 0;
	numCostAssign = 0;
	pq.clear();
	path.clear();
	pq.push_back(&start);
	start.setGscore(0);
	start.setFscore();
}

bool A_star::compare_fScore(Node* n1, Node* n2)
{
	if (n1->getFscore() > n2->getFscore())
		return true;
	else
		return false;
}


bool A_star::tick(Node* start, Node* goal, float (*h)(Node*, Node*))
{
	if (*start==*goal) return false;
	start->setHscore(h(goal, start));
	while (!pq.empty())
	{
		Node* current_node = pq.front();
		if (*current_node==*goal)
		{
			goal->setParent(current_node);
			reconstructPath(start, goal);
			return false;
		}
		std::pop_heap(pq.begin(), pq.end(), compare_fScore);
		pq.pop_back();

		for (auto n : current_node->getNeighbours())
		{
			numNodesVisited++;
			float tentative_gScore = current_node->getGscore() + 1; //1 - default graph weight
			if (tentative_gScore < n->getGscore())
			{
				numCostAssign++;
				n->setParent(current_node);
				n->setGscore(tentative_gScore);
				n->setHscore(h(goal, n));
				n->setFscore();
				if (std::find_if(pq.begin(), pq.end(), //check if node is not present in heap
				[&](Node *p) { return *p==*n; }) == pq.end())
				{
					pq.push_back(n);
					std::push_heap(pq.begin(), pq.end(), compare_fScore);
				}
			}
		}
		return true;
	}
	return false;
}

std::list <Node*> A_star::getPath()
{
	return path;
}

void A_star::reconstructPath(Node* start, Node* goal)
{
	Node *current(goal->getParent());
	path.push_back(current);
	while (current != start)
	{
		current = current->getParent();
		path.push_back(current);
	}
	//reverse path, exclude start and goal node
	path.pop_back();
	path.reverse();
	path.pop_back();
}

