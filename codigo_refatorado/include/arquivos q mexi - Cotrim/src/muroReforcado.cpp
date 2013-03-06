
#include "jogador.h"
#include "muroReforcado.h"
#include "fileNotFoundException.h"
#include "SDL_Sprite.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"


void MuroReforcado::init(int posX, int posY) throw(InitException, FileNotFoundException)
{
	this->HP = 3*TORRE_HP_PADRAO;
	this->dano = 0*TORRE_DANO_PADRAO;
	this->tempoRecarga = 0*TORRE_TEMPO_RECARGUE_PADRAO;
	this->alcance = 0*TORRE_ALCANCE_PADRAO;
	custo = 1.6*TORRE_CUSTO_PADRAO;
	
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_TORRE_MUROREFORCADO,posX, posY);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do MuroReforcado! não houve memoria suficiente!");
	}
}

//limpa a memoria
MuroReforcado::~MuroReforcado()
{
	delete this->img;
}

