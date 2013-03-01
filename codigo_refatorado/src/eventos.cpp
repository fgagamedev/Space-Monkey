
#include"fase.h"
#include"marcador.h"
#include"eventos.h"
#include"exitException.h"

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
