
#include "exitException.h"
#include "audio.h"
#include "animacao.h"
#include "constantes.h"
#include "nomesArquivos.h"
#include "tela.h"
#include <SDL/SDL_image.h>
#include <iostream>

//construtor que inicializa o vetor de imagens
Animacao::Animacao()
{
	num_img = 0;
	int i;
	for(i=0; i<NUM_MAX_IMG_POR_ANIMACAO; i++)
		imagens[i] = NULL;
}

//destrutor que libera todas as imagens carregadas
Animacao::~Animacao()
{
	int i;
	for(i=0; i<NUM_MAX_IMG_POR_ANIMACAO; i++)
	{
		if(imagens[i] == NULL)
			break;
		SDL_FreeSurface(imagens[i]);
	}
}

//carrega uma imagem e coloca na 1ª posição livre do vetor
void Animacao::carregarImagem(string nome, int x, int y, int tempo) throw (FileNotFoundException, AnimaException)
{
	if(num_img == NUM_MAX_IMG_POR_ANIMACAO)
		throw AnimaException("Ultrapassado o numero maximo de imagens a serem carregadas na mesma animacao!");
	
	imagens[num_img] = IMG_Load( (PATH+nome).c_str() );
	if(!imagens[num_img])
		throw FileNotFoundException( string("Nao foi possivel carregar o seguinte arquivo: ")+nome);
		
	posX[num_img] = (x==CENTRALIZAR ? (TELA_WIDTH-imagens[num_img]->w)/2: x);
	posY[num_img] = (y==CENTRALIZAR ? (TELA_HEIGHT-imagens[num_img]->h)/2: y);
	momento[num_img] = tempo;	
	num_img++;
}

//determina o tempo de duração da animação
void Animacao::setTime(int tempo)
{
	this->duracao = tempo;
}

void Animacao::print(SDL_Surface* imagem,int i)
{
	SDL_Rect area;
	area.x = posX[i];
	area.y = posY[i];
	area.w = imagem->w;
	area.h = imagem->h;
	
	SDL_Surface *tela = (SDL_Surface*)Tela::getTela();
	SDL_BlitSurface(imagem,NULL, tela,&area);
	SDL_UpdateRect(tela, area.x, area.y, area.w, area.h);
}


//roda a apresentação
void Animacao::rodar() throw (ExitException)
{
	int i, timer=0;
	SDL_Event event;
	for(i=0; i<NUM_MAX_IMG_POR_ANIMACAO; i++)
	{
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			case SDL_QUIT:
				throw ExitException("saindo...");
			case SDL_KEYDOWN: 
				switch (event.key.keysym.sym) 
				{
				case SDLK_ESCAPE:
					throw ExitException("saindo...");
				case SDLK_SPACE:
					return;
				default:
					break;
				}
			default:
				break;
			}
		}
		if(imagens[i]!=NULL)
		{
			if(momento[i]!=0)
				SDL_Delay( (momento[i]-timer-1)*1000 );
			timer += momento[i];
			print(imagens[i],i);
		}
	}
	SDL_Delay( (this->duracao-timer)*1000 );

}

void Animacao::gameOver()
{
	//toca musica de derrota
	try{
		Audio::setAudio(MUSICA_GAME_OVER);
	}catch(Exception &e){
		cout << "Falha a carregar a música do Game Over! "<<e.getMessage() <<endl;
		Audio::stopAudio();
	}
	//animação do game over
	SDL_Surface *tela = (SDL_Surface*)Tela::getTela();
	SDL_Surface *gameOver = IMG_Load( (PATH+GAMEOVERIMG).c_str() );
	SDL_Surface *preto = IMG_Load( (PATH+IMAGEM_FUNDO_PRETO).c_str() );
	int alpha;
	for(alpha=0; alpha<256; alpha+=8)
	{
		SDL_SetAlpha(gameOver, SDL_SRCALPHA | SDL_RLEACCEL, (Uint8)alpha);
		SDL_BlitSurface(gameOver,NULL,tela,NULL);
		SDL_UpdateRect(tela,0,0,0,0);
		SDL_Delay(75);
	}
	for(alpha=0; alpha<256; alpha+=8)
	{
		SDL_SetAlpha(preto, SDL_SRCALPHA | SDL_RLEACCEL, (Uint8)alpha);
		SDL_BlitSurface(preto,NULL,tela,NULL);
		SDL_UpdateRect(tela,0,0,0,0);
		SDL_Delay(75);
	}
	SDL_FreeSurface(gameOver);
	SDL_FreeSurface(preto);
}

void Animacao::creditos()
{

}

