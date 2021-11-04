# Pathfinding visualization
A* pathfinding  OpenGL/GLut based visualizer.
Video demo: https://youtu.be/5dhX0XH9LMA.

## Features made:
* Simple customizable pathfinding visualization engine.
* A* pathfinding algorithm.
* 2D raster text UI.
* Keyboard and mouse driven control.
* 5 Heuristic functions (Manhattan, Euclidean, Octile, Chebyshev, h(x)=0 "Dijkstra case").

## Implementation details:
* Start, goal, walls nodes are constructed before pathfinding.
* Graph (blank nodes) is constructed dynamically during pathfinding.
* Visited nodes are contained in std::map with O(log(n)) time for new nodes visiting and existing nodes revisiting.
* Wall collision detection in O(1) time.

## Tools used:
* C++, STL.
* OpenGL/GLUT.
