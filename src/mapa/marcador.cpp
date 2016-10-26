
#include"fileNotFoundException.h"
#include"tela.h"
#include"mapa.h"
#include"constantes.h"
#include"nomesArquivos.h"
#include"marcador.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<string>

SDL_Surface* Marcador::marcadorUsado = NULL;
SDL_Surface* Marcador::marcadorAzul = NULL;
SDL_Surface* Marcador::marcadorVermelho = NULL;
int Marcador::posX = VALOR_DEFAULT_X;
int Marcador::posY = VALOR_DEFAULT_Y;
	
//construtor privado para implementação do singleton (essa classe não deve ter objetos, apenas chamadas estáticas)
Marcador::Marcador(){}

//carrega as imagens no jogo
void Marcador::criaMarcadores()throw(FileNotFoundException)
{
	marcadorAzul = IMG_Load( (PATH + ARQUIVO_MARCADOR_AZUL).c_str() );
	if(!marcadorAzul)
		throw FileNotFoundException( string("Falha ao tentar carregar o seguinte arquivo: ") + ARQUIVO_MARCADOR_AZUL);
	marcadorVermelho = IMG_Load( (PATH + ARQUIVO_MARCADOR_VERMELHO).c_str() );
	if(!marcadorVermelho)
		throw FileNotFoundException( string("Falha ao tentar carregar o seguinte arquivo: ") + ARQUIVO_MARCADOR_VERMELHO);
	marcadorUsado = marcadorAzul;
}

//imprime o marcador novamente quando a tela for limpada a cada frame
void Marcador::print()
{
	SDL_Rect rect;
	rect.x = posX-(marcadorUsado->w/2), rect.y = posY-(marcadorUsado->h/2), rect.w = marcadorUsado->w, rect.h = marcadorUsado->h;
	SDL_BlitSurface(marcadorUsado,NULL,(SDL_Surface*)Tela::getTela(),&rect);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), rect.x, rect.y, rect.w, rect.h);
}

//move o marcador para a posição especificada e verifica qual dos marcadores deve ser mostrado
void Marcador::mover(int x, int y)
{
	Marcador::apagar();
	//atualiza a posição do marcador
	posX = x, posY = y;
	//verifica qual dos marcadores será impresso na tela
	bool booleano = Mapa::possoPorTorre(x, y);
	if(booleano)
		marcadorUsado = marcadorAzul;
	else
		marcadorUsado = marcadorVermelho;
}

//se apaga da tela
void Marcador::apagar()
{
	SDL_Rect rect;
	rect.x = posX-(marcadorUsado->w/2), rect.y = posY-(marcadorUsado->h/2), rect.w = marcadorUsado->w, rect.h = marcadorUsado->h;
	SDL_BlitSurface((SDL_Surface*)Mapa::getMapa(),&rect,(SDL_Surface*)Tela::getTela(),&rect);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), rect.x, rect.y, rect.w, rect.h);
}

//libera as surfaces criadas
void Marcador::destruirMarcadores()
{
	SDL_FreeSurface(marcadorAzul);
	SDL_FreeSurface(marcadorVermelho);
	marcadorAzul = marcadorVermelho = marcadorUsado = NULL;
}

