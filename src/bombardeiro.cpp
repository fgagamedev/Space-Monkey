
#include "jogador.h"
#include "bombardeiro.h"
#include "fileNotFoundException.h"
#include "SDL_Sprite.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"


void Bombardeiro::init(int posX, int posY) throw(InitException, FileNotFoundException)
{
	this->HP = 2*TORRE_HP_PADRAO;
	this->dano = TORRE_DANO_PADRAO*2;
	this->tempoRecarga = TORRE_TEMPO_RECARGUE_PADRAO;
	this->alcance = TORRE_ALCANCE_PADRAO/2;
	custo = 3*TORRE_CUSTO_PADRAO;
	
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_TORRE_BOMBARDEIRO,posX, posY);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do atiradorSimples! não houve memoria suficiente!");
	}
}

//limpa a memoria
Bombardeiro::~Bombardeiro()
{
	delete this->img;
}

