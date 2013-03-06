
#include "exitException.h"
#include "audio.h"
#include "util.h"
#include "mapa.h"
#include "animacao.h"
#include "constantes.h"
#include "nomesArquivos.h"
#include "tela.h"
#include <SDL/SDL_image.h>
#include <iostream>
#include <SDL/SDL_ttf.h>

//construtor que inicializa o vetor de imagens
Animacao::Animacao()
{
	num_img_carregadas = QUANTIDADE_INICIAL_IMAGENS;
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
void Animacao::carregarImagem(string nome, int linha, int coluna, int tempo) throw (FileNotFoundException, AnimaException)
{
	if(num_img_carregadas == NUM_MAX_IMG_POR_ANIMACAO)
		throw AnimaException("Ultrapassado o numero maximo de imagens a serem carregadas na mesma animacao!");
	
	imagens[num_img_carregadas] = IMG_Load( (PATH+nome).c_str() );
	if(!imagens[num_img_carregadas])
		throw FileNotFoundException( string("Nao foi possivel carregar o seguinte arquivo: ")+nome);
		
	if(linha == CENTRALIZAR)
		posX[num_img_carregadas] = (TELA_WIDTH-imagens[num_img_carregadas]->w)/2;
	else
		posX[num_img_carregadas]=linha;
	
	if(coluna == CENTRALIZAR)
		posY[num_img_carregadas] = (TELA_HEIGHT-imagens[num_img_carregadas]->h)/2;
	else
		posY[num_img_carregadas] = coluna;
		
	momento[num_img_carregadas] = tempo;	
	num_img_carregadas++;
}

//determina o tempo de duração da animação
void Animacao::setTime(int tempo)
{
	this->duracao = tempo;
}

void Animacao::print(SDL_Surface* imagem,int imagem_desejada)
{
	SDL_Rect area;
	area.x = posX[imagem_desejada];
	area.y = posY[imagem_desejada];
	area.w = imagem->w;
	area.h = imagem->h;
	
	SDL_Surface *tela = (SDL_Surface*)Tela::getTela();
	SDL_BlitSurface(imagem,NULL, tela,&area);
	SDL_UpdateRect(tela, area.x, area.y, area.w, area.h);
}


//roda a apresentação
void Animacao::rodar() throw (ExitException)
{
	int i, timer=VALOR_DEFAULT_ZERO;
	int delayMomento=1000;
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
				SDL_Delay( (momento[i]-timer-1)*delayMomento );
			timer += momento[i];
			print(imagens[i],i);
		}
	}
	SDL_Delay( (this->duracao-timer)*delayMomento );

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
	int valorMaximoAlpha=256;
	int incrementoFadeOut = 8;
	int tempoEspera = 75;
	for(alpha=0; alpha<valorMaximoAlpha; alpha+=incrementoFadeOut)
	{
		SDL_SetAlpha(gameOver, SDL_SRCALPHA | SDL_RLEACCEL, (Uint8)alpha);
		SDL_BlitSurface(gameOver,NULL,tela,NULL);
		SDL_UpdateRect(tela,0,0,0,0);
		SDL_Delay(tempoEspera);
	}
	for(alpha=0; alpha<valorMaximoAlpha; alpha+=incrementoFadeOut)
	{
		SDL_SetAlpha(preto, SDL_SRCALPHA | SDL_RLEACCEL, (Uint8)alpha);
		SDL_BlitSurface(preto,NULL,tela,NULL);
		SDL_UpdateRect(tela,0,0,0,0);
		SDL_Delay(tempoEspera);
	}
	SDL_FreeSurface(gameOver);
	SDL_FreeSurface(preto);
}

void Animacao::creditos()
{
	//carrega a fonte e o texto
	TTF_Font *font = Util::getFonte(TAMANHO_FONTE);
	
	int alpha=255;	
	SDL_Color white = {0, 0, 0, alpha};	 
	SDL_Surface *renderedText = TTF_RenderText_Blended(font, "VOCE GANHOU!!", white);

	if (!renderedText) {
		TTF_CloseFont(font);
		return;
	}

	//determina area de trabalho
	SDL_Rect dest;
	SDL_Surface *tela = (SDL_Surface*)Tela::getTela();
	dest.x = tela->w/2 - QUANTIDADE_CELULAS_DISTANTE_BORDA_ESQ, 
	dest.y = tela->h/2 - QUANTIDADE_CELULAS_DISTANTE_BORDA_ESQ, 
	dest.w = renderedText->w, 
	dest.h = renderedText->h;
	
	//apaga o texto atual
	SDL_BlitSurface((SDL_Surface*)Mapa::getMapa(), &dest, tela, &dest);
	
	//escreve o texto certo
	SDL_BlitSurface(renderedText, NULL, tela, &dest);
	SDL_UpdateRect(tela,dest.x,dest.y,dest.w, dest.h);
	
	SDL_FreeSurface(renderedText);
	TTF_CloseFont(font);

	SDL_Delay(2000);
	
	SDL_Color preto = {0,0,0};
	Uint32 cor = SDL_MapRGB(tela->format, preto.r, preto.g, preto.b);
	SDL_Rect rect;
	rect.x = rect.y =0, rect.w = TELA_WIDTH, rect.h = TELA_HEIGHT;
	SDL_FillRect(tela, &rect, cor);
	SDL_UpdateRect(tela,0,0,0,0);
}

