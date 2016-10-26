#ifndef MAPA_H
#define MAPA_H

#include <string>
#include "constantes.h"
#include "fileNotFoundException.h"

/**
Interface que representa o mapa (background) de cada fase. Isola a API gráfica do resto do sistema
*/
class Mapa
{
private:
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
	static void printCoins()throw(FileNotFoundException);
	static bool verificaPosicaoTorre(int xMouse, int yMouse);
	static void alteraEstadoMapaLogico(int posX,int posY, char novoEstado);
};

#endif

