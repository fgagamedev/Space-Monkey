#ifndef CLASS_JOGADOR
#define CLASS_JOGADOR

#include <stdio.h>

using namespace std;

/**
classe que representa o jogador
*/
class Jogador
{
private:
	static int moedas;
	static const int MOEDAS_INICIAIS = 100;
	static Jogador* jogador;
	//inicia o número de moedas que ele possui
	Jogador();
public:
	// Obtendo jogador
	static Jogador* obterJogador();
	//retorna o nº de moedas que ele possui
	static int getMoedas();
	//soma coins moedas ao total que o jogador possui
	static void ganharMoedas(int coins);
	//subtrai coins moedas ao total que o jogador possui
	static void perderMoedas(int coins);
};


#endif

