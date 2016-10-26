#ifndef TELA_H
#define TELA_H

#include "initException.h"

using namespace std;

/**
classe controladora que acessa a classe criadora da janela. S� serve de intermedi�ria entre a aplica��o e a Tela para facilitar portabilidade. Se qualquer classe quiser a tela pede a controladora em vez de acessar direto e caso queira trocar de API gr�fica s� precisa mudar as implementa��es desta classe
*/
class Tela
{
public:
	//m�todo que cria ou devolve a tela j� criada
	static Tela* obterTela() throw (InitException);
	//m�todo que desaloca a tela (chamado ao fim do jogo)
	static void liberarTela();
	//devolve a tela do jogo (usado por classes de mais baixo n�vel). � preciso fazer typecast para a classe ou struct usada pela respectiva API
	static void* getTela();	
};

#endif
