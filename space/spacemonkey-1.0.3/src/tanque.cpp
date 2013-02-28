
#include "jogador.h"
#include "tanque.h"
#include "fileNotFoundException.h"
#include "SDL_Sprite.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"


void Tanque::init() throw(InitException, FileNotFoundException)
{
	this->HP = TORRE_HP_PADRAO*10;
	this->dano = 5*TORRE_DANO_PADRAO;
	this->tempoRecarga = 0;
	this->alcance = 1;
	custo = 10*TORRE_CUSTO_PADRAO;
	
	this->hp_restante  = this->HP;
	
	try{
		this->img = new SDL_Sprite(ARQUIVO_TORRE_BOMBERMAN,30, 30);//nome do arquivo e as dimensões de cada desenho da sprite
		Direcao dir=BAIXO;
		this->img->init(dir);
	}catch(bad_alloc ba){
		throw InitException("falha ao alocar o sprite do atiradorSimples! não houve memoria suficiente!");
	}
}

//cria uma nova torre e decrescenta o nº de moedas do jogador
Torre* Tanque::createTorre()
{
	if(Jogador::getMoedas() < custo)
		return NULL;
	Jogador::perderMoedas(custo);
	return new Tanque();
}

//limpa a memoria
Tanque::~Tanque()
{
	delete this->img;
}

