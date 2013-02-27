#ifndef TELA_H
#define TELA_H

#include "initException.h"
#include <SDL/SDL.h>

using namespace std;

class Tela
{
private:
	Uint32 video_options;
	//construtor privado para uso do singleton
	Tela();
	//inicializa a classe
	void init() throw (InitException);
	
	static SDL_Surface *telaJogo; 
	//variável que garante que existe apenas uma instancia da tela no jogo todo
	static Tela *instancia;
public:
	//método que cria ou devolve a tela já criada
	static Tela* obterTela();
	static void liberarTela();
	static SDL_Surface* getTela();
	
};

#endif

