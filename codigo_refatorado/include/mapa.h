#ifndef MAPA_H
#define MAPA_H

#include <string>
#include "constantes.h"
#include "fileNotFoundException.h"

using namespace std;

/**
Interface que representa o mapa (background) de cada fase. Isola a API gráfica do resto do sistema
*/
class Mapa
{
public:
	static void loadMap(string nome_mapa) throw (FileNotFoundException);
	static void desenhaMapa();	
	static void* getMapa();
	static bool mapaCarregado();
	static void liberaMapa();
	static void inicializaMapaLogico();
	static bool possoPorTorre(int x, int y);
	static bool getMapaLogico(int x, int y, Direcao dir);
	static void defineGoal();
	static int getGoalX();
	static int getGoalY();
};

#endif

