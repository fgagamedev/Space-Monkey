#include "animacao.h"
#include "jogo.h"
#include "audio.h"
#include "menus.h"
#include "jogador.h"
#include "initException.h"
#include "gameOverException.h"
#include "exitException.h"
#include "nomesArquivos.h"
#include "tela.h"
#include "fase.h"
#include "marcador.h"
#include "inicializador.h"
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
		Inicializador::initGrafico();
		Inicializador::initSom();
	cout <<"som inicializado"<<endl;	
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
	
	continuaJogo = true;
	do{
		//apresenta a pt inicial
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
			continuaJogo = false;
			break;
		}

	}while(continuaJogo);
	
	//finaliza o jogo
	delete this->jogador;
	delete menus;
	Audio::closeAudio();
}

//função realizada ao clicar em iniciar jogo no menu Inicial
void Jogo::iniciaJogo()
{
	Fase *fases[NUM_FASES_TOTAIS];
	Fase::zerarContadorFases();
	Animacao anima;
	
	string nome_mapa;
	int i=0;
	try
	{
		//cria os marcadores antes de começar uma fase específica e os mantem na memoria até o fim do jogo
		Marcador::criaMarcadores();
		//roda as fases
		for(i=0; i<NUM_FASES_TOTAIS; i++)
		{
			nome_mapa = NOME_MAPAS[i];
			fases[i] = new Fase(nome_mapa, i+1, this->jogador);
			fases[i]->init();
			delete fases[i];			
		}
		//mostra os créditos
		anima.creditos();
		//libera os marcadores
		Marcador::destruirMarcadores();
		
	}catch(GameOverException &go){
		cout << "voce perdeu!!!!" << endl;
		if(fases[i])	
			delete fases[i];
		anima.gameOver();
	}catch(ExitException &ee){
		if(fases[i])	
			delete fases[i];
			continuaJogo = false;
	}catch(Exception &e){
		//caso ocorra alguma falha em alguma fase, avisa qual o erro e encerra o jogo
		cout << "Falha na fase " << i+1 << ": " << e.getMessage().c_str() << endl;
		if(fases[i])	
			delete fases[i];
		continuaJogo = false;
	}
}//fim da função

