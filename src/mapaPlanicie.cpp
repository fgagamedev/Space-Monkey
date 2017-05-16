#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "mapa1.h"

int iniciarMapa1(){

	SDL_Surface *screen = NULL;
	SDL_Rect rectMap;
	SDL_Rect *rectTower;
	SDL_Color mapColor, towerColor;
	Uint32 valMapColor, valTowColor;
	Uint32 video_options = SDL_HWSURFACE | SDL_DOUBLEBUF;

	int width = 800, height = 600;
	int bpp= 16;

	rectMap.x = RECTMAP_INICIO_X;
	rectMap.y = RECTMAP_INICIO_Y;
	rectMap.w = RECTMAP_WIDTH;
	rectMap.h = RECTMAP_HEIGHT;

	rectTower = setTowerRect();

	mapColor.r = 255;
	mapColor.g = 255;
	mapColor.b = 255;

	towerColor.r = 100;
	towerColor.g = 100;
	towerColor.b = 255;

	int rc;

	rc = SDL_Init(SDL_INIT_VIDEO);

	if(rc ==-1){
		fprintf(stdout, "Nao foi possivel inicializar a tela: %s\n", SDL_GetError());
		return -1;
	}

	atexit(SDL_Quit);

	SDL_WM_SetCaption("SpaceMonkey", "SpaceMonkey");
	SDL_WM_SetIcon(SDL_LoadBMP("resources/DownMonkeyLogo.bmp"), NULL);

	screen = SDL_SetVideoMode(width, height, bpp, video_options);

	if(!screen){
		fprintf(stdout, "Erro ao carregar video com estas configuracoes: %s\n", SDL_GetError());
		return -2;
	}

	valMapColor = SDL_MapRGB(screen->format, mapColor.r, mapColor.g, mapColor.b);
	valTowColor = SDL_MapRGB(screen->format, towerColor.r, towerColor.g, towerColor.b);

	drawMap(screen, rectMap, valMapColor);
	drawTower(screen, rectTower, valTowColor);

	SDL_UpdateRect(screen, 0, 0, 0, 0);

	SDL_Delay(10000);

	return 0;
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

void drawMap(SDL_Surface *screen, SDL_Rect rectMap, Uint32 valMapColor){

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

void drawTower(SDL_Surface *screen, SDL_Rect *rectTower, Uint32 valTowColor){

	int cont;

	for(cont=0; cont<N_TOWER; cont++)
		SDL_FillRect(screen, &rectTower[cont], valTowColor);
}

