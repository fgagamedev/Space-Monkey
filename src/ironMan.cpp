
#include "jogador.h"
#include "ironMan.h"
#include "fileNotFoundException.h"
#include "SDL_Sprite.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"


void IronMan::init(int posX, int posY) throw(InitException, FileNotFoundException)
{
	this->HP = 2*TORRE_HP_PADRAO;
	this->dano = TORRE_DANO_PADRAO;
	this->tempoRecarga = 3*TORRE_TEMPO_RECARGUE_PADRAO;
	this->alcance = 0*TORRE_ALCANCE_PADRAO;
	custo = 3*TORRE_CUSTO_PADRAO;

	this->hp_restante  = this->HP;

	try{
		this->img = new SDL_Sprite(ARQUIVO_TORRE_IRONMAN,posX, posY);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do IronMan! não houve memoria suficiente!");
	}
}


//cria uma nova torre e decrescenta o nº de moedas do jogador
Torre* IronMan::createTorre()
{
	if(Jogador::getMoedas() < custo)
		return NULL;
	Jogador::perderMoedas(custo);
	return new IronMan();
}

//limpa a memoria
IronMan::~IronMan()
{
	delete this->img;
}

