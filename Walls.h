#ifndef PATHFINDING_VISUALIZER_WALLS_H_
#define PATHFINDING_VISUALIZER_WALLS_H_

#include <utility>

bool intersect(std::pair <int, int> coord);
void reserveWalls();
void reserveWalls(int glutWinW, int glutwinH);
void generateRandomWalls(int number);
#endif  // PATHFINDING_VISUALIZER_WALLS_H_
