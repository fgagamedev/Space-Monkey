#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include <string>
#include "mapa.h"
#include "fileNotFoundException.h"
#include <SDL/SDL.h>

using namespace std;

/**
implementa a interface mapa com SDL. carrega o mapa daquela fase e o coloca na tela*/
class SDL_Mapa : public Mapa
{
private:
	SDL_Surface *img_mapa;
public:
	SDL_Mapa(string nome_mapa) throw (FileNotFoundException);
	~SDL_Mapa();
	void desenhaMapa();
	
};

#endif

