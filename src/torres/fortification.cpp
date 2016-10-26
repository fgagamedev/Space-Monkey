
#include "jogador.h"
#include "fortification.h"
#include "fileNotFoundException.h"
#include "SDL_Sprite.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"


void Fortification::init(int posX, int posY) throw(InitException, FileNotFoundException)
{
	this->HP = 4*TORRE_HP_PADRAO;
	this->dano = 0*TORRE_DANO_PADRAO;
	this->tempoRecarga = 0*TORRE_TEMPO_RECARGUE_PADRAO;
	this->alcance = 0*TORRE_ALCANCE_PADRAO;
	custo = 4*TORRE_CUSTO_PADRAO;
	
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_TORRE_FORTIFICATION,posX, posY);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do Fortification! não houve memoria suficiente!");
	}
}

//limpa a memoria
Fortification::~Fortification()
{
	delete this->img;
}

