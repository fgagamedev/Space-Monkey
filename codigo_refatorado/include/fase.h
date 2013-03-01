#ifndef FASE_H
#define FASE_H

#include <string>
#include <vector>

#include "jogador.h"
#include "initException.h"
#include "fileNotFoundException.h"
#include "mapa.h"
#include "horda.h"

using namespace std;

/**
classe que representa as fases. cada objeto é uma fase diferente.
*/
class Fase
{
private:
	//vetor de hordas inimigas
	vector<Horda*> *hordas;
	//referência ao jogador, puxado da classe menu
	Jogador *jogador;
	//nome do arquivo de imagem do mapa
	string nome_mapa;
	//numero da fase (usado para o objeto saber qual fase ele é)
	int num_fase;
	//numero de hordas da fase (definido pelo num_fase)
	int num_hordas;
	//numero medio de inimigos por horda (definido pelo num_fase)
	int num_medio_inimigos_por_horda;
public:
	Fase(string nome_mapa, int num_fase, Jogador *jogador);
	//inicia o mapa e o desenha na tela, além de iniciar as hordas e seus inimigos
	void init() throw (FileNotFoundException, InitException);
	~Fase();
};

#endif
