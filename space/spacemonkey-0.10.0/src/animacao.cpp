
#include "animacao.h"
#include "constantes.h"
#include "tela.h"

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

void Animacao::fadeIn(SDL_Surface* imagem, int i)
{
	SDL_Rect area;
	area.x = posX[i];
	area.y = posY[i];
	area.w = imagem->w;
	area.h = imagem->h;
	
	SDL_Surface *tela = (SDL_Surface*)Tela::getTela();
	int passo = 256/NUM_FRAMES_FADE_IN;
	int cont;
	Uint8 alpha=0;
	for(cont=0; cont<NUM_FRAMES_FADE_IN; cont++)
	{
		SDL_SetAlpha(imagem, SDL_SRCALPHA | SDL_SRCCOLORKEY | SDL_RLEACCEL, alpha);
		SDL_BlitSurface(imagem,NULL, tela,&area);
		SDL_UpdateRect(tela, area.x, area.y, area.w, area.h);
		//SDL_Flip(tela);
		alpha += passo;
		SDL_Delay(32);
	}
	
}

void Animacao::fadeOut()
{
	SDL_Surface *tela = (SDL_Surface*)Tela::getTela();
	int passo = 256/NUM_FRAMES_FADE_IN;
	int cont;
	Uint8 alpha=255;
	for(cont=0; cont<NUM_FRAMES_FADE_IN; cont++)
	{
		SDL_SetAlpha(tela, SDL_SRCALPHA | SDL_SRCCOLORKEY | SDL_RLEACCEL, alpha);
		SDL_UpdateRect(tela, 0, 0, 0, 0);
		alpha -= passo;
		SDL_Delay(32);
	}
	
}

//roda a apresentação
void Animacao::rodar()
{
	int i, timer=0;
	for(i=0; i<NUM_MAX_IMG_POR_ANIMACAO; i++)
	{
		if(imagens[i]!=NULL)
		{
			SDL_Delay( (momento[i]-timer)*1000 );
			timer += momento[i];
			fadeIn(imagens[i], i);
		}
	}
	SDL_Delay( (this->duracao-timer)*1000 );
	fadeOut();
}



