# pathfinding_visualizer
A* pathfinding  OpenGL/GLut based visualizer.

Features made:

* Simple customizable pathfinding visualization engine.
* A* pathfinding algorithm.
* 2D raster text UI.
* Keyboard and mouse driven control.
* 5 Heuristic functions (Manhattan, Euclidean, Octile, Chebyshev, h(x)=0 "Dijkstra case").

Implementation details:

* Start, goal, walls nodes are constructed before pathfinding.
* Graph (blank nodes) is constructed dynamically while pathfinding proceeds with O(1) new node insertion time.
* Wall collision detection in O(1) time.
