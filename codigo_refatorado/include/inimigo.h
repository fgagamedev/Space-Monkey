#ifndef INIMIGO_h
#define INIMIGO_h

#include "initException.h"
#include "constantes.h"
#include "sprite.h"
#include "fileNotFoundException.h"

class Inimigo
{
protected:
	int HP;
	int dano;
	int vel;
	int hp_restante;
	Sprite *img;
public:
	//inicializa os valores do inimigo
	virtual void init() throw (InitException, FileNotFoundException) = 0;
	//retorna o quanto de vida resta
	virtual int getHp() = 0;
	//retorna o dano que o inimigo causa
	virtual int getDano() = 0;
	//retorna o numero de quadrados que o inimigo anda
	virtual int getVel() =  0;
	//movimenta o inimigo
	virtual void mover(Direcao dir) =  0;
	virtual void mover() = 0;
};


#endif

