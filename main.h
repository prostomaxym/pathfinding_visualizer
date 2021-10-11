#ifndef PATHFINDING_VISUALIZER_MAIN_H_
#define PATHFINDING_VISUALIZER_MAIN_H_

void gameloop(int);
void render();
void update();

extern bool fullscreen;
extern const int frametime;  //frametime in milliseconds
extern const int w, h;  //window resolution
extern const int cell_size;  //length of single field cell
#endif  // PATHFINDING_VISUALIZER_MAIN_H_