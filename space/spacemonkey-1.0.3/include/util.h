#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include <SDL/SDL_ttf.h>
#include"fileNotFoundException.h"

//classe de funções estáticas uteis
class Util{
public:
	//para a execução pelos milissegundos pedidos
	static void delay(int mili);
	static TTF_Font* getFonte(int size)throw(FileNotFoundException);
};

#endif
