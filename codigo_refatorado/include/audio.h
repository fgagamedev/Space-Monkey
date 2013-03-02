#ifndef AUIDO_CABECALHO_H
#define AUIDO_CABECALHO_H

#include <SDL/SDL.h>
#include <string>
#include "fileNotFoundException.h"
#include "initException.h"

class Audio
{
private:
	//audioSpec obtido da inicialização do SDL_OpenAudio
	static SDL_AudioSpec *audio_spec_obtido;
	//buffer da musica, que alimenta o controlador da placa
	static Uint8 *bufferAudio;
	//tamanho do buffer que alimenta a controladora da placa
	static int size;
	//posição no buffer em que o cursosr da musica está
	static int position;
	//booleano que diz se há algo tocando ou não
	static bool isPlaying;
	// Volume Áudio
	static int volume;
	static int minVolume;
	
public:
	//inicializa o SDL Audio
	static void init()throw(InitException);
	//Alimenta o controlador da placa de audio com blocos de dados de tempos em tempos. Deve carregar as novas amostras quando solicitado, mixar o som no buffer e atualizar a posição do playback
	static void callback(void *userdata, Uint8 *stream, int len);
	//realiza todo o processo de carregar a musica especificada e trabalhá-la para que possa ser tocada
	static void setAudio(string nome_audio)throw (FileNotFoundException, InitException);
	//para a execução do áudio corrente e libera a memória da musica
	static void stopAudio();
	static void closeAudio();
	static void setVolume(int volumeRecebido);
	static int getVolume();
};

#endif
