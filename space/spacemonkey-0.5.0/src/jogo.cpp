
#include "jogo.h"
#include "menus.h"

//inicia de fato o jogo
void Jogo::rodarJogo()
{
	//inicia o jogo
	Menus *menus = new Menus();
	menus->init();
	menus->apresentacaoInicial();
	
	//finaliza o jogo
	menus->~Menus();
}

