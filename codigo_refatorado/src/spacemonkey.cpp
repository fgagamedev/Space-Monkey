
#include "jogo.cpp"

int main()
{
	//cria um jogo e o executa
	Jogo spaceMonkey;
	spaceMonkey.rodarJogo();
	//o jogo já acabou, então encerra o programa também
	return 0;
}


/*#include <iostream>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <time.h>

#include "tela.h"
#include "mapa.h"
#include "SDL_Mapa.h"
#include "orangotango.h"
#include "fileNotFoundException.h"
#include "nomesArquivos.h"
#include "initException.h"
#include "jogo.cpp"

using namespace std;

Direcao direcaoAleatoria()
{
	Direcao dir = BAIXO;
	int x = rand()%8;
	switch(x)
	{
	case 0:
		dir = BAIXO;
		break;
	case 1:
		dir = ACIMA;
		break;
	case 2:
		dir = ESQUERDA;
		break;
	case 3:
		dir = DIREITA;
		break;
	case 4:
		dir = ACIMA_ESQUERDA;
		break;
	case 5:
		dir = ACIMA_DIREITA;
		break;
	case 6:
		dir = BAIXO_ESQUERDA;
		break;
	case 7:
		dir = BAIXO_DIREITA;
		break;
	}
	return dir;
}

int main()
{
	srand(time(NULL));
	try{
		Tela::obterTela();
		Mapa::loadMap(NOME_MAPA1);
		Mapa::desenhaMapa();	
		Inimigo *orangotango = new Orangotango();
		orangotango->init();

		int i;
		for(i=0; i<150; i++){
			orangotango->mover();
			SDL_Delay(100);
		}
		
	}catch(Exception &e){
		cout << e.getMessage() << endl;
	}
	
	return 0;
}
*/




