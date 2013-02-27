#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main()
{
	SDL_Surface *screen = NULL;
	SDL_Color cor;	
	Uint32 valorCor;
	SDL_Rect retangulo;

	retangulo.w = 150;
	retangulo.h = 90;
	retangulo.x = 300;
	retangulo.y = 200;

	cor.r = 255;
	cor.g = 0;
	cor.b = 0;	

	int width = 800, height = 600;
	int bpp = 16;

	Uint32 video_options = SDL_HWSURFACE | SDL_DOUBLEBUF;
	int rc;

	rc = SDL_Init(SDL_INIT_VIDEO);

	if (rc == -1)
	{
		fprintf(stderr, "Erro na inicializacao da SDL: %s\n",
			SDL_GetError());
		return -1;
	}

	atexit(SDL_Quit);

	SDL_WM_SetCaption("SpaceMonkey", "SpaceMonkey");
	SDL_WM_SetIcon(SDL_LoadBMP("/opt/spacemonkey/resources/DownMonkeyLogo.bmp"), NULL);

	screen = SDL_SetVideoMode(width, height, bpp, video_options);

	if (!screen)
	{
		fprintf(stderr, "Falha ao iniciar o video com essas configuracoes: %s\n",
			SDL_GetError());
		return -2;
	}

	valorCor = SDL_MapRGB(screen->format, cor.r, cor.g, cor.b);

	SDL_FillRect(screen, &retangulo, valorCor);
	SDL_UpdateRect(screen, 0, 0, 0, 0);

	printf("Tela Inicial do jogo - Duracao: 10seg!\n");

	SDL_Delay(10000);

	return 0;
}

