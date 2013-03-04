#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#include "eventos.h"
#include"marcador.h"
#include"exitException.h"
#include "util.h"
#include "mapa.h"
#include "horda.h"
#include "constantes.h"
#include "inimigo.h"
#include "chipanze1.h"
#include "chipanze2.h"
#include "orangotango.h"
#include "gorila1.h"
#include "gorila2.h"

//guarda o tamanho da horda e a quantidade de cada tipo de inimigo
Horda::Horda(int numInimigos, int numFase)
{
	this->numInimigos = numInimigos;
	this->inimigosSobrando = numInimigos;
	
	//determina se é uma fase facil ou dificil, dependendo da resposta determina um maior numero de inimigos fortes
	if(numFase < (NUM_FASES_TOTAIS/3))
	{
		this->numChipanzes1 = rand()%numInimigos;
		this->numChipanzes2 = rand()%(numInimigos-numChipanzes1);
		this->numOragotangos = rand()%(numInimigos-numChipanzes1-numChipanzes2);
		this->numGorilas1 = numInimigos-numChipanzes1-numChipanzes2-numOragotangos;
		this->numGorilas2 = 0;
		
	}
	else if(numFase > (NUM_FASES_TOTAIS/3) && numFase < (2*NUM_FASES_TOTAIS/3))
	{
		this->numChipanzes1 = rand()%numInimigos;
		this->numChipanzes2 = rand()%(numInimigos-numChipanzes1);
		this->numOragotangos = rand()%(numInimigos-numChipanzes1-numChipanzes2);
		this->numGorilas1 = rand()%(numInimigos-numChipanzes1-numChipanzes2-numOragotangos);
		this->numGorilas2 = numInimigos-numChipanzes1-numChipanzes2-numGorilas1-numOragotangos;	
	}
	else{
		this->numGorilas1 = rand()%numInimigos;
		this->numGorilas2 = rand()%(numInimigos-numGorilas1);
		this->numOragotangos = rand()%(numInimigos-numGorilas1-numGorilas2);
		this->numChipanzes2 = rand()%(numInimigos-numGorilas1-numGorilas2-numOragotangos);
		this->numChipanzes1 = numInimigos-numGorilas1-numGorilas2-numChipanzes2-numOragotangos;	
	}
	
}


//inicializa os inimigos
void Horda::init() throw (InitException, FileNotFoundException)
{
	try{
		//this->vetorInimigos = new Chipanze1[this->numInimigos];	
		
		this->vetorInimigos = new vector<Inimigo*>();
		int i;
		for(i=0; i<this->numChipanzes1; i++)
		{
			vetorInimigos->push_back(new Chipanze1());
			vetorInimigos->back()->init();
		}
		for(i=0; i<this->numChipanzes2; i++)
		{
			vetorInimigos->push_back(new Chipanze2());
			vetorInimigos->back()->init();
		}
		for(i=0; i<this->numOragotangos; i++)
		{
			vetorInimigos->push_back(new Orangotango());
			vetorInimigos->back()->init();
		}
		for(i=0; i<this->numGorilas1; i++)
		{
			vetorInimigos->push_back(new Gorila1());
			vetorInimigos->back()->init();
		}
		for(i=0; i<this->numGorilas2; i++)
		{
			vetorInimigos->push_back(new Gorila2());
			vetorInimigos->back()->init();
		}
		
		random_shuffle(vetorInimigos->begin(), vetorInimigos->end());
	}catch(bad_alloc ba){
		throw InitException("erro ao alocar os inimigos!");
	}
	
cout << "criei " << numChipanzes1+numChipanzes2+numOragotangos+numGorilas1+numGorilas2 << " macacos" << endl;
}

//retorna um inimigo especifico
Inimigo* Horda::getInimigo(int pos)
{
	return 	this->vetorInimigos->at(pos);
}



//desaloca a memoria da hordae seus inimigos
Horda::~Horda()
{
	if(this->vetorInimigos)
	{
		this->vetorInimigos->clear();	
		delete this->vetorInimigos;
	}
}

//redesenha o mapa só nas posiçõe onde tem inimigo e o marcador (limpa a tela). Em vez de atualizar a tela toda, atualiza só as partes necessarias pra economizar processamento
void Horda::redesenhaMapa()throw(FileNotFoundException)
{
	int i;
	for(i=0; i<vetorInimigos->size(); i++)
		vetorInimigos->at(i)->limparTela();
	
	Mapa::printCoins();
	Marcador::print();
}

//executa a movimentação de toda horda, sendo que cada uma decide pra onde vai sozinha
void Horda::exec()throw(ExitException,FileNotFoundException)
{
	Eventos eventos;
	unsigned int i, j, k, passos;
	for(i=1; i<vetorInimigos->size()+1; i++)
	{
		passos = rand()%10+1;
		for(j=0; j<passos; j++)
		{
			eventos.trataEventos();
			this->redesenhaMapa();
			for(k=0; k<i; k++)
				vetorInimigos->at(k)->mover();
			Util::delay(5);
		}
	}
}

void Horda::exec1()throw(ExitException,FileNotFoundException)
{
	unsigned int i;
	this->redesenhaMapa();
	for(i=0; i<vetorInimigos->size(); i++)
		vetorInimigos->at(i)->mover();
	Util::delay(5);
}

//verifica o estado de cada inimigo da horda e os libera caso tenham morrido ou chegado ao objetivo. Retorna o número de inimigos que alcançaram o objetivo final
unsigned int Horda::verificaEstadoInimigos()
{
	int i=0;
	unsigned int cont=0;
	for(i=0; i<this->vetorInimigos->size(); i++)
	{
		//verifica se chegou ao ponto final
		if(this->vetorInimigos->at(i)->chegouPontoFinal())
		{
			cont++;
			delete this->vetorInimigos->at(i);
			this->vetorInimigos->erase(this->vetorInimigos->begin()+i);
			i--;
			this->inimigosSobrando--;
		}
		//verifica se foi morto
		else if(this->vetorInimigos->at(i)->isDead())
		{
			delete this->vetorInimigos->at(i);
			this->vetorInimigos->erase(this->vetorInimigos->begin()+i);
			i--;
			this->inimigosSobrando--;
		}
	}
	return cont;
}

//retorna o numero de inimigos vivos
int Horda::getInimigosSobrando()
{
	return this->inimigosSobrando;
}

