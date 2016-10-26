#include<iostream>
#include <SDL/SDL.h>
#include"audio.h"
#include "constantes.h"
#include "fileNotFoundException.h"
#include "initException.h"

SDL_AudioSpec* Audio::audio_spec_obtido = NULL;
Uint8* Audio::bufferAudio = 0;
int Audio::size = 0;
int Audio::position = 0;
bool Audio::isPlaying = false;
int Audio::volume = 5;
int Audio::minVolume = volume*(SDL_MIX_MAXVOLUME / 10);

//inicializa o SDL Audio
void Audio::init()throw(InitException)
{
	SDL_AudioSpec desired, *obtained;
	desired.freq = FREQUENCIA;
	desired.format = AUDIO_S16SYS;
	desired.channels = NUM_CANAIS;
	desired.samples = SIZE_SAMPLE;
	desired.callback = Audio::callback;
	
	obtained = (SDL_AudioSpec*) malloc(sizeof(SDL_AudioSpec));
	if(obtained == NULL)
		throw InitException("erro ao inicializar o som! Pouca memoria para alocar espaco para o audioSpec");
	
	if(SDL_OpenAudio(&desired, obtained) < 0)
		throw InitException( string("Erro ao inicializar o som: ") + string(SDL_GetError()) );
		
	audio_spec_obtido = obtained;
}

//Alimenta o controlador da placa de audio com blocos de dados de tempos em tempos. Deve carregar as novas amostras quando solicitado, mixar o som no buffer e atualizar a posição do playback
void Audio::callback(void *userdata, Uint8 *audioFinal, int TamanhoBuffer)
{
	//inicializa o audio final
	memset(audioFinal, 0, TamanhoBuffer);

	//se a posição do cursor da musica for -1 (não inicializado) ou maior que o tamanho da msuica, termina a execução
	if (position == -1 || position >= size)
		return;

	int tamanho_prox_amostra;

	//verifica quantos bytes serão colocados na próxima amostra, o máximo que cabe ou só o quanto falta pra acabar
	if (position + TamanhoBuffer > size)
		tamanho_prox_amostra =  size - position;
	else
		tamanho_prox_amostra = TamanhoBuffer;

	//mixa os dados
	SDL_MixAudio(audioFinal, bufferAudio + position, tamanho_prox_amostra, minVolume);

	//muda a posição do cursor
	position += tamanho_prox_amostra;
}

//realiza todo o processo de carregar a musica especificada e trabalhá-la para que possa ser tocada
void Audio::setAudio(string nome_audio)throw (FileNotFoundException, InitException)
{
	//inicializa os valores da classe
	position = -1;
	size = 0;
	bufferAudio = 0;
	isPlaying = false;
	
	//carrego o áudio
	SDL_AudioSpec wavSpec;
	Uint32 wavLen;
	Uint8 *wavBuffer;

	if (SDL_LoadWAV( ( PATH+nome_audio).c_str() , &wavSpec, &wavBuffer, &wavLen) == NULL)
		throw FileNotFoundException( string("Erro ao inicializar a musica: ") + string(SDL_GetError()));	

	//construindo o conversor de áudio para o formato da placa
	SDL_AudioCVT cvt;
	int rc = SDL_BuildAudioCVT(&cvt, wavSpec.format, wavSpec.channels, wavSpec.freq, audio_spec_obtido->format, audio_spec_obtido->channels, audio_spec_obtido->freq);
	if (rc != 0) {
		SDL_FreeWAV(wavBuffer);
		throw InitException("falha ao converter o audio para o formato da placa de audio: "+string(SDL_GetError()));
  	}

	//alocando um novo buffer para caso da conversão precisar de um buffer maior
   	cvt.len = wavLen;//o campo len da estrutura AudioCVT deve ser atualizado para o tamanho do buffer do som
    	Uint8 *wavNewBuf = (Uint8 *) malloc(cvt.len * cvt.len_mult);//o novo buffer é alocado
    	if (wavNewBuf == NULL) {
		SDL_FreeWAV(wavBuffer);
		throw InitException("Sem memoria para um novo buffer!");
    	}
    	memcpy(wavNewBuf, wavBuffer, wavLen);//copia os dados no buffer para o novo
    	cvt.buf = wavNewBuf;//aponta o buffer da estrutura do audio convertido para o novo buffer
	//convertendo de fato para o formado da placa
	if ( SDL_ConvertAudio(&cvt) != 0) {
		SDL_FreeWAV(wavBuffer);
		free(wavNewBuf);
		throw InitException("Erro na conversao do audio!");
	}
	//como já apontei o buffer da estrutura convertida para o buffer novo, este pode ser liberado
	SDL_FreeWAV(wavBuffer);
	bufferAudio = wavNewBuf;
	
	//setta os valores do áudio nos atributos da classe
	SDL_LockAudio();
	position = 0;
	size = cvt.len * cvt.len_mult;
	SDL_UnlockAudio();
	
	//por fim, toca a bagaça
	SDL_PauseAudio(0);
	isPlaying = true;
}

//para a execução do áudio corrente e libera a memória da musica
void Audio::stopAudio()
{
	//código para faze-lo parar
	if(isPlaying)
		SDL_PauseAudio(1);
	//fecha tudo
	if(bufferAudio)
		SDL_FreeWAV(bufferAudio);
	bufferAudio = NULL;
}

void Audio::closeAudio()
{
	if(audio_spec_obtido)
		free(audio_spec_obtido);
	audio_spec_obtido=NULL;
}

void Audio::setVolume(int volumeRecebido){
	volume = volumeRecebido;
}

int Audio::getVolume(){
	return volume;
}

void Audio::pausaMusica(){
	SDL_PauseAudio(1);	
}
