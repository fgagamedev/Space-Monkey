#ifndef NOMES_ARQUIVOS_H
#define NOMES_ARQUIVOS_H

#include <string>
#include "constantes.h"

//define o nome do arquivo de cada mapa do jogo
const string NOME_MAPA1 = "mapa1.png";
const string NOME_MAPA2 = "mapa2.png";
const string NOME_MAPA3 = "mapa3.png";
const string NOME_MAPA4 = "mapa4.png";
const string NOME_MAPA5 = "mapa5.png";
const string NOME_MAPA6 = "mapa6.png";
const string NOME_MAPA7 = "mapa7.png";
const string NOME_MAPA8 = "mapa8.png";

const string NOME_MAPAS[] = {NOME_MAPA1, NOME_MAPA2, NOME_MAPA3, NOME_MAPA4, NOME_MAPA5, NOME_MAPA6, NOME_MAPA7, NOME_MAPA8};

//define o nome dos arquivos de cada inimigo do jogo
const string ARQUIVO_ORANGOTANGO = "inimigo.png";
const string ARQUIVO_CHIPANZE1 = "inimigo2.png";
const string ARQUIVO_CHIPANZE2 = "inimigo3.png";
const string ARQUIVO_GORILA1 = "inimigo.png";
const string ARQUIVO_GORILA2 = "inimigo.png";

//define o nome dos arquivos de cada torre do jogador
const string ARQUIVO_TORRE_SIMPLES = "torreSimples.png";
const string ARQUIVO_TORRE_DUPLO = "torreDupla.png";
const string ARQUIVO_TORRE_RETARDANTE = "torreRetardante.png";
const string ARQUIVO_TORRE_ANGULADO = "torreAngulado.png";
const string ARQUIVO_TORRE_MOREFIRE = "torreMoreFire.png";
const string ARQUIVO_TORRE_BOMBARDEIRO = "torreBombardeiro.png";
const string ARQUIVO_TORRE_BOMBERMAN = "torreBomberman.png";
const string ARQUIVO_TORRE_AGENTES_PROTETORES = "torreAgenteProtetor.png";
const string ARQUIVO_TORRE_IRONMAN = "torreIronMan.png";
const string ARQUIVO_TORRE_MURO = "torreMuro.png";
const string ARQUIVO_TORRE_MUROREFORCADO = "torreMuroReforcado.png";
const string ARQUIVO_TORRE_FORTIFICATION = "torreFortification.png";

//define o nome do arquivo com a logo do jogo
const string IMAGEM_LOGO = "DownMonkeyLogo.png";
//define os nomes dos arquivos que aparecem na apresentação inicial
const string IMAGEM_APRESENTACAO_INICIAL = "logo.png";
const string IMAGEM_PRESENTS = "apresenta.png";
//define os nomes dos arquivos que aparecem no menu do jogo
const string IMAGEM_FUNDO_MENU = "menu.png";
const string IMAGEM_BOTAOJOGAR = "MenuJogar.png";
const string IMAGEM_BOTAOJOGAR2 = "MenuJogar2.png";
const string IMAGEM_BOTAOEXTRA = "MenuExtras.png";
const string IMAGEM_BOTAOEXTRA2 = "MenuExtras2.png";
const string IMAGEM_BOTAOSAIR = "MenuSair.png";
const string IMAGEM_BOTAOSAIR2 = "MenuSair2.png";

//define as posições dos objetivos inimigos em cada fase
const int GOALS_X[NUM_FASES_TOTAIS] = {720, 360, 360, 690, 780, 510, 720, 660};
const int GOALS_Y[NUM_FASES_TOTAIS] = {570, 0, 570, 510, 510, 570, 540, 510};
//define as posições iniciais dos inimigos em cada fase
const int INITS_X[NUM_FASES_TOTAIS] = {0, 120, 300, 30, 90, 0, 90, 0};
const int INITS_Y[NUM_FASES_TOTAIS] = {30, 600, 0, 0, 0, 30, 0, 30};


#endif

