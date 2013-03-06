
#include "jogador.h"

int Jogador::moedas = VALOR_INICIAL_MOEDAS;
Jogador* Jogador::jogador = NULL;
//inicia o número de moedas que ele possui
Jogador::Jogador()
{
	moedas = MOEDAS_INICIAIS;
}

Jogador* Jogador::obterJogador(){
	if(jogador == NULL)
		jogador = new Jogador();
	
	return jogador; 
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

