#ifndef ANIMACAO_H
#define ANIMACAO_H

#include "constantes.h"
#include "fileNotFoundException.h"
#include "animaException.h"
#include "exitException.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

/** classe que mostra uma animação na tela. Todas as imagens registradas aparecem com efeito de fade-in e permanecem até o fim da animação*/
class Animacao
{
private:
	//vetor de imagens
	SDL_Surface *imagens[NUM_MAX_IMG_POR_ANIMACAO];
	//tempo de duração da animação
	int duracao;
	//posição em x de cada imagem
	int posX[NUM_MAX_IMG_POR_ANIMACAO];
	//posição em y de cada imagem
	int posY[NUM_MAX_IMG_POR_ANIMACAO];
	//momento em que cada imagem irá aparecer
	int momento[NUM_MAX_IMG_POR_ANIMACAO];
	//numero de imagens carregadas até o momento
	int num_img;
	//método que coloca a imagem na tela com fade-in
	void print(SDL_Surface* imagem,int i);
public:
	//construtor
	Animacao();
	//destrutor
	~Animacao();
	//carrega uma imagem e coloca na 1ª posição livre do vetor. retorna Exceções ao não carregar a imagem ou ao ultrapassar o nº de imagens maxima
	void carregarImagem(string nome, int x, int y, int tempo) throw (FileNotFoundException, AnimaException);
	//determina o tempo de duração da animação
	void setTime(int tempo);
	//roda a apresentação
	void rodar() throw (ExitException);	
};

#endif

