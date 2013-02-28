
#include "jogador.h"
#include "atiradorSimples.h"
#include "fileNotFoundException.h"
#include "SDL_Sprite.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"


void AtiradorSimples::init() throw(InitException, FileNotFoundException)
{
	this->HP = TORRE_HP_PADRAO;
	this->dano = TORRE_DANO_PADRAO;
	this->tempoRecarga = TORRE_TEMPO_RECARGUE_PADRAO;
	this->alcance = TORRE_ALCANCE_PADRAO;
	custo = TORRE_CUSTO_PADRAO;
	
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_TORRE_SIMPLES,30, 30);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do atiradorSimples! não houve memoria suficiente!");
	}
}

//cria uma nova torre e decrescenta o nº de moedas do jogador
Torre* AtiradorSimples::createTorre()
{
	if(Jogador::getMoedas() < custo)
		return NULL;
	Jogador::perderMoedas(custo);
	return new AtiradorSimples();
}

//limpa a memoria
AtiradorSimples::~AtiradorSimples()
{
	delete this->img;
}

