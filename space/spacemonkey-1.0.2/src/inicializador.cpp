#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<string>

#include"audio.h"
#include"constantes.h"
#include"nomesArquivos.h"
#include"initException.h"
#include"inicializador.h"

void Inicializador::initGrafico()throw(InitException)
{
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		throw InitException( string("Erro ao inicializar SDL: ") + string(SDL_GetError()) );
	
	atexit(SDL_Quit);
	atexit(SDL_CloseAudio);
	
	if (TTF_Init() != 0)
		throw InitException(string("Erro ao inicializar o ttf: ") + string(TTF_GetError()));

	atexit(TTF_Quit);
	
	SDL_WM_SetCaption(NOME_BARRA_SUPERIOR.c_str(), NOME_BARRA_SUPERIOR.c_str());
	SDL_WM_SetIcon( IMG_Load( (PATH + IMAGEM_LOGO).c_str() ), NULL);
}

void Inicializador::initSom()throw(InitException)
{
	SDL_AudioSpec desired, obtained;
	desired.freq = FREQUENCIA;
	desired.format = AUDIO_S16SYS;
	desired.channels = NUM_CANAIS;
	desired.samples = SIZE_SAMPLE;
	desired.callback = Audio::callback;
	
	if(SDL_OpenAudio(&desired, &obtained) < 0)
		throw InitException( string("Erro ao inicializar o som: ") + string(SDL_GetError()) );
		
	Audio::setAudioSpec(&obtained);
}

