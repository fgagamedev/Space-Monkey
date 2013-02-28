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
//define o caminho onde estão os resources usados
const string PATH = "/opt/spacemonkey/resources/";
//define o texto que aparecerá na barra superior do jogo
const string NOME_BARRA_SUPERIOR = "SpaceMonkey";
//define que uma certa imagem será centralizada com a tela
const int CENTRALIZAR = -1;
//define o numero máximo de imagens que uma animação pode conter
const int NUM_MAX_IMG_POR_ANIMACAO = 10;
//define o número de atualizações de tela para dar o efeito de fade-in
const int NUM_FRAMES_FADE_IN = 32;
//define os valores que cada ponto da matriz lógica (mapa) pode conter
const char MAPA = '0';
const char ESTRADA = '1';
const char TORRE = '2';
const char TEM_TORRE = '3';

//define o tamanho de cada quadrado por onde os inimigos andarão
const int TAMANHO_QUADRADO = 30;
const int TAMANHO_MATRIZ_LOGICA_X = (TELA_WIDTH%TAMANHO_QUADRADO)==0? TELA_WIDTH/TAMANHO_QUADRADO : ((int)(TELA_WIDTH/TAMANHO_QUADRADO)+1);
const int TAMANHO_MATRIZ_LOGICA_Y = (TELA_HEIGHT%TAMANHO_QUADRADO)==0? TELA_HEIGHT/TAMANHO_QUADRADO : ((int)(TELA_HEIGHT/TAMANHO_QUADRADO)+1);
//define uma estrutura que diz os tipos de movimentos possiveis
typedef enum _Direcao {BAIXO, ACIMA, ESQUERDA, DIREITA, ACIMA_ESQUERDA, ACIMA_DIREITA, BAIXO_ESQUERDA, BAIXO_DIREITA}Direcao; 
//define os botões do menu inicial
typedef enum _Botoes {Jogar, Extras, Sair}Botoes;
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

