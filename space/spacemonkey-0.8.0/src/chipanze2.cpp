
#include "inimigo.h"
#include "constantes.h"
#include "initException.h"
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
	
/*	try{
		this->img = new SDL_Sprite("inimigo.bmp",48, 32);//nome do arquivo e as dimensões de cada desenho da sprite
		this->img->init(1,1, Direcao dir=BAIXO);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do orangotango! não houve memoria suficiente!");
	}*/
	
}

//limpa a memoria
Chipanze2::~Chipanze2()
{
	delete this->img;
}

//move o inimigo
void Chipanze2::mover(Direcao dir){
	this->img->mover(dir, this->vel);
}

void Chipanze2::mover(){}

//retorna o quanto de vida resta
int Chipanze2::getHp()
{
	return this->hp_restante;
}

//retorna o dano que o inimigo causa
int Chipanze2::getDano()
{
	return this->dano;
}

//retorna o numero de quadrados que o inimigo anda
int Chipanze2::getVel()
{
	return this->vel;
}

