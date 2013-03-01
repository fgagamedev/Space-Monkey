
#include <stdlib.h>
#include <vector>
#include <algorithm>

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
}

//retorna um inimigo especifico
Inimigo* Horda::getInimigo(int pos)
{
	return 	this->vetorInimigos->at(pos);
}

//desaloca a memoria da hordae seus inimigos
Horda::~Horda()
{
//	this->vetorInimigos->(Inimigo)~Chipanze1();
	 
	int i, loops=this->vetorInimigos->size();
	for(i=0; i<loops; i++)
		delete this->vetorInimigos->at(i);
	
	delete this->vetorInimigos;
}


