
//#include "tela.h"
#include "SDL_Tela.h"
#include "constantes.h"
#include "initException.h"
#include "nomesArquivos.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

SDL_Surface* SDL_Tela::telaJogo = NULL;
SDL_Tela* SDL_Tela::instancia = NULL;

SDL_Tela::SDL_Tela() 
{
	video_options = SDL_HWSURFACE | SDL_DOUBLEBUF;
}

void SDL_Tela::init() throw (InitException)
{
	this->telaJogo = SDL_SetVideoMode(TELA_WIDTH, TELA_HEIGHT, TELA_BPP, video_options);
	
	if( !(this->telaJogo) )
		throw InitException( string("Falha ao iniciar o video com essas configuracoes: ") + string(SDL_GetError()) );
}

Tela* SDL_Tela::obterTela() throw (InitException)
{
	if( instancia == NULL)
	{
		instancia = new SDL_Tela();
		instancia->init();
	}	
	return instancia;
}

bool SDL_Tela::foiInstanciado()
{
	if(telaJogo != NULL && instancia != NULL)
		return true;
	return false;
}

void SDL_Tela::liberarTela()
{
	if( instancia->foiInstanciado() )
	{
		SDL_FreeSurface(telaJogo);
		telaJogo = NULL;
		delete (instancia);
		instancia = NULL;
	}
}


void* SDL_Tela::getTela()
{
	return telaJogo;
}

