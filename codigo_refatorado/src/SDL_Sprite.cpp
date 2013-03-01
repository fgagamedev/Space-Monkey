#include <iostream>
#include "SDL_Sprite.h"
#include "constantes.h"
#include "SDL_Mapa.h"
#include "tela.h"
#include "fileNotFoundException.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

//carrega o arquivo com o desenho do sprite e guarda o tamanho de cada imagem dela (w e h). Se der errado lança uma exceção
SDL_Sprite::SDL_Sprite(string nome_arquivo, int w, int h) throw (FileNotFoundException)
{
	sprite = IMG_Load( (PATH + nome_arquivo).c_str() );
	if(!sprite)
		throw FileNotFoundException( string("Falha ao tentar carregar o seguinte arquivo: ") + nome_arquivo);
	
	this->w = w;
	this->h = h;
	
	//this->ativarTransparencia();
}

//ativa a colorkey, sumindo com a cor de fundo
void SDL_Sprite::ativarTransparencia()
{
	this->COLORKEY.r = this->COLORKEY.g = this->COLORKEY.b = 255;
	const_cast <SDL_Color*> (&(this->COLORKEY));
	
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, COLORKEY.r, COLORKEY.g, COLORKEY.b));
	SDL_Surface *temp = SDL_DisplayFormat(sprite);
	SDL_FreeSurface(sprite);
	sprite = temp;
}

//o coloca na tela, fazendo-o aparecer  pela primeira vez no jogo na posição definida (x0 e y0) e virado pro lado certo (dir)
void SDL_Sprite::init(int x0, int y0, Direcao dir)
{
	this->x = x0, this->y = y0;

	SDL_Rect retangulo;//retangulo que informa a area que será atualizada
	retangulo.w = this->w, retangulo.h = this->h;
	retangulo.x = 0;
	switch(dir)
	{
	case BAIXO:
		retangulo.y = 0;
		break;
	case ACIMA:
		retangulo.y = this->h*3;
		break;
	case ESQUERDA:
		retangulo.y = this->h;
		break;
	case DIREITA:
		retangulo.y = this->h*2;
		break;
	case ACIMA_ESQUERDA:
		retangulo.y = this->h;
		break;
	case ACIMA_DIREITA:
		retangulo.y = this->h*2;
		break;
	case BAIXO_ESQUERDA:
		retangulo.y = this->h;
		break;
	case BAIXO_DIREITA:
		retangulo.y = this->h*2;
		break;	
	}
	//retangulo atualizado na tela
	SDL_Rect retangulo2;//retangulo que informa a area que será atualizada
	retangulo2.w = this->w, retangulo2.h = this->h;
	retangulo2.x = x0, retangulo2.y = y0;
	
	//SDL_BlitSurface(sprite,NULL, (SDL_Surface*)Tela::getTela(),NULL);
	SDL_BlitSurface(sprite,&retangulo, (SDL_Surface*)Tela::getTela(),&retangulo2);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), retangulo2.x, retangulo2.y, retangulo2.w, retangulo2.h);
}

//apaga o sprite da tela
void SDL_Sprite::apagarSprite()
{
/*	//pega o mapa original para re-escrever por cima do boneco
	SDL_Surface *tela = (SDL_Surface*)SDL_Mapa::getMapa();
	//pega a area  q deve ser reescrita
	SDL_Rect retangulo;//retangulo que informa a area que será atualizada
	retangulo.w = this->w, retangulo.h = this->h, retangulo.x = this->x, retangulo.y = this->y; 
	
	SDL_BlitSurface(tela,&retangulo, (SDL_Surface*)Tela::getTela(),&retangulo);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), retangulo.x, retangulo.y, retangulo.w, retangulo.h);*/
	
	Uint32 cor = SDL_MapRGB(((SDL_Surface*)Tela::getTela())->format, 255, 255, 255);
	SDL_Rect retangulo;//retangulo que informa a area que será atualizada
	retangulo.w = this->w, retangulo.h = this->h, retangulo.x = this->x, retangulo.y = this->y;
	SDL_FillRect((SDL_Surface*)Tela::getTela(), &retangulo, cor);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), retangulo.x, retangulo.y, retangulo.w, retangulo.h);
	
}

//move o sprite e atualiza o desenho mostrado de acordo com o movimento
void SDL_Sprite::mover(Direcao dir, int numPixels)
{
	//apaga o sprite atual da tela
	this->apagarSprite();
	//altera o desenho que aparece do sprite
	SDL_Rect retangulo;//retangulo que informa a area que será atualizada
	retangulo.w = this->w, retangulo.h = this->h;
	retangulo.x = retangulo.y = 0;
	switch(dir)
	{
	case BAIXO:
		retangulo.y = 0;
		this->y += numPixels;
		break;
	case ACIMA:
		retangulo.y = this->h*3;
		this->y -= numPixels;
		break;
	case ESQUERDA:
		retangulo.y = this->h;
		this->x -= numPixels;
		break;
	case DIREITA:
		retangulo.y = this->h*2;
		this->x += numPixels;
		break;
	case ACIMA_ESQUERDA:
		retangulo.y = this->h;
		this->y -= numPixels;
		this->x -= numPixels;
		break;
	case ACIMA_DIREITA:
		retangulo.y = this->h*2;
		this->y -= numPixels;
		this->x += numPixels;
		break;
	case BAIXO_ESQUERDA:
		retangulo.y = this->h;
		this->y += numPixels;
		this->x -= numPixels;
		break;
	case BAIXO_DIREITA:
		retangulo.y = this->h*2;
		this->y += numPixels;
		this->x += numPixels;
		break;	
	}	
	SDL_Rect retangulo2;//retangulo que informa a area da janela que será atualizada
	retangulo2.w = this->w, retangulo2.h = this->h;
	retangulo2.x = this->x, retangulo2.y = this->y;
	/*desenha na nova posição*/
	//SDL_BlitSurface(sprite,NULL, (SDL_Surface*)Tela::getTela(),NULL);
	SDL_BlitSurface(sprite,&retangulo, (SDL_Surface*)Tela::getTela(),&retangulo2);
	SDL_UpdateRect((SDL_Surface*)Tela::getTela(), retangulo2.x, retangulo2.y, retangulo2.w, retangulo2.h);
	
}

int SDL_Sprite::getW()
{
	return this->w;
}

int SDL_Sprite::getH()
{
	return this->h;
}

int SDL_Sprite::getX()
{
	return this->x;
}

int SDL_Sprite::getY()
{
	return this->y;
}

SDL_Sprite::~SDL_Sprite()
{
	SDL_FreeSurface(sprite);	
}
