#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include <string>
#include "mapa.h"
#include "constantes.h"
#include "fileNotFoundException.h"
#include <SDL/SDL.h>

using namespace std;

/**
implementa a interface mapa com SDL. carrega o mapa daquela fase e o coloca na tela*/
class SDL_Mapa : public Mapa
{
private:
	static SDL_Surface *img_mapa;
	static char **mapaLogico;
	//posição, em pixels, do objetivo dos inimigos
	static int goalX, goalY;
public:
	static void loadMap(string nome_mapa) throw (FileNotFoundException);
	static void desenhaMapa();	
	static void* getMapa();	
	static bool mapaCarregado();
	static void liberaMapa();
	static void inicializaMapaLogico();
	static bool getMapaLogico(int x, int y, Direcao dir);
	static bool possoPorTorre(int x, int y);
	static void defineGoal();
	static int getGoalX();
	static int getGoalY();
};

#endif

