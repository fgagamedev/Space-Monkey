#ifndef SDL_SPRITE_H
#define SDL_SPRITE_H

#include "sprite.h"
#include <string>
#include "fileNotFoundException.h"
#include <SDL/SDL.h>

using namespace std;

class SDL_Sprite : public Sprite
{
private:
	SDL_Surface *sprite;
	int w, h, x, y;
	SDL_Color COLORKEY;
public:
	//o coloca na tela, fazendo-o aparecer  pela primeira vez no jogo virado pro lado certo (dir)
	void init(Direcao dir);
	//construtor que carrega a imagem especificada no programa e guarda o tamanho de cada imagem dela (w e h)
	SDL_Sprite(string nome_arquivo, int w, int h) throw (FileNotFoundException);
	//deleta o sprite
	~SDL_Sprite();
	//ativa a colorkey, sumindo com a cor de fundo
	void ativarTransparencia();
	//move o sprite pra algum lado
	void mover(Direcao dir, int numPixels);
	//apaga o sprite da tela
	void apagarSprite();
	//retorna informações de posição para o inimigo
	int getW();
	int getH();
	int getX();
	int getY();
};

#endif

