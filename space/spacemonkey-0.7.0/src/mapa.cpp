
#include  <string>
#include "mapa.h"
#include "constantes.h"
#include "SDL_Mapa.h"
#include "fileNotFoundException.h"

void Mapa::desenhaMapa()
{
	SDL_Mapa::desenhaMapa();
}	

void* Mapa::getMapa()
{
	return SDL_Mapa::getMapa();
}

void Mapa::loadMap(string nome_mapa) throw (FileNotFoundException)
{
	return SDL_Mapa::loadMap(nome_mapa);
}

bool Mapa::mapaCarregado()
{
	return  SDL_Mapa::mapaCarregado();
}

void Mapa::liberaMapa()
{	
	SDL_Mapa::liberaMapa();
}

void Mapa::inicializaMapaLogico()
{
	SDL_Mapa::inicializaMapaLogico();
}

bool Mapa::getMapaLogico(int x, int y, Direcao dir)
{
	return SDL_Mapa::getMapaLogico(x, y, dir);
}

void Mapa::defineGoal(string nome_mapa)
{
	SDL_Mapa::defineGoal(nome_mapa);
}
	
int Mapa::getGoalX()
{
	return SDL_Mapa::getGoalX();
}

int Mapa::getGoalY()
{
	return SDL_Mapa::getGoalY();
}

