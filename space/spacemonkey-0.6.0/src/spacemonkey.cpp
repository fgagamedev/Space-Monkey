#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "jogo.cpp"

int main()
{
	//cria um jogo e o executa
	Jogo spaceMonkey;
	spaceMonkey.rodarJogo();
	//o jogo já acabou, então encerra o programa também
	return 0;
}


