
#include "jogo.h"
#include "menus.h"
#include "initException.h"
#include <iostream>

using namespace std;

//inicia de fato o jogo
void Jogo::rodarJogo()
{
	Menus *menus;
	//cria os menus
	try{
		menus = new Menus();
		menus->init();
	}catch(InitException e){
		cout << "falha ao iniciar o jogo! " << e.getMessage().c_str() << endl;
	}
	
	//os erros que podem vir a ocorrer durante o jogo são tratados na classe menus!
	menus->apresentacaoInicial();
	
	//finaliza o jogo
	menus->~Menus();
}

