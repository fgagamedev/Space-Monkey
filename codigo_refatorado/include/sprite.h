#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include "constantes.h"

class Sprite
{
protected:
	
public:
	//o coloca na tela, fazendo-o aparecer  pela primeira vez no jogo virado pro lado certo (dir)
	virtual void init(Direcao dir) = 0;
	//ativa a colorkey, sumindo com a cor de fundo
	virtual void ativarTransparencia() = 0;	
	//pega uma parte especifica da sprite (um dos desenhos)e a atualiza na tela
	virtual void mover(Direcao dir, int numPixels) = 0;
	//apaga o sprite da tela
	virtual void apagarSprite() = 0;
	//retorna informações de posição para o inimigo
	virtual int getW() = 0;
	virtual int getH() = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
};

#endif

