#ifndef INICIALIZADOR_SDL_E_OUTRAS_BAGACAS
#define INICIALIZADOR_SDL_E_OUTRAS_BAGACAS

#include"initException.h"

class Inicializador
{
public:
	static void initGrafico()throw(InitException);
	static void initSom()throw(InitException);
};

#endif
