#ifndef MAPA_H
#define MAPA_H

#include <string>
#include "fileNotFoundException.h"

using namespace std;

/**
Interface que representa o mapa (background) de cada fase. Isola a API gráfica do resto do sistema
*/
class Mapa
{
public:
	virtual void desenhaMapa() = 0;	
};

#endif

