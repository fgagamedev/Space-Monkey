
#include <iostream>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <time.h>

#include "tela.h"
#include "mapa.h"
#include "SDL_Mapa.h"
#include "orangotango.h"
#include "fileNotFoundException.h"
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
		Mapa::loadMap("mapa1.bmp");
		Mapa::desenhaMapa();
cout << "mapa carregado" << endl;	
		Inimigo *orangotango = new Orangotango();
		orangotango->init();
cout << "sprite carregado" << endl;		
		SDL_Delay(100);		
		Direcao dir;
		int i;
		for(i=0; i<100; i++){
			dir = direcaoAleatoria();
			orangotango->mover(dir);
			SDL_Delay(100);
		}
		
	}catch(Exception &e){
		cout << e.getMessage() << endl;
	}
	
	return 0;
}



