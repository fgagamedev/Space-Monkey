

#include "jogador.h"

int Jogador::moedas = 0;

//inicia o número de moedas que ele possui
Jogador::Jogador()
{
	this->moedas = MOEDAS_INICIAIS;
}

//retorna o nº de moedas que ele possui
int Jogador::getMoedas()
{
	return moedas;
}

//soma coins moedas ao total que o jogador possui
void Jogador::ganharMoedas(int coins)
{
	moedas += coins;
}

//subtrai coins moedas ao total que o jogador possui
void Jogador::perderMoedas(int coins)
{
	moedas -= coins;
}

