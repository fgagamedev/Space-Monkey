
#include "menus.h"
#include "fase.h"
#include "tela.h"
#include "jogador.h"
#include "constantes.h"
#include "initException.h"
#include <string>
#include <iostream>


//inicia as variáveis locais
void Menus::init() throw (InitException)
{
	this->jogador = new Jogador();
	this->telaJogo = Tela::obterTela();
}

//destrutor da classe
Menus::~Menus()
{
	delete (this->jogador);
	Tela::liberarTela();
}

//mostra a animação inicial do jogo. Ao terminar executa o menuInicial
void Menus::apresentacaoInicial()
{
	//COLOCAR O CÓDIGO DA APRESENTAÇÃO INICIAL AQUI!
	
	menuInicial();
}

//mostra o menu inicial pro jogador. cada opção do menu levará a outra função desta classe
void Menus::menuInicial()
{
	//COLOCAR O CÓDIGO DO MENU INICIAL AQUI!
	
	//isso aqui acontece só ao receber o evento certo!!!
	iniciaJogo();
}

//função realizada ao clicar em iniciar jogo no menu Inicial
void Menus::iniciaJogo()
{
	Fase *fases[NUM_FASES_TOTAIS];
	
	string nome_mapa;
	int i;
	for(i=0; i<NUM_FASES_TOTAIS; i++)
	{
		try
		{
			switch(i)
			{
			case 0:
				nome_mapa = "mapa1.bmp";
				fases[i] = new Fase(nome_mapa, i+1, this->jogador);
				fases[i]->init();
				
				fases[i]->~Fase();
				break;
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 7:
				
				break;
			}// fim do switch
		//DESCOMENTAR APÓS FAZER TODAS AS FASES!!!		fases[i]->~Fase();	
		
		}catch(Exception e){
			//caso ocorra alguma falha em alguma fase, avisa qual o erro e encerra o jogo
			cout << "Falha na fase " << i+1 << ": " << e.getMessage().c_str() << endl;
			fases[i]->~Fase();
			break;
		}//fim do catch
	}//fim do for
}//fim da função

