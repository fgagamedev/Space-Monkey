
#include "mapa.h"
#include "constantes.h"
#include "tela.h"
#include <string>
#include <SDL/SDL.h>

Mapa::Mapa(string nome_mapa)
{
	img_mapa = SDL_LoadBMP( (PATH + nome_mapa).c_str() );
}

void Mapa::desenhaMapa()
{
	SDL_BlitSurface(img_mapa,NULL, Tela::getTela(),NULL);
	SDL_UpdateRect(Tela::getTela(), 0, 0, 0, 0);
}

Mapa::~Mapa()
{
	SDL_FreeSurface(img_mapa);
	
}
