#ifndef CLASS_JOGO 
#define CLASS_JOGO

#include "jogador.h"
//#include "thread.h"

using namespace std;

/**
classe que representa um jogo. Inicia os menus iniciais e inicializa o jogo e jogador
*/
class Jogo
{
private:
	bool continuaJogo;
	Jogador *jogador;
public:
	//inicia de fato o jogo
	void rodarJogo();
	//função realizada ao clicar em iniciar jogo no menu Inicial
	void iniciaJogo();
};


#endif

