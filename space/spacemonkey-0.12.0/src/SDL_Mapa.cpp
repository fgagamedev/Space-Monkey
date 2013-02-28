
#include "SDL_Mapa.h"
#include "constantes.h"
#include "nomesArquivos.h"
#include "tela.h"
#include "fase.h"
#include "fileNotFoundException.h"
#include "nomesArquivos.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

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
	for(i=0; i<6; i++)
		mapaLogico[i][1] = mapaLogico[i][2] = ESTRADA;
	mapaLogico[6][2] = mapaLogico[5][3] = mapaLogico[6][3] = mapaLogico[7][3] = mapaLogico[6][4] = mapaLogico[7][4] = mapaLogico[8][4] = mapaLogico[6][5] = mapaLogico[12][6] = ESTRADA;	
	for(i=7; i<12; i++)
		mapaLogico[i][5] = mapaLogico[i][6] =ESTRADA;	
	for(i=6; i<9; i++)
		mapaLogico[13][i] =mapaLogico[14][i] = ESTRADA;
	mapaLogico[15][7] =mapaLogico[15][8] = ESTRADA;
	for(i=14; i<=16; i++)
		mapaLogico[i][9] =mapaLogico[i][10] = ESTRADA;
	mapaLogico[17][10] = mapaLogico[18][9] = mapaLogico[19][9] = ESTRADA;
	for(i=18; i<=20; i++)
		mapaLogico[i][11] =mapaLogico[i][12] = ESTRADA;
	mapaLogico[20][12] = mapaLogico[19][13] = mapaLogico[18][13] = ESTRADA;
	for(i=13; i<18; i++)
		mapaLogico[19][i] = mapaLogico[20][i] = ESTRADA;
	mapaLogico[21][17] = ESTRADA;
	for(i=20; i<24; i++)
		mapaLogico[i][18] =mapaLogico[i][19]= ESTRADA;
		
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

