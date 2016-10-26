#ifndef INIMIGO_h
#define INIMIGO_h

#include "initException.h"
#include "constantes.h"
#include "sprite.h"
#include "SDL_Sprite.h"
#include "fileNotFoundException.h"

class Inimigo
{
protected:
	int HP;
	int dano;
	int vel;
	int hp_restante;
	SDL_Sprite *img;
public:
	//inicializa os valores do inimigo
	virtual void init() throw (InitException, FileNotFoundException) = 0;
	//destrutor
	~Inimigo();
	//retorna o quanto de vida resta
	int getHp() const;
	//retorna o dano que o inimigo causa
	int getDano() const;
	//retorna o numero de quadrados que o inimigo anda
	int getVel() const;
	//movimenta o inimigo
	void mover(Direcao dir);
	void mover();
	Direcao direcao_a_ser_movido(int dirX, int dirY);
	//retira o desenho do inimigo da tela
	void limparTela();
	//verifica se o HP restante é 0 (se morreu)
	bool isDead();
	//verifica se chegou ao ponto final
	bool chegouPontoFinal();
};


#endif

