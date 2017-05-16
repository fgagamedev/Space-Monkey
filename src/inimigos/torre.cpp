
#include "torre.h"
#include "constantes.h"
#include "jogador.h"
#include "atiradorSimples.h"
#include "atiradorDuplo.h"
#include "atiradorRetardante.h"
#include "atiradorAngulado.h"
#include "atiradorMoreFire.h"
#include "bombardeiro.h"
#include "tanque.h"
#include "agentesProtetores.h"
#include "ironMan.h"
#include "muro.h"
#include "muroReforcado.h"
#include "fortification.h"
#include "mapa.h"

int Torre::custo = 0;

bool Torre::possoCriar(int tipoTorre)
{
	int custo_criacao = 0;
	switch(tipoTorre)
	{
	case TIPO_TORRE_SIMPLES:
		custo_criacao = TORRE_CUSTO_PADRAO ;
		break;
	case TIPO_TORRE_DUPLO:
		custo_criacao = 2*TORRE_CUSTO_PADRAO;
		break;
	case TIPO_TORRE_RETARDANTE:
		custo_criacao = 2*TORRE_CUSTO_PADRAO;
	break;
	case TIPO_TORRE_ANGULADO:
		custo_criacao = TORRE_CUSTO_PADRAO;
		break;
	case TIPO_TORRE_MOREFIRE:
		custo_criacao = 2*TORRE_CUSTO_PADRAO;
		break;
	case TIPO_TORRE_BOMBARDEIRO:
		custo_criacao = 3*TORRE_CUSTO_PADRAO;
		break;
	case TIPO_TORRE_BOMBERMAN:
		custo_criacao = 10*TORRE_CUSTO_PADRAO;
		break;
	case TIPO_TORRE_AGENTES_PROTETORES:
		custo_criacao = 2*TORRE_CUSTO_PADRAO;
		break;
	case TIPO_TORRE_IRONMAN:
		custo_criacao = 3*TORRE_CUSTO_PADRAO;
		break;
	case TIPO_TORRE_MURO:
		custo_criacao = 0.7*TORRE_CUSTO_PADRAO;
		break;
	case TIPO_TORRE_MUROREFORCADO:
		custo_criacao = 1.6*TORRE_CUSTO_PADRAO;
		break;
	case TIPO_TORRE_FORTIFICATION:
		custo_criacao = 4*TORRE_CUSTO_PADRAO;
		break;
	default:
		break;
	}
	if(Jogador::getMoedas() < custo_criacao)
		return false;
	return true;

}

//cria uma nova torre e decrescenta o nº de moedas do jogador
Torre* Torre::createTorre(int tipoTorre,int xMouse, int yMouse)
{

	if(!Mapa::possoPorTorre(xMouse,yMouse))
		return NULL;

	if( !possoCriar(tipoTorre) )
		return NULL;

	int posX = xMouse/TAMANHO_QUADRADO;
	int posY = yMouse/TAMANHO_QUADRADO;

	Torre *torre = NULL;

	switch(tipoTorre)
	{
	case TIPO_TORRE_SIMPLES:
		torre = new AtiradorSimples();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_DUPLO:
		torre = new AtiradorDuplo();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_RETARDANTE:
		torre = new AtiradorRetardante();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_ANGULADO:
		torre = new AtiradorAngulado();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_MOREFIRE:
		torre = new AtiradorMoreFire();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_BOMBARDEIRO:
		torre = new Bombardeiro();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_BOMBERMAN:
		torre = new Tanque();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_AGENTES_PROTETORES:
		torre = new AgentesProtetores();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_IRONMAN:
		torre = new IronMan();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_MURO:
		torre = new Muro();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_MUROREFORCADO:
		torre = new MuroReforcado();
		torre->init(posX,posY);
		break;
	case TIPO_TORRE_FORTIFICATION:
		torre = new Fortification();
		torre->init(posX,posY);
		break;
	default:
		break;
	}
	Mapa::alteraEstadoMapaLogico(posX,posY,TEM_TORRE);
	Jogador::perderMoedas(torre->getCusto());
	return torre;
}



//retorna o quanto de vida resta
int Torre::getHp() const
{
	return this->hp_restante;
}

//retorna o dano que a torre causa
int Torre::getDano() const
{
	return this->dano;
}

//retorna o numero de quadrados que o tiro da torre alcance
int Torre::getAlcance() const
{
	return this->alcance;
}

//reorna o custo de construção da torre
int Torre::getCusto()
{
	return custo;
}

