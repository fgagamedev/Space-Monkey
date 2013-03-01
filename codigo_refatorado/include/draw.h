#ifndef DRAW_H
#define DRAW_H

#include <SDL/SDL.h>

#define RECTMAP_INICIO_X 80
#define RECTMAP_INICIO_Y 0
#define RECTMAP_WIDTH 40
#define RECTMAP_HEIGHT 40

#define RECTTOWER_WIDTH 40
#define RECTTOWER_HEIGHT 40

#define N_TOWER 5

extern void init_map1(SDL_Surface *screen);
extern SDL_Rect *setTowerRect();
extern void drawMap(SDL_Surface *screen);
extern void drawTower(SDL_Surface *screen);


#endif
