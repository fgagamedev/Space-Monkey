
#include "inimigo.h"
#include "constantes.h"
#include "initException.h"
#include "nomesArquivos.h"
#include "mapa.h"
#include "SDL_Sprite.h"
#include "fileNotFoundException.h"
#include "chipanze2.h"

//inicializa os valores do inimigo
void Chipanze2::init() throw (InitException, FileNotFoundException)
{
	this->HP = INIMIGO_HP_PADRAO;
	this->dano = INIMIGO_DANO_PADRAO;
	this->vel = INIMIGO_VEL_PADRAO*3;
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_CHIPANZE2,TAM_X_SPRITE_CHIMPANZE, TAM_Y_SPRITE_CHIMPANZE);
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do orangotango! não houve memoria suficiente!");
	}
	
}


