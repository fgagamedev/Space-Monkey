#ifndef CLASS_JOGADOR
#define CLASS_JOGADOR

using namespace std;

/**
classe que representa o jogador
*/
class Jogador
{
private:
	int moedas;
	static const int MOEDAS_INICIAIS = 100;
public:
	//inicia o número de moedas que ele possui
	Jogador();
	//retorna o nº de moedas que ele possui
	int getMoedas();
	//soma coins moedas ao total que o jogador possui
	void ganharMoedas(int coins);
	//subtrai coins moedas ao total que o jogador possui
	void perderMoedas(int coins);
};


#endif

