#ifndef CLASS_MENUS
#define CLASS_MENUS

#include "jogador.h"
#include "tela.h"
#include "initException.h"

using namespace std;

/**
classe que mostra os menus do jogo na tela, cria a tela e o jogador
*/
class Menus
{
private:
	Jogador *jogador;
	Tela *telaJogo;
public:
	//inicia as variáveis locais
	void init() throw (InitException);
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

