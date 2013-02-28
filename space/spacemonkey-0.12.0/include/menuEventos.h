#ifndef MENU_EVENTOS_H
#define MENU_EVENTOS_H

#include "constantes.h"
#include "fileNotFoundException.h"
#include "exitException.h"
#include <SDL/SDL.h>

class MenuEventos
{
private:
	SDL_Surface *fundo, *btJogar, *btExtra, *btSair, *btJogar2, *btExtra2, *btSair2;
	bool emcimaJogar, emcimaExtra, emcimaSair;
	//métodos que verificam se o mouse passou por cima do botão
	bool verificaColisaoJogar(Uint16 x, Uint16 y);
	bool verificaColisaoExtra(Uint16 x, Uint16 y);
	bool verificaColisaoSair(Uint16 x, Uint16 y);
	//troca a imagem do botão
	void trocarImgJogar();
	void trocarImgExtra();
	void trocarImgSair();
public:
	MenuEventos() throw (FileNotFoundException);
	~MenuEventos();
	void init();
	Botoes getBotaoPressionado() throw (ExitException);
};

#endif
