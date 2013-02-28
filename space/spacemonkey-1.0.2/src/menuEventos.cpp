#include <iostream>
using namespace std;

#include "menuEventos.h"
#include "audio.h"
#include "constantes.h"
#include "nomesArquivos.h"
#include "tela.h"
#include "exitException.h"
#include <SDL/SDL.h>
#include <string>
#include <SDL/SDL_image.h>
#include "fileNotFoundException.h"


//construtor
MenuEventos::MenuEventos() throw(FileNotFoundException)
{
	fundo = IMG_Load( (PATH+IMAGEM_FUNDO_MENU).c_str() );
	if(!fundo)
		throw FileNotFoundException( string("falha ao carregar o seguinte arquivo: ")+IMAGEM_FUNDO_MENU);
	btJogar = IMG_Load( (PATH+IMAGEM_BOTAOJOGAR).c_str() );
	if(!btJogar)
		throw FileNotFoundException( string("falha ao carregar o seguinte arquivo: ")+IMAGEM_BOTAOJOGAR);
	btExtra = IMG_Load( (PATH+IMAGEM_BOTAOEXTRA).c_str() );
	if(!btExtra)
		throw FileNotFoundException( string("falha ao carregar o seguinte arquivo: ")+IMAGEM_BOTAOEXTRA);
	btSair = IMG_Load( (PATH+IMAGEM_BOTAOSAIR).c_str() );
	if(!btSair)
		throw FileNotFoundException( string("falha ao carregar o seguinte arquivo: ")+IMAGEM_BOTAOSAIR);
	btJogar2 = IMG_Load( (PATH+IMAGEM_BOTAOJOGAR2).c_str() );
	if(!btJogar2)
		throw FileNotFoundException( string("falha ao carregar o seguinte arquivo: ")+IMAGEM_BOTAOJOGAR2);
	btExtra2 = IMG_Load( (PATH+IMAGEM_BOTAOEXTRA2).c_str() );
	if(!btExtra2)
		throw FileNotFoundException( string("falha ao carregar o seguinte arquivo: ")+IMAGEM_BOTAOEXTRA2);
	btSair2 = IMG_Load( (PATH+IMAGEM_BOTAOSAIR2).c_str() );
	if(!btSair2)
		throw FileNotFoundException( string("falha ao carregar o seguinte arquivo: ")+IMAGEM_BOTAOSAIR2);
	
	emcimaExtra = emcimaJogar = emcimaSair = false;

}

MenuEventos::~MenuEventos()
{
	SDL_FreeSurface(fundo);
	SDL_FreeSurface(btJogar);
	SDL_FreeSurface(btJogar2);
	SDL_FreeSurface(btExtra);
	SDL_FreeSurface(btExtra2);
	SDL_FreeSurface(btSair);
	SDL_FreeSurface(btSair2);
}

void MenuEventos::init()
{
	SDL_Surface* tela = (SDL_Surface*)Tela::getTela();
	SDL_Rect rect;
	//colocando o fundo na tela
	SDL_BlitSurface(fundo,NULL,tela,NULL);
	//colocando o botão jogar na tela
	rect.x = 100, rect.y =200;
	rect.w = btJogar->w, rect.h = btJogar->h;
	SDL_BlitSurface(btJogar,NULL,tela,&rect);
	//colocando o botão extra na tela
	rect.x = 100, rect.y =300;
	rect.w = btExtra->w, rect.h = btExtra->h;
	SDL_BlitSurface(btExtra,NULL,tela,&rect);
	//colocando o botão sair na tela
	rect.x = 100, rect.y =400;
	rect.w = btSair->w, rect.h = btSair->h;
	SDL_BlitSurface(btSair,NULL,tela,&rect);
	
	SDL_UpdateRect(tela,0,0,0,0);
}

bool MenuEventos::verificaColisaoJogar(Uint16 x, Uint16 y)
{
	if(x >= 100 && x< (btJogar->w+100) && y >= 200 && y< (btJogar->h+200))
		return true;
	return false;
}
bool MenuEventos::verificaColisaoExtra(Uint16 x, Uint16 y)
{
	if(x >= 100 && x< (btExtra->w+100) && y >= 300 && y< (btExtra->h+300))
		return true;
	return false;
}
bool MenuEventos::verificaColisaoSair(Uint16 x, Uint16 y)
{
	if(x >= 100 && x< (btSair->w+100) && y >= 400 && y< (btSair->h+400))
		return true;
	return false;
}

void MenuEventos::trocarImgJogar()
{
	SDL_Surface* tela = (SDL_Surface*)Tela::getTela();
	SDL_Rect rect;
	rect.x = 100, rect.y =200;
	rect.w = btJogar->w, rect.h = btJogar->h;
	
	if(emcimaJogar)
		SDL_BlitSurface(btJogar2,NULL,tela,&rect);
	else{
		SDL_BlitSurface(fundo,&rect,tela,&rect);
		SDL_BlitSurface(btJogar,NULL,tela,&rect);
	}
	SDL_UpdateRect(tela,rect.x, rect.y, rect.w, rect.h);
}
void MenuEventos::trocarImgExtra()
{
	SDL_Surface* tela = (SDL_Surface*)Tela::getTela();
	SDL_Rect rect;
	rect.x = 100, rect.y =300;
	rect.w = btExtra->w, rect.h = btExtra->h;
	
	if(emcimaExtra)
		SDL_BlitSurface(btExtra2,NULL,tela,&rect);
	else{
		SDL_BlitSurface(fundo,&rect,tela,&rect);
		SDL_BlitSurface(btExtra,NULL,tela,&rect);
	}
	SDL_UpdateRect(tela,rect.x, rect.y, rect.w, rect.h);
}
void MenuEventos::trocarImgSair()
{
	SDL_Surface* tela = (SDL_Surface*)Tela::getTela();
	SDL_Rect rect;
	rect.x = 100, rect.y =400;
	rect.w = btSair->w, rect.h = btSair->h;
	
	if(emcimaSair)
		SDL_BlitSurface(btSair2,NULL,tela,&rect);
	else{
		SDL_BlitSurface(fundo,&rect,tela,&rect);
		SDL_BlitSurface(btSair,NULL,tela,&rect);
	}
	SDL_UpdateRect(tela,rect.x, rect.y, rect.w, rect.h);
}

void MenuEventos::rodaMusica(string nome_musica){
	Audio::setAudio(nome_musica);		
}

Botoes MenuEventos::getBotaoPressionado() throw (ExitException)
{
	Botoes bt = Sair;
	SDL_Event event;

	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	
	//rodaMusica();
	
	int indiceBt=0;
	
	while(true)
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
					break;
				case SDLK_UP:
				
					indiceBt--;

					if(indiceBt <= 0)
						indiceBt = 3;
      
					cout << "indice na entrada subida: " << indiceBt << endl;
					
					if(indiceBt == 1){
						emcimaJogar = true;
						emcimaExtra = false;
						emcimaSair = false;
						trocarImgJogar();
						trocarImgExtra();
						trocarImgSair();
					}
					if(indiceBt == 2){
						emcimaJogar = false;
						emcimaExtra = true;
						emcimaSair = false;
						trocarImgJogar();
						trocarImgExtra();
						trocarImgSair();
					}
					if(indiceBt == 3){
						emcimaJogar = false;
						emcimaExtra = false;
						emcimaSair = true;
						trocarImgJogar();
						trocarImgExtra();		
						trocarImgSair();
					}
																				
					break;
				case SDLK_DOWN:
					
					indiceBt++;

					if(indiceBt >= 4)
						indiceBt=1;

					cout << "indice na entrada descida: " << indiceBt << endl;
					
					if(indiceBt == 1){
						emcimaJogar = true;
						emcimaExtra = false;
						emcimaSair = false;
						trocarImgJogar();
						trocarImgExtra();
						trocarImgSair();
					}
					if(indiceBt == 2){
						emcimaJogar = false;
						emcimaExtra = true;
						emcimaSair = false;
						trocarImgJogar();
						trocarImgExtra();
						trocarImgSair();
					}
					if(indiceBt == 3){
						emcimaJogar = false;
						emcimaExtra = false;
						emcimaSair = true;
						trocarImgJogar();
						trocarImgExtra();		
						trocarImgSair();
					}
																					
					break;
				case SDLK_SPACE:
				case SDLK_KP_ENTER:
					if(emcimaJogar)
						return bt = Jogar;
					if(emcimaExtra)
						return bt = Extras;
					if(emcimaSair)
						return bt = Sair;
					
					cout << "emcimaJogar: " << emcimaJogar << endl;
					cout << "emcimaExtra: " << emcimaExtra << endl;
					cout << "emcimaSair: " << emcimaSair << endl;
					
					break;
				default:
					break;
				}
				break;
			case SDL_MOUSEMOTION:
				//verifica se o mouse está em cima de algum botão
				emcimaJogar = verificaColisaoJogar(event.motion.x, event.motion.y);
				emcimaExtra = verificaColisaoExtra(event.motion.x, event.motion.y);
				emcimaSair = verificaColisaoSair(event.motion.x, event.motion.y);
				trocarImgJogar();
				trocarImgExtra();
				trocarImgSair();
				indiceBt=0;	
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button) 
				{
				case SDL_BUTTON_LEFT:
					//verifica se o mouse está em cima de algum botão
					if(verificaColisaoJogar(event.motion.x, event.motion.y))
					{
						bt = Jogar;
						return bt;
					}else if(verificaColisaoExtra(event.motion.x, event.motion.y))
					{
						bt = Extras;
						return bt;
					}else if(verificaColisaoSair(event.motion.x, event.motion.y))
					{
						bt = Sair;
						return bt;
					}
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
	}
	return bt;
}

