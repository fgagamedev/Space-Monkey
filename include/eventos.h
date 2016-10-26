#ifndef EVENTOS_H
#define EVENTOS_H

#include"exitException.h"
#include"fase.h"
#include<SDL/SDL.h>

class Eventos
{
private:
	SDL_Event event;
public:
	void trataEventos(Fase *faseCorrente) throw(ExitException);
	void trataEventos() throw(ExitException);
};

#endif
