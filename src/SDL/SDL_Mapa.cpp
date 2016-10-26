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

#include "definicoesMapaLogico.cpp"

SDL_Surface* SDL_Mapa::img_mapa = NULL;
char** SDL_Mapa::mapaLogico = NULL;
int SDL_Mapa::goalX = VALOR_DEFAULT_ZERO;
int SDL_Mapa::goalY = VALOR_DEFAULT_ZERO;

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
	
	
	nomesArquivos_montaMapaLogicoGeral(Fase::getFaseAtual(), mapaLogico);
		
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

//desenha o mapa na tela
void SDL_Mapa::desenhaMapa()
{
	SDL_BlitSurface(img_mapa,NULL, (SDL_Surface*)Tela::getTela(),NULL);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), 0, 0, 0, 0);
	
}

//retorna a superficie do mapa
void* SDL_Mapa::getMapa()
{
	return img_mapa;
}

bool SDL_Mapa::mapaCarregado()
{
	int imagemCarregada = false;
	if(img_mapa)
	{
		imagemCarregada = true;
	}
	else
	{
		imagemCarregada = false;
	}

	return imagemCarregada;
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
	TTF_Font *font = Util::getFonte(TAMANHO_FONTE);
	int alpha = 255;
	SDL_Color white = {0, 0, 0, alpha};	 
	SDL_Surface *renderedText = TTF_RenderText_Blended(font, "Moedas do Jogador: ", white);

	if (!renderedText) {
		TTF_CloseFont(font);
		return;
	}

	//determina area de trabalho
	SDL_Rect dest;
	SDL_Surface *tela = (SDL_Surface*)Tela::getTela();
	int areaY = 30;
	dest.x = tela->w -renderedText->w - 10, dest.y = areaY, dest.w = renderedText->w, dest.h = renderedText->h;
	//apaga o texto atual
	SDL_BlitSurface((SDL_Surface*)Mapa::getMapa(), &dest, tela, &dest);
	
	//escreve o texto certo
	SDL_BlitSurface(renderedText, NULL, tela, &dest);
	SDL_UpdateRect(tela,dest.x,dest.y,dest.w, dest.h);
	
	SDL_FreeSurface(renderedText);
	TTF_CloseFont(font);
}

bool SDL_Mapa::verificaPosicaoTorre(int xMouse, int yMouse){
	int posicaoRealX = xMouse/TAMANHO_QUADRADO;
	int posicaoRealY = yMouse/TAMANHO_QUADRADO;
	
	if(possoPorTorre(posicaoRealX,posicaoRealY)){
		return true;
	}
	else{
		return false;
	}	
	
}

void SDL_Mapa::alteraEstadoMapaLogico(int posX,int posY, char novoEstado){
	
	mapaLogico[posX][posY] = novoEstado;

}
