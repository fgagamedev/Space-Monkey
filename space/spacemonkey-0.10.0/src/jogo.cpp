
#include "jogo.h"
#include "menus.h"
#include "jogador.h"
#include "initException.h"
#include "exitException.h"
#include "nomesArquivos.h"
#include "tela.h"
#include "fase.h"
//#include "thread.h"
#include "constantes.h"
#include <iostream>
#include <string>

using namespace std;


//inicia de fato o jogo
void Jogo::rodarJogo()
{
	Menus *menus;
	Botoes botao;
	
	//cria os menus e inicia a thread de Eventos
	try{	
		this->jogador = new Jogador();
		menus = new Menus();
		menus->init();
	}catch(bad_alloc ba){
		cout << "falha ao alocar memoria para o jogador!" << endl;
		return;
	}catch(InitException &e){
		cout << "falha ao iniciar o jogo! " << e.getMessage().c_str() << endl;
		return;
	}catch(ExitException &e2){
		cout << e2.getMessage().c_str() << endl;
		return;
	}
	
	try{
		menus->apresentacaoInicial();
		botao = menus->menuInicial();
	}catch(Exception &e){
		delete this->jogador;
		delete menus;
		cout << e.getMessage().c_str() << endl;
		return;
	}
	
	switch(botao)
	{
	case Jogar:
		iniciaJogo();
		break;
	case Extras:
		
		break;
	case Sair:
		break;
	}
	
	//finaliza o jogo
	delete this->jogador;
	delete menus;
}

//função realizada ao clicar em iniciar jogo no menu Inicial
void Jogo::iniciaJogo()
{
	Fase *fases[NUM_FASES_TOTAIS];
	
	string nome_mapa;
	int i;
	for(i=0; i<NUM_FASES_TOTAIS; i++)
	{
		try
		{
			nome_mapa = NOME_MAPAS[i];
			fases[i] = new Fase(nome_mapa, i+1, this->jogador);
			fases[i]->init();
			delete fases[i];	
		
		}catch(Exception &e){
			//caso ocorra alguma falha em alguma fase, avisa qual o erro e encerra o jogo
			cout << "Falha na fase " << i+1 << ": " << e.getMessage().c_str() << endl;
			if(fases[i])	
				delete fases[i];
			break;
		}//fim do catch
	}//fim do for
}//fim da função

