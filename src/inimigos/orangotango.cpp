
#include <math.h>
#include "mapa.h"
#include "inimigo.h"
#include "SDL_Sprite.h"
#include "constantes.h"
#include "nomesArquivos.h"
#include "initException.h"
#include "fileNotFoundException.h"
#include "orangotango.h"

//inicializa os valores do inimigo
void Orangotango::init() throw (InitException, FileNotFoundException)
{
	this->HP = 2*INIMIGO_HP_PADRAO;
	this->dano = INIMIGO_DANO_PADRAO;
	this->vel = 2*INIMIGO_VEL_PADRAO;
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_ORANGOTANGO,TAM_X_SPRITE_CHIMPANZE, TAM_X_SPRITE_CHIMPANZE);
		Direcao dir=DIREITA;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do orangotango! não houve memoria suficiente!");
	}
	
}




