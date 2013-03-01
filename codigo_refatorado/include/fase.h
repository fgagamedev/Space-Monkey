#ifndef FASE_H
#define FASE_H

#include <string>
#include "jogador.h"
#include "mapa.h"

using namespace std;

class Fase
{
private:
	Mapa *mapaFase;
	Jogador *jogador;
	string nome_mapa;
	int num_fase;
	int num_hordas;
	int num_medio_inimigos_por_horda;
public:
	Fase(string nome_mapa, int num_fase, Jogador *jogador);
	void init();
	~Fase();
};

#endif

