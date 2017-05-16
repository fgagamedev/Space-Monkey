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
//determina o número de inmigos que podem chegar ao ponto final
const int VIDA_FASE = 9000;
//define o caminho onde estão os resources usados
const string PATH = "resources/";
//define o texto que aparecerá na barra superior do jogo
const string NOME_BARRA_SUPERIOR = "SpaceMonkey";

//define dados de configuração do audio
const int FREQUENCIA = 44100;
const int NUM_CANAIS = 2;
const int SIZE_SAMPLE = 4096;

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
const int INIMIGO_DANO_INICIAL = 0;
const int INIMIGO_ALCANCE_INICIAL=0;
//define os valores padrão dos atributos das torres
const int TORRE_HP_PADRAO = 8;
const int TORRE_DANO_PADRAO = 2;
const int TORRE_TEMPO_RECARGUE_PADRAO = 1;//em segundos
const int TORRE_ALCANCE_PADRAO = 15;//em pixels
const int TORRE_CUSTO_PADRAO = 10;
//define o valor numerico de cada torre
const int TIPO_TORRE_SIMPLES = 1;
const int TIPO_TORRE_DUPLO = 2;
const int TIPO_TORRE_RETARDANTE = 3;
const int TIPO_TORRE_ANGULADO = 4;
const int TIPO_TORRE_MOREFIRE = 5;
const int TIPO_TORRE_BOMBARDEIRO = 6;
const int TIPO_TORRE_BOMBERMAN = 7;
const int TIPO_TORRE_AGENTES_PROTETORES = 8;
const int TIPO_TORRE_IRONMAN = 9;
const int TIPO_TORRE_MURO = 10;
const int TIPO_TORRE_MUROREFORCADO = 11;
const int TIPO_TORRE_FORTIFICATION = 12;
//define valor numérico
const int NORMAL = 0;
const int ATACADO = 1;
const int DESTRUIDO = 2;
// classe animacao
const int QUANTIDADE_INICIAL_IMAGENS = 0;
const int TAMANHO_FONTE = 30;
const int QUANTIDADE_CELULAS_DISTANTE_BORDA_ESQ = 10;
// classe audio
const int VALOR_INICIAL_BUFFER_AUDIO = 0;
const int VALOR_DEFAULT_ZERO = 0;
const int VOLUME_DEFAULT = 5;
const int GRADUACAO_VOLUME = 10;
const int VALOR_DEFAULT_CURSOR_MUSICA = -1;
const int TOCANDO_MUSICA = 0;
const int NAO_TOCANDO_MUSICA = 1;
// classe chipanze
const int TAM_X_SPRITE_CHIMPANZE = 19;
const int TAM_Y_SPRITE_CHIMPANZE = 30;
// classe definicoesMapaLogico
const int ERRO_ABRIR_ARQUIVO = 1;
const int QTD_COLUNAS_ARQUIVO = 20;
const int QTD_LINHAS_ARQUIVO = 27;
// classe fase
const int VALOR_DEFAULT_MINUS_ONE = -1;
const int QTD_WAVES_BASE_CALCULO = 5;
// classe horda
const int QTD_DIFICULDADES = 3;
// classe menuEventos
const int LIMITE_INFERIOR_BT = 0;
const int LIMITE_SUPERIOR_BT = 4;
const int BOTAO1 = 1;
const int BOTAO2 = 2;
const int BOTAO3 = 3;
// classe jogador
const int VALOR_INICIAL_MOEDAS = 0;
// classe marcador
const int VALOR_DEFAULT_X= -50;
const int VALOR_DEFAULT_Y= -50;
#endif

