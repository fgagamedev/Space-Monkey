
#include "jogador.h"
#include "muro.h"
#include "fileNotFoundException.h"
#include "SDL_Sprite.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"


void Muro::init() throw(InitException, FileNotFoundException)
{
	this->HP = TORRE_HP_PADRAO;
	this->dano = 0*TORRE_DANO_PADRAO;
	this->tempoRecarga = 0*TORRE_TEMPO_RECARGUE_PADRAO;
	this->alcance = 0*TORRE_ALCANCE_PADRAO;
	custo = 0.7*TORRE_CUSTO_PADRAO;
	
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_TORRE_MURO,30, 30);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do Muro! não houve memoria suficiente!");
	}
}

//cria uma nova torre e decrescenta o nº de moedas do jogador
Torre* Muro::createTorre()
{
	if(Jogador::getMoedas() < custo)
		return NULL;
	Jogador::perderMoedas(custo);
	return new Muro();
}

//limpa a memoria
Muro::~Muro()
{
	delete this->img;
}

