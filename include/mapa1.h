#define RECTMAP_INICIO_X 80
#define RECTMAP_INICIO_Y 0
#define RECTMAP_WIDTH 40
#define RECTMAP_HEIGHT 40

#define RECTTOWER_WIDTH 40
#define RECTTOWER_HEIGHT 40

#define N_TOWER 5

SDL_Rect *setTowerRect();
void drawMap(SDL_Surface *screen, SDL_Rect rectMap, Uint32 valMapColor);
void drawTower(SDL_Surface *screen, SDL_Rect *rectTower, Uint32 valTowColor);
int iniciarMapa1();
