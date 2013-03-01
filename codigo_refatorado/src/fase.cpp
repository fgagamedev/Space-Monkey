
#include <stdlib.h>
#include <time.h>
#include <string>

#include "fase.h"
#include "constantes.h"
#include "initException.h"
#include "jogador.h"
#include "SDL_Mapa.h"
#include "fileNotFoundException.h"
#include "horda.h"

//inicializa o mapa e o desenha na tela, além de inicializar as hordas e seus inimigos
void Fase::init() throw (FileNotFoundException, InitException)
{
	int inimigos_horda;

	//inicializa o mapa
	try{
		Mapa::loadMap(nome_mapa);
		Mapa::desenhaMapa();
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar memoria para o mapa da fase!" );
	}
	
	//inicializa as hordas
	try{
		//cria um vetor de hordas vazios
		this->hordas = new vector<Horda*>();
		
		int i;
		for(i=0; i<this->num_hordas; i++)
		{
			//determina o numero exato de inimigos em cada horda
			inimigos_horda = rand()%5 + 1;
			inimigos_horda *= rand()%2 ? 1 : -1;		
			inimigos_horda += this->num_medio_inimigos_por_horda;
			inimigos_horda < 5 ? inimigos_horda=5 : inimigos_horda=inimigos_horda;
			
			this->hordas->push_back(new Horda(inimigos_horda, this->num_fase));
			this->hordas->at(i)->init();
		}
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar memoria para as hordas da fase!");
	}
}

//faz os calculos das hordas e dos inimigos
Fase::Fase(string nome_mapa, int num_fase, Jogador *jogador)
{
	srand(time(NULL));
	
	this->nome_mapa = nome_mapa;
	this->num_fase = num_fase;
	this->num_hordas = num_fase*3 + rand()%5;
	this->num_medio_inimigos_por_horda = num_fase*5 + rand()%(num_fase+5);
	
	this->jogador = jogador;
}


Fase::~Fase()
{
	Mapa::liberaMapa();
	int i,loops=this->hordas->size();
	for(i=0; i<loops; i++)
	{	
		delete this->hordas->at(i);
	}
}

