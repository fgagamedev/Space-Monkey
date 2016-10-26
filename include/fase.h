#ifndef FASE_H
#define FASE_H

#include <string>
#include <vector>

#include "jogador.h"
#include "initException.h"
#include "exitException.h"
#include "gameOverException.h"
#include "fileNotFoundException.h"
#include "mapa.h"
#include "horda.h"
#include "torre.h"

using namespace std;

/**
classe que representa as fases. cada objeto � uma fase diferente.
*/
class Fase
{
private:
	//vetor de hordas inimigas
	vector<Horda*> *hordas;
	
	//refer�ncia ao jogador, puxado da classe menu
	Jogador *jogador;
	//nome do arquivo de imagem do mapa
	string nome_mapa;
	//numero da fase (usado para o objeto saber qual fase ele �)
	int num_fase;
	//numero de hordas da fase (definido pelo num_fase)
	int num_hordas;
	//numero medio de inimigos por horda (definido pelo num_fase)
	int num_medio_inimigos_por_horda;
	//fase atual, usado pelas outras classes
	static int faseAtual;
	//"vida" da fase. Diz quantos inimigos podem chegar no final at� dar game over
	int life;
	//ap�s inicializar tudo, executa a horda at� seu fim
	void execFase(int i) throw (GameOverException, ExitException, FileNotFoundException);
public:
	Fase(string nome_mapa, int num_fase, Jogador *jogador);
	//inicia o mapa e o desenha na tela, al�m de iniciar as hordas e seus inimigos
	void init() throw (FileNotFoundException, InitException, GameOverException, ExitException);
	~Fase();
	static int getFaseAtual();
	//zera o contador de fases em caso de game over ou de encerr�-lo
	static int zerarContadorFases();
	//vetor de torres
	vector<Torre*> *torres;
	void redesenharTorres();

};

#endif
