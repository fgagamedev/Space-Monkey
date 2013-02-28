
#include "inimigo.h"
#include "constantes.h"
#include "initException.h"
#include "SDL_Sprite.h"
#include "fileNotFoundException.h"
#include "gorila2.h"

//inicializa os valores do inimigo
void Gorila2::init() throw (InitException, FileNotFoundException)
{
	this->HP = 4*INIMIGO_HP_PADRAO;
	this->dano = 3*INIMIGO_DANO_PADRAO;
	this->vel = INIMIGO_VEL_PADRAO;
	this->hp_restante  = this->HP;
	
/*	try{
		this->img = new SDL_Sprite("inimigo.bmp",48, 32);//nome do arquivo e as dimensões de cada desenho da sprite
		this->img->init(1,1, Direcao dir=BAIXO);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do orangotango! não houve memoria suficiente!");
	}*/
	
}

//limpa a memoria
Gorila2::~Gorila2()
{
	delete this->img;
}

//move o inimigo
void Gorila2::mover(Direcao dir){
	this->img->mover(dir, this->vel);
}

void Gorila2::mover(){}

//retorna o quanto de vida resta
int Gorila2::getHp()
{
	return this->hp_restante;
}

//retorna o dano que o inimigo causa
int Gorila2::getDano()
{
	return this->dano;
}

//retorna o numero de quadrados que o inimigo anda
int Gorila2::getVel()
{
	return this->vel;
}

