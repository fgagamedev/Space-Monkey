#include <iostream>
#include <stdlib.h>
using namespace std;
#include "inimigo.h"
#include "mapa.h"

Inimigo::~Inimigo()
{
	delete this->img;
}


int Inimigo::getHp() const 
{
	return this->hp_restante;
}

//retorna o dano que o inimigo causa
int Inimigo::getDano() const
{
	return this->dano;
}

//retorna o numero de quadrados que o inimigo anda
int Inimigo::getVel() const
{
	return this->vel;
}

//move o inimigo
void Inimigo::mover(Direcao dir){
	this->img->mover(dir, this->vel);
}

Direcao Inimigo::direcao_a_ser_movido(int dirX, int dirY)
{
	Direcao dir = BAIXO;
	if(dirX>0 && dirY>0)
		dir = BAIXO_DIREITA;
	else if(dirX>0 && dirY==0)
		dir = DIREITA;
	else if(dirX>0 && dirY<0)
		dir = ACIMA_DIREITA;
	else if(dirX==0 && dirY>0)
		dir = BAIXO;
	else if(dirX==0 && dirY<0)
		dir = ACIMA;
	else if(dirX<0 && dirY>0)
		dir = BAIXO_ESQUERDA;
	else if(dirX<0 && dirY==0)
		dir = ESQUERDA;
	else if(dirX<0 && dirY<0)
		dir = ACIMA_ESQUERDA;
	
	return dir;
}

void Inimigo::mover(){
	//vê a direção do objetivo da fase
	int direcaoX = Mapa::getGoalX();
	int direcaoY = Mapa::getGoalY();
	//vê sua posição
	int x = this->img->getX();
	int y = this->img->getY();
	//compara as duas pra ver pra onde vai
	int dirX = (direcaoX>x ? 1: (direcaoX<x ? -1: 0));
	int dirY = (direcaoY>y ? 1: (direcaoY<y ? -1: 0));	
	Direcao dir = direcao_a_ser_movido(dirX,dirY);
	//verifica se pode ir nessa direção
	bool pode = Mapa::getMapaLogico(x/TAMANHO_QUADRADO, y/TAMANHO_QUADRADO, dir);
	if(pode)
		this->mover(dir);
	else
	{
		//caso o movimento desejado não possa, tenta pros movimentos semelhantes
		int dy;
		switch(dirY)
		{
		case 1:
		case -1:
			dy = -dy;
			break;
		case 0:
			dy = rand()%2 ? 1 : -1;
			break;
		} 
		dir = direcao_a_ser_movido(dirX, dy);
		pode = Mapa::getMapaLogico(x/TAMANHO_QUADRADO, y/TAMANHO_QUADRADO, dir);
		if(pode)
			this->mover(dir);
		else
		{
			int dx;
			switch(dirX)
			{
			case 1:
			case -1:
				dx= -dx;
				break;
			case 0:
				dx = rand()%2 ? 1 : -1;
				break;
			}
			dir = direcao_a_ser_movido(dx, dirY);
			pode = Mapa::getMapaLogico(x/TAMANHO_QUADRADO, y/TAMANHO_QUADRADO, dir);
			if(pode)
				this->mover(dir);
			else
			{
				dir = direcao_a_ser_movido(dx, dy);
				pode = Mapa::getMapaLogico(x/TAMANHO_QUADRADO, y/TAMANHO_QUADRADO, dir);
				if(pode)
					this->mover(dir);
			}
		}
	}
	
}

//retira o desenho do inimig da tela
void Inimigo::limparTela()
{
	this->img->apagarSprite();
}

//verifica se o HP restante é 0 (se morreu)
bool Inimigo::isDead()
{
	if(hp_restante <= 0)
		return true;
	return false;
}

//verifica se chegou ao ponto final
bool Inimigo::chegouPontoFinal()
{
	//vê sua posição em quadrados
	int x = this->img->getX()/TAMANHO_QUADRADO;
	int y = this->img->getY()/TAMANHO_QUADRADO;
	//vê a posição do objetivo final  em quadrados
	int direcaoX = Mapa::getGoalX()/TAMANHO_QUADRADO;
	int direcaoY = Mapa::getGoalY()/TAMANHO_QUADRADO;
	//verifica se já chegou nela
	if(x==direcaoX && (y==direcaoY || y==direcaoY-1 || y==direcaoY+1))
		return true;
	return false;
}


