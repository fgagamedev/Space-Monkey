#include "inimigo.h"
#include "mapa.h"


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
			dy = 0;
			break;
		case 0:
			dy = 1;
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
				dx= 0;
				break;
			case 0:
				dx = 1;
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

