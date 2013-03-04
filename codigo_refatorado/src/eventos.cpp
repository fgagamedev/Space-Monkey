

#include"fase.h"
#include"marcador.h"
#include"eventos.h"
#include"exitException.h"
#include"util.h"
#include"constantes.h"
#include"nomesArquivos.h"

#include <iostream>
using namespace std;

void Eventos::trataEventos() throw(ExitException)
{
	while (SDL_PollEvent(&this->event)) 
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
			default:
				break;
			}
		case SDL_MOUSEMOTION:
			//move o marcador
			Marcador::mover(event.motion.x, event.motion.y);		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				//código de inserir torre Aqui
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

void Eventos::trataEventos(Fase *faseCorrente) throw(ExitException)
{
	while (SDL_PollEvent(&this->event)) 
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
			case SDLK_m:
				Util::muteMusic(MUSICA_FASES[Fase::getFaseAtual()]);						
				break;
			default:
				break;
			}
			break;
		case SDL_MOUSEMOTION:
			//move o marcador
			Marcador::mover(event.motion.x, event.motion.y);		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
				case SDL_BUTTON_LEFT:
				{
					//código de inserir torre Aqui
cout << "Moedas antes da compra: " <<Jogador::getMoedas() << endl;
					Torre *temp = Torre::createTorre(TIPO_TORRE_SIMPLES,event.motion.x,event.motion.y);
					
					if(temp == NULL)
						cout << "torre nao criada!!" << endl;
					else
						faseCorrente->torres->push_back(temp);
						
cout << "Numero atual de torres: " << faseCorrente->torres->size() << endl;
					
cout << "Moedas depois da compra: " << Jogador::getMoedas() << endl;
					break;
				}
				default:
					break;
			}
			break;
		default:
			break;
		}
	}
}
