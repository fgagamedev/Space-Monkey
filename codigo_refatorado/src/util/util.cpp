
#include <SDL/SDL.h>
#include"util.h"
#include"nomesArquivos.h"
#include"constantes.h"
#include"fileNotFoundException.h"
#include"audio.h"
#include <iostream>
using namespace std;

bool Util::musicaRodando = true;

//para a execução pelos milissegundos pedidos
void Util::delay(int mili)
{
	SDL_Delay(mili);
}

TTF_Font* Util::getFonte(int size)throw(FileNotFoundException)
{
	TTF_Font *font = TTF_OpenFont( (PATH+FONTE).c_str(), size);
	if(!font)
		throw FileNotFoundException("Falha ao carregar a fonte "+ string(FONTE));
	return font;
}

void Util::muteMusic(string musicName){
	if(musicaRodando){
		cout << "Mute Apertado" << endl;
		Audio::pausaMusica();
		musicaRodando = false;					
	}
	else{
		cout << "Mute desapertado" << endl;
	
		playMusic(musicName);
		musicaRodando = true;
	}
	
}

void Util::playMusic(string musicName){

	try{
		Audio::setAudio(musicName);
	}catch(Exception &e){
		cout << "Falha a carregar a música do Menu inicial! "<<e.getMessage() <<endl;
		Audio::stopAudio();
	}	

}



