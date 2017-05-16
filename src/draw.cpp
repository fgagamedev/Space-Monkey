#include <stdio.h>
#include <stdlib.h>

#include "draw.h"

void init_map1(SDL_Surface *screen){


	drawMap1(screen);
	//drawTower(screen);

	SDL_UpdateRect(screen, 0, 0, 0, 0);

	SDL_Delay(10000);
}


SDL_Rect *setTowerRect(){

	SDL_Rect *rectTower;
	rectTower = (SDL_Rect *) calloc(N_TOWER, sizeof(SDL_Rect));

	int cont;

	for(cont=0; cont<N_TOWER; cont++){
		rectTower[cont].w = RECTTOWER_WIDTH;
		rectTower[cont].h = RECTTOWER_HEIGHT;
	}

	rectTower[0].x = 160;
	rectTower[0].y = 80;
	rectTower[1].x = 200;
	rectTower[1].y = 280;
	rectTower[2].x = 380;
	rectTower[2].y = 160;
	rectTower[3].x = 560;
	rectTower[3].y = 160;
	rectTower[4].x = 720;
	rectTower[4].y = 360;

	return rectTower;
}

void drawMap(SDL_Surface *screen){

	SDL_Rect rectMap;
	SDL_Color mapColor;
	Uint32 valMapColor;

	rectMap.x = RECTMAP_INICIO_X;
	rectMap.y = RECTMAP_INICIO_Y;
	rectMap.w = RECTMAP_WIDTH;
	rectMap.h = RECTMAP_HEIGHT;

	mapColor.r = 255;
	mapColor.g = 255;
	mapColor.b = 255;

	valMapColor = SDL_MapRGB(screen->format, mapColor.r, mapColor.g, mapColor.b);

	int i;
	int j;

	for(i=0; i<15; i++){

		if(i<5){
			for(j=0; j<2; j++){
				SDL_FillRect(screen, &rectMap, valMapColor);
				rectMap.x += RECTMAP_WIDTH;
			}
			rectMap.x = RECTMAP_INICIO_X;
			rectMap.y += RECTMAP_HEIGHT;
		}

		if(i>=5 && i<7){
			for(j=0; j<16; j++){
				SDL_FillRect(screen, &rectMap, valMapColor);
				rectMap.x += RECTMAP_WIDTH;
			}
			rectMap.x = RECTMAP_INICIO_X;
			rectMap.y += RECTMAP_HEIGHT;
		}

		if(i>=7){
			rectMap.x = RECTMAP_INICIO_X + 14*RECTMAP_WIDTH;
			for(j=0; j<2; j++){
				SDL_FillRect(screen, &rectMap, valMapColor);
				rectMap.x += RECTMAP_WIDTH;
			}
			rectMap.y += RECTMAP_HEIGHT;
		}
	}
}

void drawMap1(SDL_Surface *screen){

	SDL_Surface *mapa1 = SDL_LoadBMP("resources/mapa1.bmp");

	SDL_BlitSurface(mapa1,NULL, screen,NULL);

}

void drawTower(SDL_Surface *screen){

	SDL_Rect *rectTower;
	SDL_Color towerColor;
	Uint32 valTowColor;

	rectTower = setTowerRect();

	towerColor.r = 100;
	towerColor.g = 100;
	towerColor.b = 255;

	valTowColor = SDL_MapRGB(screen->format, towerColor.r, towerColor.g, towerColor.b);

	int cont;

	for(cont=0; cont<N_TOWER; cont++)
		SDL_FillRect(screen, &rectTower[cont], valTowColor);
}

