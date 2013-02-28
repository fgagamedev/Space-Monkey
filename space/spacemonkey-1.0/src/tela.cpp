
#include "tela.h"
#include "SDL_Tela.h"
#include "constantes.h"
#include "initException.h"
#include <string>

static Tela *instancia = NULL;

//obtem a Tela já instanciada ou cria a tela
Tela* Tela::obterTela() throw (InitException)
{
	return SDL_Tela::obterTela();
}

//deleta a tela criada. Chamado só no fim do programa
void Tela::liberarTela()
{
	SDL_Tela::liberarTela();
}

//retorna a estrutura usada para criar a tela (é preciso fazer o typecast nas outras classes que envolvam SDL)
void* Tela::getTela()
{
	return SDL_Tela::getTela();
}

