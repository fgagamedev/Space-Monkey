#include<iostream>

#include "SDL_Mapa.h"
#include "constantes.h"
#include "tela.h"
#include "fileNotFoundException.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface* SDL_Mapa::img_mapa = NULL;
bool** SDL_Mapa::mapaLogico = NULL;
int SDL_Mapa::goalX = 0;
int SDL_Mapa::goalY = 0;


void SDL_Mapa::inicializaMapaLogico()
{
	//bota 0 em tudo
	int i, j;
	for(i=0; i<TAMANHO_MATRIZ_LOGICA_X; i++)
	{
		for(j=0; j<TAMANHO_MATRIZ_LOGICA_Y; j++)
		{
			mapaLogico[i][j] = false;
		}
	}
	//bota 1 onde for estrada
	for(i=0; i<300/TAMANHO_QUADRADO; i++)
		mapaLogico[i][1] = true;
	for(i=2; i<300/TAMANHO_QUADRADO; i++)
		mapaLogico[9][i] = true;
	for(i=10; i<540/TAMANHO_QUADRADO; i++)
		mapaLogico[i][9] = true;
	for(i=10; i<20; i++)
		mapaLogico[17][i] = true;
		
}

bool SDL_Mapa::getMapaLogico(int x, int y, Direcao dir)
{
	switch(dir)
	{
	case BAIXO:
		return mapaLogico[x][y+1];
		break;
	case ACIMA:
		return mapaLogico[x][y-1];
		break;
	case ESQUERDA:
		return mapaLogico[x-1][y];
		break;
	case DIREITA:
		return mapaLogico[x+1][y];
		break;
	case ACIMA_ESQUERDA:
		return mapaLogico[x-1][y-1];
		break;
	case ACIMA_DIREITA:
		return mapaLogico[x+1][y-1];
		break;
	case BAIXO_ESQUERDA:
		return mapaLogico[x-1][y+1];
		break;
	case BAIXO_DIREITA:
		return mapaLogico[x+1][y+1];
		break;	
	}
	return mapaLogico[x][y];
}

void SDL_Mapa::defineGoal(string nome_mapa)
{
	const char *nome = nome_mapa.c_str();
	if(nome == NOME_MAPA1)
		goalX = FASE1_GOALX, goalY = FASE1_GOALY;
	else if(nome == NOME_MAPA2)
		goalX = FASE2_GOALX, goalY = FASE2_GOALY;
	else if(nome == NOME_MAPA3)
		goalX = FASE3_GOALX, goalY = FASE3_GOALY;
	else if(nome == NOME_MAPA4)
		goalX = FASE4_GOALX, goalY = FASE4_GOALY;
	else if(nome == NOME_MAPA5)
		goalX = FASE5_GOALX, goalY = FASE5_GOALY;
	else if(nome == NOME_MAPA6)
		goalX = FASE6_GOALX, goalY = FASE6_GOALY;
	else if(nome == NOME_MAPA7)
		goalX = FASE7_GOALX, goalY = FASE7_GOALY;
	else if(nome == NOME_MAPA8)
		goalX = FASE8_GOALX, goalY = FASE8_GOALY;
	
}

int SDL_Mapa::getGoalX()
{
	return goalX;
}

int SDL_Mapa::getGoalY()
{
	return goalY;
}

//carrega o arquivo com o desenho do mapa. Se der errado lança uma exceção
void SDL_Mapa::loadMap(string nome_mapa) throw (FileNotFoundException)
{
	if( SDL_Mapa::mapaCarregado() )
		return;

	img_mapa = IMG_Load( (PATH + nome_mapa).c_str() );
	if(!img_mapa)
		throw FileNotFoundException( string("Falha ao tentar carregar o seguinte arquivo: ") + nome_mapa);


	mapaLogico = new bool*[TAMANHO_MATRIZ_LOGICA_X];	
	int i;
	for(i=0; i<TAMANHO_MATRIZ_LOGICA_X; i++)
		mapaLogico[i] = new bool[TAMANHO_MATRIZ_LOGICA_Y];
	inicializaMapaLogico();
	defineGoal(nome_mapa);
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
/*	SDL_BlitSurface(img_mapa,NULL, (SDL_Surface*)Tela::getTela(),NULL);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), 0, 0, 0, 0);*/
	
	drawMapaFeio();
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

