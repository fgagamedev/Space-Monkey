
#include "initException.h"
#include "exitException.h"
#include "thread.h"
#include <SDL/SDL_thread.h>
#include <SDL/SDL.h>

static int verificaEventos(void *porra)
{
	SDL_Event event;
	while(true)
	{
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			case SDL_QUIT:
			{
				Thread::booleanoGlobal = true;
				return 0;			
			}
			case SDL_KEYDOWN: 
				switch (event.key.keysym.sym) 
				{
				case SDLK_ESCAPE:
				{
					Thread::booleanoGlobal = true;
					return 0;			
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
	return 0;
}

void Thread::initThread() throw (InitException, ExitException)
{
	booleanoGlobal = false;
	thread = SDL_CreateThread(verificaEventos, NULL);
	if ( thread == NULL )
        	throw InitException("Falha ao criar a thread");
	if(booleanoGlobal)
		throw ExitException("saindo...");
}

