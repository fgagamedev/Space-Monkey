#include<stdio.h>
#include<iostream>
using namespace std;

#include "SDL_Mapa.h"
#include "constantes.h"
#include"util.h"
#include"jogador.h"
#include "nomesArquivos.h"
#include "tela.h"
#include "fase.h"
#include "fileNotFoundException.h"
#include "nomesArquivos.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "src/mapa/definicoesMapaLogico.cpp"

SDL_Surface* SDL_Mapa::img_mapa = NULL;
char** SDL_Mapa::mapaLogico = NULL;
int SDL_Mapa::goalX = 0;
int SDL_Mapa::goalY = 0;

//carrega o arquivo com o desenho do mapa. Se der errado lança uma exceção
void SDL_Mapa::loadMap(string nome_mapa) throw (FileNotFoundException)
{
	if( SDL_Mapa::mapaCarregado() )
		return;

	img_mapa = IMG_Load( (PATH + nome_mapa).c_str() );
	if(!img_mapa)
		throw FileNotFoundException( string("Falha ao tentar carregar o seguinte arquivo: ") + nome_mapa);


	inicializaMapaLogico();
	defineGoal();
}

void SDL_Mapa::inicializaMapaLogico()
{
	//instancia a matriz 
	mapaLogico = new char*[TAMANHO_MATRIZ_LOGICA_X];	
	int i, j;
	for(i=0; i<TAMANHO_MATRIZ_LOGICA_X; i++)
		mapaLogico[i] = new char[TAMANHO_MATRIZ_LOGICA_Y];	
	
	//bota 0 em tudo
	for(i=0; i<TAMANHO_MATRIZ_LOGICA_X; i++)
	{
		for(j=0; j<TAMANHO_MATRIZ_LOGICA_Y; j++)
		{
			mapaLogico[i][j] = MAPA;
		}
	}
	//bota 1 onde for estrada
	nomesArquivos_montaMapaLogico(mapaLogico, Fase::getFaseAtual() );
		
}

//retorna o valor de uma pos
bool SDL_Mapa::getMapaLogico(int x, int y, Direcao dir)
{
	switch(dir){
		case BAIXO:
			return mapaLogico[x][y+1] == ESTRADA;
		case ACIMA:
			return mapaLogico[x][y-1] == ESTRADA;
		case ESQUERDA:
			return mapaLogico[x-1][y] == ESTRADA;
		case DIREITA:
			return mapaLogico[x+1][y] == ESTRADA;
		case ACIMA_ESQUERDA:
			return mapaLogico[x-1][y-1] == ESTRADA;
		case ACIMA_DIREITA:
			return mapaLogico[x+1][y-1] == ESTRADA;
		case BAIXO_ESQUERDA:
			return mapaLogico[x-1][y+1] == ESTRADA;
		case BAIXO_DIREITA:
			return mapaLogico[x+1][y+1] == ESTRADA;
	}
	return mapaLogico[x][y] == ESTRADA;
}

bool SDL_Mapa::possoPorTorre(int x, int y)
{
	int matrizX = x/TAMANHO_QUADRADO;
	int matrizY = y/TAMANHO_QUADRADO;
	
	return mapaLogico[matrizX][matrizY] == TORRE;
}

void SDL_Mapa::defineGoal()
{
	int i = Fase::getFaseAtual();
	
	goalX = GOALS_X[i];
	goalY = GOALS_Y[i];
	
}

int SDL_Mapa::getGoalX()
{
	return goalX;
}

int SDL_Mapa::getGoalY()
{
	return goalY;
}

void drawMapaFeio()
{
	Uint32 cor = SDL_MapRGB(((SDL_Surface*)Tela::getTela())->format, 255, 255, 255);
	
	SDL_Rect r, r2, r3, r4;
	r.x = 0, r.y = 30, r.w = 300, r.h = 30;
	r2.x = 270, r2.y = 60, r2.w = 30, r2.h = 240;
	r3.x = 300, r3.y = 270, r3.w = 240, r3.h = 30;
	r4.x = 510, r4.y = 300, r4.w = 30, r4.h = 300;
	
	SDL_FillRect((SDL_Surface*)Tela::getTela(), &r, cor);
	SDL_FillRect((SDL_Surface*)Tela::getTela(), &r2, cor);
	SDL_FillRect((SDL_Surface*)Tela::getTela(), &r3, cor);
	SDL_FillRect((SDL_Surface*)Tela::getTela(), &r4, cor);
	
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), 0, 0, 0, 0);
}

//desenha o mapa na tela
void SDL_Mapa::desenhaMapa()
{
	SDL_BlitSurface(img_mapa,NULL, (SDL_Surface*)Tela::getTela(),NULL);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), 0, 0, 0, 0);
	
//	drawMapaFeio();
}

//retorna a superficie do mapa
void* SDL_Mapa::getMapa()
{
	return img_mapa;
}

bool SDL_Mapa::mapaCarregado()
{
	return img_mapa ? true : false;
}

void SDL_Mapa::liberaMapa()
{
	if(SDL_Mapa::mapaCarregado())
	{
		int i;
		for(i=0; i<TAMANHO_MATRIZ_LOGICA_X; i++)
			delete[] mapaLogico[i];
		delete[] mapaLogico;
		SDL_FreeSurface(img_mapa);
		img_mapa = NULL;
	}	
}

void SDL_Mapa::printCoins() throw(FileNotFoundException)
{
	//carrega a fonte e o texto
	TTF_Font *font = Util::getFonte(30);
	
	SDL_Color white = {0, 0, 0, 255};	 
	SDL_Surface *renderedText = TTF_RenderText_Blended(font, "Moedas do Jogador: ", white);

	if (!renderedText) {
		TTF_CloseFont(font);
		return;
	}

	//determina area de trabalho
	SDL_Rect dest;
	SDL_Surface *tela = (SDL_Surface*)Tela::getTela();
	dest.x = tela->w -renderedText->w - 10, dest.y = 30, dest.w = renderedText->w, dest.h = renderedText->h;
	//apaga o texto atual
	SDL_BlitSurface((SDL_Surface*)Mapa::getMapa(), &dest, tela, &dest);
	
	//escreve o texto certo
	SDL_BlitSurface(renderedText, NULL, tela, &dest);
	SDL_UpdateRect(tela,dest.x,dest.y,dest.w, dest.h);
	
	SDL_FreeSurface(renderedText);
	TTF_CloseFont(font);
}

