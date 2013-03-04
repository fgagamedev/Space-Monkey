
#include "inimigo.h"
#include "constantes.h"
#include "initException.h"
#include "nomesArquivos.h"
#include "SDL_Sprite.h"
#include "fileNotFoundException.h"
#include "gorila1.h"

//inicializa os valores do inimigo
void Gorila1::init() throw (InitException, FileNotFoundException)
{
	this->HP = 3*INIMIGO_HP_PADRAO;
	this->dano = 2*INIMIGO_DANO_PADRAO;
	this->vel = 2*INIMIGO_VEL_PADRAO/3;
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_GORILA1,19, 30);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do orangotango! não houve memoria suficiente!");
	}
	
}



