
#include "jogador.h"
#include "atiradorMoreFire.h"
#include "fileNotFoundException.h"
#include "SDL_Sprite.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"


void AtiradorMoreFire::init(int posX, int posY) throw(InitException, FileNotFoundException)
{
	this->HP = TORRE_HP_PADRAO;
	this->dano = TORRE_DANO_PADRAO*2;
	this->tempoRecarga = TORRE_TEMPO_RECARGUE_PADRAO;
	this->alcance = TORRE_ALCANCE_PADRAO;
	custo = 2*TORRE_CUSTO_PADRAO;
	
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_TORRE_MOREFIRE,posX, posY);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do atiradorSimples! não houve memoria suficiente!");
	}
}

//limpa a memoria
AtiradorMoreFire::~AtiradorMoreFire()
{
	delete this->img;
}

