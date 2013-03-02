#include "constantes.h"

//funções que montam o mapa lógico de cada fase
void nomesArquivos_montaMapaLogico1(char** mapaLogico)
{
	int i;
	//determina onde é estrada
	for(i=0; i<6; i++)
		mapaLogico[i][1] = mapaLogico[i][2] = ESTRADA;
	mapaLogico[6][2] = mapaLogico[5][3] = mapaLogico[6][3] = mapaLogico[7][3] = mapaLogico[6][4] = mapaLogico[7][4] = mapaLogico[8][4] = mapaLogico[6][5] = mapaLogico[12][6] = ESTRADA;	
	for(i=7; i<12; i++)
		mapaLogico[i][5] = mapaLogico[i][6] =ESTRADA;	
	for(i=6; i<9; i++)
		mapaLogico[13][i] =mapaLogico[14][i] = ESTRADA;
	mapaLogico[15][7] =mapaLogico[15][8] = ESTRADA;
	for(i=14; i<=16; i++)
		mapaLogico[i][9] =mapaLogico[i][10] = ESTRADA;
	mapaLogico[17][10] = mapaLogico[18][9] = mapaLogico[19][9] = ESTRADA;
	for(i=18; i<=20; i++)
		mapaLogico[i][11] =mapaLogico[i][12] = ESTRADA;
	mapaLogico[20][12] = mapaLogico[19][13] = mapaLogico[18][13] = ESTRADA;
	for(i=13; i<18; i++)
		mapaLogico[19][i] = mapaLogico[20][i] = ESTRADA;
	mapaLogico[21][17] = ESTRADA;
	for(i=20; i<25; i++)
		mapaLogico[i][18] =mapaLogico[i][19]= ESTRADA;
	//determina onde pode construir torre
	for(i=0; i<5; i++)
		mapaLogico[i][3] = TORRE;
	mapaLogico[5][4] = mapaLogico[5][5] = mapaLogico[6][6] = mapaLogico[7][7] = mapaLogico[13][9] = mapaLogico[13][10] = mapaLogico[14][11] = mapaLogico[15][11] = mapaLogico[16][12] = mapaLogico[17][13] = mapaLogico[18][14] = mapaLogico[19][14] = mapaLogico[19][15] = mapaLogico[19][16] = mapaLogico[19][17] = mapaLogico[20][18] = mapaLogico[20][19] = TORRE;
	mapaLogico[6][1] = mapaLogico[7][2] = mapaLogico[8][3] = mapaLogico[9][4] = mapaLogico[10][4] = mapaLogico[11][4] = mapaLogico[12][5] = mapaLogico[13][5] = mapaLogico[14][5] = mapaLogico[15][6] = mapaLogico[16][7] = mapaLogico[16][8] = mapaLogico[17][9] = mapaLogico[18][9] = mapaLogico[19][10] = mapaLogico[20][11] = mapaLogico[21][12] = mapaLogico[22][13] = mapaLogico[23][17]  = mapaLogico[22][14] = mapaLogico[22][15] = mapaLogico[22][16] = TORRE;
}
void nomesArquivos_montaMapaLogico2(char** mapaLogico)
{
	int x, x2, y, y2;
	//determina onde é estrada
	for(x=4, x2=20; x<7; x++, x2++)
		mapaLogico[x][19] = mapaLogico[x2][19] = mapaLogico[x][18] = mapaLogico[x2][18] = ESTRADA;
	mapaLogico[5][17] = mapaLogico[6][17] = mapaLogico[19][17] = mapaLogico[20][17] = mapaLogico[21][17] = mapaLogico[5][16] = mapaLogico[6][16] = mapaLogico[7][16] = ESTRADA;
	for(x=18, x2=17, y2=15; x<=21; x++, x2++, y2++)
		mapaLogico[x][16] = mapaLogico[x2][15] = mapaLogico[x2][10] = mapaLogico[y2][14] = mapaLogico[y2][11] = ESTRADA;
	for(x=6, x2=7, y=5,y2=18; x<=8; x++, x2++, y++,y2++)
		mapaLogico[x][15] = mapaLogico[x2][11] = mapaLogico[x][10] = mapaLogico[y][9] = mapaLogico[y2][9] = ESTRADA;
	mapaLogico[8][14] = mapaLogico[9][14] = mapaLogico[5][8] = mapaLogico[6][8] = ESTRADA;
	for(x=18; x<=21; x++)
		mapaLogico[x][8] = ESTRADA;
	mapaLogico[4][7] = mapaLogico[5][7] = mapaLogico[6][7] = mapaLogico[19][7] =  mapaLogico[20][7] = ESTRADA;
	mapaLogico[4][6] = mapaLogico[5][6] = mapaLogico[19][6] = mapaLogico[20][6] =  mapaLogico[21][6] = ESTRADA;
	mapaLogico[4][5] = mapaLogico[5][5] = mapaLogico[19][5] = mapaLogico[20][5] =  mapaLogico[21][5] = ESTRADA;
	mapaLogico[4][4] = mapaLogico[5][4] = mapaLogico[6][4] = mapaLogico[19][4] =  mapaLogico[20][4] = mapaLogico[21][4] = ESTRADA;
	for(x=4,x2=6, y=7, y2=14; x<=7; x++,x2++,y++,y2++)
		mapaLogico[x][3] = mapaLogico[x2][2] = mapaLogico[y][1] = mapaLogico[y2][1] = ESTRADA;
	for(x=18; x<=20; x++)
		mapaLogico[x][3] = ESTRADA;
	for(x=10, x2=14; x<=15; x++,x2++)
		mapaLogico[x][13] = mapaLogico[x2][2] = ESTRADA;
	for(x=9; x<=16; x++)
		mapaLogico[x][12] = ESTRADA;
	for(x=9; x<=15; x++)
		mapaLogico[x][0] = ESTRADA;
	//determina onde é torre
	mapaLogico[3][19] = mapaLogico[7][19] = mapaLogico[19][19] = mapaLogico[23][19] = mapaLogico[3][18] = mapaLogico[7][18] = mapaLogico[23][18] = mapaLogico[19][18] = TORRE;
	mapaLogico[4][17] = mapaLogico[7][17] = mapaLogico[18][17] = mapaLogico[22][17] = mapaLogico[4][16] = mapaLogico[8][16] = mapaLogico[17][16] = mapaLogico[22][16] = TORRE;
	mapaLogico[5][15] = mapaLogico[9][15] = mapaLogico[16][15] = mapaLogico[21][15] = mapaLogico[7][14] = mapaLogico[19][14] = TORRE;
	mapaLogico[9][13] = mapaLogico[16][13] = mapaLogico[8][12] = mapaLogico[17][12] = mapaLogico[6][11] = mapaLogico[19][11] = mapaLogico[5][10] = mapaLogico[9][10] = mapaLogico[16][10] = mapaLogico[21][10] = TORRE;
	mapaLogico[4][9] = mapaLogico[8][9] = mapaLogico[17][9] = mapaLogico[21][9] = mapaLogico[4][8] = mapaLogico[7][8] = mapaLogico[17][8] = mapaLogico[22][8] = TORRE;
	mapaLogico[3][7] = mapaLogico[7][7] = mapaLogico[18][7] = mapaLogico[21][7] = mapaLogico[3][6] = mapaLogico[6][6] = mapaLogico[18][6] = mapaLogico[22][6] = TORRE;
	mapaLogico[3][5] = mapaLogico[6][5] = mapaLogico[18][5] = mapaLogico[22][5] = mapaLogico[3][4] = mapaLogico[7][4] = mapaLogico[18][4] = mapaLogico[22][4] = TORRE;
	mapaLogico[3][3] = mapaLogico[8][3] = mapaLogico[17][3] = mapaLogico[21][3] = mapaLogico[5][2] = mapaLogico[8][2] = mapaLogico[13][2] = mapaLogico[18][2] = mapaLogico[6][1] = mapaLogico[18][1] = TORRE;
	for(x=11;x<=13;x++)
		mapaLogico[x][1] = TORRE;
	for(x=10;x<=14;x++)
		mapaLogico[x][14] = mapaLogico[x][11] = TORRE;
}
void nomesArquivos_montaMapaLogico3(char** mapaLogico)
{
	int x,x2, y;
	mapaLogico[10][0] = mapaLogico[11][0] = ESTRADA;
	for(x=5; x<=23;x++)
		mapaLogico[x][1] = ESTRADA;
	for(x=2; x<=23;x++)
		mapaLogico[x][2] = ESTRADA;
	for(y=3; y<=10;y++)
		mapaLogico[2][y] = ESTRADA;
	for(y=3; y<=11;y++)
		mapaLogico[3][y] = ESTRADA;
	for(y=3; y<=11;y++)
		mapaLogico[22][y] = ESTRADA;
	for(y=3; y<=7;y++)
		mapaLogico[23][y] = ESTRADA;
	for(y=7; y<=11;y++)
		mapaLogico[21][y] = ESTRADA;
	for(y=9; y<=11;y++)
		mapaLogico[20][y] = ESTRADA;
	mapaLogico[4][11] = mapaLogico[4][12] = mapaLogico[5][12] = mapaLogico[5][13] = mapaLogico[6][13] = mapaLogico[6][14] = mapaLogico[7][14] = mapaLogico[7][15] = mapaLogico[8][15] = mapaLogico[8][16] = mapaLogico[9][16] = mapaLogico[10][16] = ESTRADA;
	for(y=10; y<=14;y++)
		mapaLogico[y][17] = ESTRADA;
	for(y=10; y<=13;y++)
		mapaLogico[y][18] = mapaLogico[y][19] = ESTRADA;
	for(x=18, x2=17; x<=21;x++,x2++)
		mapaLogico[x][12] = mapaLogico[x2][13] = ESTRADA;
	for(x=16; x<=18;x++)
		mapaLogico[x][14] = ESTRADA;
	mapaLogico[15][15] = mapaLogico[16][15] = mapaLogico[14][16] = mapaLogico[15][16] = ESTRADA;
	//marca a posição das torres
	for(x=4; x<=21;x++)
		mapaLogico[x][3] = TORRE;
	for(y=3; y<=10;y++)
		mapaLogico[4][y] = TORRE;
	mapaLogico[5][11] = mapaLogico[6][12] = mapaLogico[7][13] = mapaLogico[8][14] = mapaLogico[9][15]= mapaLogico[10][15] = mapaLogico[13][16] = mapaLogico[15][14]=mapaLogico[16][13]=mapaLogico[17][12]=mapaLogico[18][11]=mapaLogico[20][8]=mapaLogico[20][7]=TORRE;
	for(x=11; x<=13;x++)
		mapaLogico[x][16] = TORRE;
	for(x=9; x<=11;x++)
		mapaLogico[19][x] = TORRE;
	mapaLogico[3][12] = mapaLogico[4][13] = mapaLogico[5][14] = mapaLogico[6][15] = mapaLogico[7][16]= mapaLogico[8][17] = mapaLogico[15][17] = mapaLogico[16][16]=mapaLogico[17][15]=mapaLogico[18][15]=mapaLogico[19][14]=mapaLogico[20][14] = mapaLogico[21][13]=mapaLogico[22][12]=mapaLogico[23][12]=TORRE;
	for(y=3; y<=6;y++)
		mapaLogico[21][y] = TORRE;
	for(y=17; y<=19;y++)
		mapaLogico[9][y] = TORRE;
	for(y=18; y<=19;y++)
		mapaLogico[14][y] = TORRE;
}
void nomesArquivos_montaMapaLogico4(char** mapaLogico)
{
	int x, x2, x3, y;
	mapaLogico[1][0] = mapaLogico[2][0] = mapaLogico[3][9] = mapaLogico[3][10] = mapaLogico[21][12]=mapaLogico[22][12]=mapaLogico[22][13]=ESTRADA;
	for(y=0;y<=12;y++)
		mapaLogico[1][y] = ESTRADA;
	for(y=0;y<=8;y++)
		mapaLogico[2][y] = ESTRADA;
	for(x=3;x<=6;x++)
		mapaLogico[x][2] = ESTRADA;
	for(x=6;x<=13;x++)
		mapaLogico[x][3] = ESTRADA;
	for(x=11;x<=14;x++)
		mapaLogico[x][4] = ESTRADA;
	for(x=14;x<=16;x++)
		mapaLogico[x][7] = ESTRADA;
	for(x=15;x<=18;x++)
		mapaLogico[x][8] = ESTRADA;
	for(x=16;x<=19;x++)
		mapaLogico[x][9] = ESTRADA;
	for(x=13;x<=15;x++)
		mapaLogico[x][5] = mapaLogico[x][6] = ESTRADA;
	for(x=19,x2=4, x3=5;x<=21;x++,x2++,x3++)
		mapaLogico[x][10] = mapaLogico[x2][10] = mapaLogico[x3][11] = ESTRADA;
	for(x=7,x2=11;x<=9;x++,x2++)
		mapaLogico[x][13]=mapaLogico[x2][15] = ESTRADA;
	mapaLogico[22][14] = mapaLogico[23][14] = mapaLogico[22][15] = mapaLogico[23][15] = mapaLogico[10][14] = mapaLogico[11][14] = mapaLogico[22][16] = mapaLogico[23][16] = mapaLogico[23][17] = mapaLogico[23][18] = ESTRADA;
	for(x=12;x<=23;x++)
		mapaLogico[x][18] = ESTRADA;
	for(x=11;x<=15;x++)
		mapaLogico[x][16] = ESTRADA;
	for(x=12,x2=14;x<=14;x++,x2++)
		mapaLogico[2][x] = mapaLogico[3][x2] = ESTRADA;
	mapaLogico[4][15] = mapaLogico[5][15] = ESTRADA;
	for(x=4;x<=8;x++)
		mapaLogico[x][16] = ESTRADA;
	for(x=6;x<=17;x++)
		mapaLogico[x][17] = ESTRADA;
	//determina as posições da torre
	for(y=0;y<=11;y++)
		mapaLogico[0][y] = TORRE;
	mapaLogico[1][14] = mapaLogico[2][15] = mapaLogico[2][16] = mapaLogico[7][10] = mapaLogico[8][11] = mapaLogico[11][13] = mapaLogico[13][14] = mapaLogico[14][15] = mapaLogico[16][16] = mapaLogico[17][16] = mapaLogico[20][12] = mapaLogico[20][11] = mapaLogico[19][11] = mapaLogico[18][10] = mapaLogico[17][10] = mapaLogico[16][10] = mapaLogico[14][8] = mapaLogico[15][9] = mapaLogico[13][7] = mapaLogico[12][6] = mapaLogico[12][5] = mapaLogico[13][3] = mapaLogico[15][4] = mapaLogico[16][5] = mapaLogico[16][6] = mapaLogico[17][7] = mapaLogico[22][10] = mapaLogico[3][5] = mapaLogico[3][6] = TORRE;
	for(x=3; x<=5;x++)
		mapaLogico[x][17] = TORRE;
	for(x=6; x<=11; x++)
		mapaLogico[x][18] = TORRE;
	for(x=13;x<=19;x++)
		mapaLogico[x][19] = TORRE;
	for(x=4;x<=6;x++)
		mapaLogico[x][9] = TORRE;
	for(x=18;x<=22;x++)
		mapaLogico[x][17] = TORRE;
	for(y=13;y<=16;y++)
		mapaLogico[21][y] = TORRE;
	for(x=6;x<=10;x++)
		mapaLogico[x][4] = TORRE;
	for(x=3;x<=5;x++)
		mapaLogico[x][3] = TORRE;
	for(x=3;x<=6;x++)
		mapaLogico[x][1] = TORRE;
	for(x=7;x<=13;x++)
		mapaLogico[x][2] = TORRE;
	for(x=20;x<=21;x++)
		mapaLogico[x][9] = TORRE;
	for(x=11;x<=13;x++)
		mapaLogico[23][x] = TORRE;
	for(x=14;x<=17;x++)
		mapaLogico[24][x] = TORRE;
}
void nomesArquivos_montaMapaLogico5(char** mapaLogico)
{}
void nomesArquivos_montaMapaLogico6(char** mapaLogico)
{}
void nomesArquivos_montaMapaLogico7(char** mapaLogico)
{}
void nomesArquivos_montaMapaLogico8(char** mapaLogico)
{}
void nomesArquivos_montaMapaLogico(char** mapaLogico, int num_fase)
{
	switch(num_fase)
	{
	case 0:
		nomesArquivos_montaMapaLogico1(mapaLogico);
		break;
	case 1:
		nomesArquivos_montaMapaLogico2(mapaLogico);
		break;
	case 2:
		nomesArquivos_montaMapaLogico3(mapaLogico);
		break;
	case 3:
		nomesArquivos_montaMapaLogico4(mapaLogico);
		break;
	case 4:
		nomesArquivos_montaMapaLogico5(mapaLogico);
		break;
	case 5:
		nomesArquivos_montaMapaLogico6(mapaLogico);
		break;
	case 6:
		nomesArquivos_montaMapaLogico7(mapaLogico);
		break;
	case 7:
		nomesArquivos_montaMapaLogico8(mapaLogico);
		break;
	}
}

