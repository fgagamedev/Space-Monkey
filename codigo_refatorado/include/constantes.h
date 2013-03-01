#ifndef CONSTANTES_H
#define CONSTANTES_H

#include<string>
using namespace std;

//define o número de fases do jogo
const int NUM_FASES_TOTAIS = 8;
//define o tamanho da tela do jogo
const int TELA_WIDTH = 800;
const int TELA_HEIGHT = 600;
//define o número de bits por pixel da tela
const int TELA_BPP = 32;
//define o camino onde estão os resources usados
const string PATH = "/opt/spacemonkey/resources/";
//define o nome do arquivo de cada mapa do jogo
const string NOME_MAPA1 = "mapa1.bmp";
const string NOME_MAPA2 = "mapa2.bmp";
const string NOME_MAPA3 = "mapa3.bmp";
const string NOME_MAPA4 = "mapa4.bmp";
const string NOME_MAPA5 = "mapa5.bmp";
const string NOME_MAPA6 = "mapa6.bmp";
const string NOME_MAPA7 = "mapa7.bmp";
const string NOME_MAPA8 = "mapa8.bmp";

//define as posições dos objetivos inimigos em cada fase
const int FASE1_GOALX = 540, FASE1_GOALY = 600;
const int FASE2_GOALX = 10, FASE2_GOALY = 30;
const int FASE3_GOALX = 10, FASE3_GOALY = 30;
const int FASE4_GOALX = 10, FASE4_GOALY = 30;
const int FASE5_GOALX = 10, FASE5_GOALY = 30;
const int FASE6_GOALX = 10, FASE6_GOALY = 30;
const int FASE7_GOALX = 10, FASE7_GOALY = 30;
const int FASE8_GOALX = 10, FASE8_GOALY = 30;

//define o tamanho de cada quadrado por onde os inimigos andarão
const int TAMANHO_QUADRADO = 30;
const int TAMANHO_MATRIZ_LOGICA_X = (TELA_WIDTH%TAMANHO_QUADRADO)==0? TELA_WIDTH/TAMANHO_QUADRADO : ((int)(TELA_WIDTH/TAMANHO_QUADRADO)+1);
const int TAMANHO_MATRIZ_LOGICA_Y = (TELA_HEIGHT%TAMANHO_QUADRADO)==0? TELA_HEIGHT/TAMANHO_QUADRADO : ((int)(TELA_HEIGHT/TAMANHO_QUADRADO)+1);
//define uma estrutura que diz os tipos de movimentos possiveis
typedef enum _Direcao {BAIXO, ACIMA, ESQUERDA, DIREITA, ACIMA_ESQUERDA, ACIMA_DIREITA, BAIXO_ESQUERDA, BAIXO_DIREITA}Direcao; 
//define os valores padrão dos atributos inimigos
const int INIMIGO_HP_PADRAO = 6;
const int INIMIGO_DANO_PADRAO = 2;
const int INIMIGO_VEL_PADRAO = 3;
//define os valores padrão dos atributos das torres
const int TORRE_HP_PADRAO = 8;
const int TORRE_DANO_PADRAO = 2;
const int TORRE_TEMPO_RECARGUE_PADRAO = 1;//em segundos
const int TORRE_ALCANCE_PADRAO = 15;//em pixels
const int TORRE_CUSTO_PADRAO = 10;

#endif

