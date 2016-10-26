#ifndef CLASS_MENUS
#define CLASS_MENUS

#include "jogador.h"
#include "tela.h"
#include "initException.h"
#include "fileNotFoundException.h"
#include "animaException.h"
#include "exitException.h"
#include "constantes.h"

using namespace std;

/**
classe que mostra os menus do jogo na tela e cria a tela
*/
class Menus
{
private:
	Tela *telaJogo;
public:
	//inicia as variáveis locais
	void init() throw (InitException);
	//destrutor da classe
	~Menus();
	//mostra a animação inicial do jogo
	void apresentacaoInicial() throw(InitException, FileNotFoundException, ExitException, AnimaException);
	//mostra o menu inicial pro jogador. retorna o inteiro correspondente ao botão pressionado
	Botoes menuInicial() throw(FileNotFoundException, ExitException);
};


#endif

