#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "fase.h"
#include "eventos.h"
#include "constantes.h"
#include "nomesArquivos.h"
#include "exitException.h"
#include "exception.h"
#include "initException.h"
#include "gameOverException.h"
#include "audio.h"
#include "jogador.h"
#include "SDL_Mapa.h"
#include "fileNotFoundException.h"
#include "horda.h"
#include "util.h"
// Torres
#include "torre.h"
#include "atiradorSimples.h"

int Fase::faseAtual = -1;

//faz os calculos das hordas e dos inimigos
Fase::Fase(string nome_mapa, int num_fase, Jogador *jogador)
{
	srand(time(NULL));
	
	this->nome_mapa = nome_mapa;
	this->num_fase = num_fase;
	this->num_hordas = num_fase*3 + rand()%5;
	this->num_medio_inimigos_por_horda = num_fase*5 + rand()%(num_fase+5);
	this->jogador = jogador;
	this->life = VIDA_FASE;
	
	faseAtual++;
	this->hordas=NULL;
	this->torre=NULL;	
}

//inicializa o mapa e o desenha na tela, além de inicializar as hordas e seus inimigos
void Fase::init() throw (FileNotFoundException, InitException, GameOverException, ExitException)
{
	int inimigos_horda;
cout << "\nFASE " << this->num_fase << endl;
	//inicializa o mapa
	try{
		Mapa::loadMap(nome_mapa);
		Mapa::desenhaMapa();
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar memoria para o mapa da fase!" );
	}
	//inicia a musica de fundo
	Util::playMusic(MUSICA_FASES[faseAtual]);	
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
cout << "horda "<< i+1 << endl;
			
			this->hordas->push_back(new Horda(inimigos_horda, this->num_fase));
			this->hordas->at(i)->init();
			this->execHorda(i);
		}
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar memoria para as hordas da fase!");
	}
	
	// Inicializa Torres
	try{
		this->torre = new AtiradorSimples();
		torre->init();
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar memoria para torre!");
	}
}

int Fase::getFaseAtual()
{
	return faseAtual;
}

Fase::~Fase()
{
	Mapa::liberaMapa();
	Audio::stopAudio();
	if(this->hordas)
	{
		int i,loops=this->hordas->size();
		for(i=0; i<loops; i++)
			delete this->hordas->at(i);
		delete this->hordas;
	}
}

//após inicializar tudo, executa a fase até seu fim
//Talvez: Mudar nome de execHorda para execFase
void Fase::execHorda(int i) throw(GameOverException, ExitException, FileNotFoundException)
{
	this->hordas->at(i)->exec();
	while(this->hordas->at(i)->getInimigosSobrando() > 0)
	{
		this->life -= this->hordas->at(i)->verificaEstadoInimigos();
		//verifica se deu game over
		if(this->life <= 0)
			throw GameOverException("");
		//trata os eventos
		Eventos eventos;
		eventos.trataEventos(this);
		//executa a horda
		this->hordas->at(i)->exec1();
	}
}

int Fase::zerarContadorFases()
{
	faseAtual = -1;
	return faseAtual;
}

