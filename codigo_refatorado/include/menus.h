#ifndef CLASS_MENUS
#define CLASS_MENUS

#include "jogador.h"
#include "tela.h"

using namespace std;

/**
classe que mostra os menus do jogo na tela
*/
class Menus
{
private:
	Jogador *jogador;
	Tela *telaJogo;
public:
	//inicia as variáveis locais
	void init();
	//destrutor da classe
	~Menus();
	//mostra a animação inicial do jogo. Ao terminar executa o menuInicial
	void apresentacaoInicial();
	//mostra o menu inicial pro jogador. cada opção do menu levará a outra função desta classe
	void menuInicial();
	//função realizada ao clicar em iniciar jogo no menu Inicial
	void iniciaJogo();
};


#endif

