#ifndef TELA_H
#define TELA_H

#include "initException.h"

using namespace std;

/**
classe controladora que acessa a classe criadora da janela. Só serve de intermediária entre a aplicação e a Tela para facilitar portabilidade. Se qualquer classe quiser a tela pede a controladora em vez de acessar direto e caso queira trocar de API gráfica só precisa mudar as implementações desta classe
*/
class Tela
{
public:
	//método que cria ou devolve a tela já criada
	static Tela* obterTela() throw (InitException);
	//método que desaloca a tela (chamado ao fim do jogo)
	static void liberarTela();
	//devolve a tela do jogo (usado por classes de mais baixo nível). É preciso fazer typecast para a classe ou struct usada pela respectiva API
	static void* getTela();	
};

#endif
