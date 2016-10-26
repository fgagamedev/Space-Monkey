
#include "jogador.h"
#include "agentesProtetores.h"
#include "fileNotFoundException.h"
#include "SDL_Sprite.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"


void AgentesProtetores::init() throw(InitException, FileNotFoundException)
{
	this->HP = TORRE_HP_PADRAO;
	this->dano = 0;
	this->tempoRecarga = 2*TORRE_TEMPO_RECARGUE_PADRAO;
	this->alcance = 0;
	custo = 2*TORRE_CUSTO_PADRAO;
	
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_TORRE_AGENTES_PROTETORES,30, 30);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do AgentesProtetores! não houve memoria suficiente!");
	}
}

//cria uma nova torre e decrescenta o nº de moedas do jogador
Torre* AgentesProtetores::createTorre()
{
	if(Jogador::getMoedas() < custo)
		return NULL;
	Jogador::perderMoedas(custo);
	return new AgentesProtetores();
}

//limpa a memoria
AgentesProtetores::~AgentesProtetores()
{
	delete this->img;
}

