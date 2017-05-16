// #include <iostream>
// #include <SDL/SDL.h>

// #include "Tela.h"
// #include "mapa.h"
// #include "SDL_Mapa.h"
// #include "orangotango.h"
// #include "fileNotFoundException.h"
// #include "initException.h"
// #include "jogo.cpp"

// using namespace std;

// int main()
// {
// 	try{
// 		Tela::obterTela();
// 		Mapa *map = new SDL_Mapa("mapa1.bmp");
// 		map->desenhaMapa();

// 		Inimigo *orangotango = new Orangotango();
// 		orangotango->init();

// 		SDL_Delay(1000);

// 		orangotango->mover(Direcao dir=BAIXO);

// 		SDL_Delay(1000);

// 		orangotango->mover(Direcao dir=BAIXO);

// 	}catch(Exception &e){
// 		cout << e.getMessage(); << endl;
// 	}

// 	return 0;
// }


