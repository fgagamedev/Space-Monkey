#ifndef SDL_TELA_H
#define SDL_TELA_H

#include "initException.h"
#include "tela.h"
#include <SDL/SDL.h>

using namespace std;

class SDL_Tela : public Tela
{
private:
	Uint32 video_options;
	//construtor privado
	SDL_Tela();
	//objeto SDL que representa a tela
	static SDL_Surface *telaJogo; 
	//objeto único usado pelo singleton para determinar se cria umanova instância ou não
	static SDL_Tela *instancia;
	//inicializa a classe
	void init() throw (InitException);
	//verifica se a tela já foi criada
	bool foiInstanciado();
public:
	//método que cria ou devolve a tela já criada
	static Tela* obterTela() throw (InitException);
	//método que desaloca a tela (chamado ao fim do jogo)
	static void liberarTela();
	//devolve a tela do jogo (usado por classes de mais baixo nível). É preciso fazer typecast para a classe ou struct usada pela respectiva API
	static void* getTela();	

	//os métodos obterTela, getTela e liberarTela não precisam ser reescritos, pois são herdados da classe pai
};

#endif
