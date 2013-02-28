
#include "SDL_Mapa.h"
#include "constantes.h"
#include "tela.h"
#include "fileNotFoundException.h"
#include <string>
#include <SDL/SDL.h>

//carrega o arquivo com o desenho do mapa. Se der errado lança uma exceção
SDL_Mapa::SDL_Mapa(string nome_mapa) throw (FileNotFoundException)
{
	img_mapa = SDL_LoadBMP( (PATH + nome_mapa).c_str() );
	if(!img_mapa)
		throw new FileNotFoundException( string("Falha ao tentar carregar o seguinte arquivo: ") + nome_mapa);
}

//desenha o mapa na tela
void SDL_Mapa::desenhaMapa()
{
	SDL_BlitSurface(img_mapa,NULL, (SDL_Surface*)Tela::getTela(),NULL);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), 0, 0, 0, 0);
	
	SDL_Delay(3000);
	
	SDL_SaveBMP((SDL_Surface*)Tela::getTela(), "screenshot.bmp");
}

SDL_Mapa::~SDL_Mapa()
{
	SDL_FreeSurface(img_mapa);
	
}
