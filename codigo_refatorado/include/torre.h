#ifndef TORRE_H
#define TORRE_H

#include "sprite.h"
#include "initException.h"
#include "fileNotFoundException.h"
#include "mapa.h"

class Torre
{
protected:
	int HP, dano, tempoRecarga, hp_restante, alcance;
	static int custo;
	Sprite *img;
public:
	//inicializa os valores do inimigo
	virtual void init(int posX,int posY) throw (InitException, FileNotFoundException) = 0;
	//retorna o quanto de vida resta
	int getHp() const;
	//retorna o dano que a torre causa
	int getDano() const;
	//retorna o numero de quadrados que o tiro da torre alcance
	int getAlcance() const;
	//reorna o custo de construção da torre
	static int getCusto();
	//chama o new para criar a torre caso haja dinheiro
	static Torre* createTorre(int tipoTorre,int xMouse, int yMouse);
	static bool possoCriar(int tipoTorre);
};

#endif

