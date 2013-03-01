#ifndef MAPA_H
#define MAPA_H

#include <string>
#include "jogador.h"
#include "mapa.h"
#include <SDL/SDL.h>

using namespace std;

class Mapa
{
private:
	SDL_Surface *img_mapa;
public:
	Mapa(string nome_mapa);
	~Mapa();
	void desenhaMapa();
	
};

#endif

