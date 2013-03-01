#include <stdio.h>
#include <stdlib.h>

#include "video.h"

void init_sdl(){
	
	int rc = SDL_Init(SDL_INIT_VIDEO);
	
	if(rc==-1){
		fprintf(stdout, "Erro ao inicializar SDL: %s", SDL_GetError());
		exit(1);
	}

	atexit(SDL_Quit);
}

void setup_window(){
	
	SDL_WM_SetCaption("SpaceMonkey", "SpaceMonkey");
	SDL_WM_SetIcon(SDL_LoadBMP("/opt/spacemonkey/resources/DownMonkeyLogo.bmp"), NULL);

}

SDL_Surface *setup_video(){

	SDL_Surface *screen = NULL;
	Uint32 video_options = SDL_HWSURFACE | SDL_DOUBLEBUF;

	int width = 800, height = 600;
	int bpp = 32;

	screen = SDL_SetVideoMode(width, height, bpp, video_options);

	if (!screen)
	{
		fprintf(stderr, "Falha ao iniciar o video com essas configuracoes: %s\n",
			SDL_GetError());
		exit(1);
	}

	return screen;
}



