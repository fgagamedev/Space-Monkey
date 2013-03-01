
#include "torre.h"

int Torre::custo = 0;

//retorna o quanto de vida resta
int Torre::getHp() const
{
	return this->hp_restante;
}

//retorna o dano que a torre causa
int Torre::getDano() const
{
	return this->dano;
}

//retorna o numero de quadrados que o tiro da torre alcance
int Torre::getAlcance() const
{
	return this->alcance;
}

//reorna o custo de construção da torre
int Torre::getCusto()
{
	return custo;
}

