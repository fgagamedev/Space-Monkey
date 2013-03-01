
#include <stdlib.h>
#include <time.h>
#include <string>

#include "fase.h"
#include "constantes.h"
#include "jogador.h"
#include "mapa.h"
//#include "jogador.cpp"
//#include "mapa.cpp"

void Fase::init()
{
	this->mapaFase = new Mapa(nome_mapa);
	this->mapaFase->desenhaMapa();
}

Fase::Fase(string nome_mapa, int num_fase, Jogador *jogador)
{
	srand(time(NULL));
	
	this->nome_mapa = nome_mapa;
	this->num_fase = num_fase;
	this->num_hordas = num_fase*3 + rand()%5;
	this->num_medio_inimigos_por_horda = num_fase*5 + rand()%(num_fase+10);
	
	this->jogador = jogador;
}

Fase::~Fase()
{
	mapaFase->~Mapa();
}

