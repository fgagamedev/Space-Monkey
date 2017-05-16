#include "definicoesMapaLogico.h"

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
	int x,x2;
	for(x=0;x<=5;x++){
		mapaLogico[x][3]=ESTRADA;
	}
	mapaLogico[5][4]=mapaLogico[6][4]=mapaLogico[5][5]=mapaLogico[6][5]=ESTRADA;

	for(x=6;x<=14;x++){
		mapaLogico[6][x]=mapaLogico[7][x]=ESTRADA;
	}
	for(x=8;x<=22;x++){
		mapaLogico[x][13]=mapaLogico[x][14]=ESTRADA;
	}
	mapaLogico[22][12]=mapaLogico[23][12]=mapaLogico[22][11]=mapaLogico[23][11]=ESTRADA;
	for(x=7;x<=10;x++){
		mapaLogico[23][x]=mapaLogico[24][x]=ESTRADA;
	}
	for(x=2;x<=6;x++){
		mapaLogico[24][x]=mapaLogico[25][x]=ESTRADA;
	}
	mapaLogico[25][1]=mapaLogico[26][1]=mapaLogico[26][0]=ESTRADA;

	//Torres
	mapaLogico[3][4]=mapaLogico[4][4]=mapaLogico[4][5]=mapaLogico[24][1]=mapaLogico[21][11]=mapaLogico[3][2]=
	mapaLogico[4][2]=mapaLogico[7][4]=mapaLogico[7][5]=TORRE;
	for(x=6;x<=14;x++){
		mapaLogico[5][x]=TORRE;
	}
	mapaLogico[23][14]=mapaLogico[23][13]=mapaLogico[24][12]=mapaLogico[24][11]=TORRE;
	for(x=6;x<=22;x++){
		mapaLogico[x][15]=TORRE;
	}
	for(x=2;x<=6;x++){
		mapaLogico[23][x]=TORRE;
	}
	for(x=7;x<=10;x++){
		mapaLogico[22][x]=TORRE;
	}
	for(x=6;x<=12;x++){
		mapaLogico[8][x]=TORRE;
	}
	for(x=9;x<=21;x++){
		mapaLogico[x][12]=TORRE;
	}
	for(x=7;x<=10;x++){
		mapaLogico[25][x]=TORRE;
	}
}
void nomesArquivos_montaMapaLogico3(char** mapaLogico)
{
	int x;
	for(x=0;x<=10;x++){
		mapaLogico[3][x]=ESTRADA;
	}
	for(x=9;x<=11;x++){
		mapaLogico[4][x]=ESTRADA;
	}
	mapaLogico[5][10]=mapaLogico[5][11]=mapaLogico[11][12]=ESTRADA;
	for(x=6;x<=13;x++){
		mapaLogico[x][11]=ESTRADA;
	}
	for(x=12;x<=19;x++){
		mapaLogico[x][12]=ESTRADA;
	}
	for(x=13;x<=19;x++){
		mapaLogico[x][13]=ESTRADA;
	}

	// Torres
	for(x=1;x<=8;x++){
		mapaLogico[4][x]=TORRE;
	}
	mapaLogico[5][9]=mapaLogico[2][9]=mapaLogico[2][10]=mapaLogico[11][13]=TORRE;
	mapaLogico[14][11]=mapaLogico[14][12]=TORRE;
	for(x=4;x<=10;x++){
		mapaLogico[x][12]=TORRE;
	}

}
void nomesArquivos_montaMapaLogico4(char** mapaLogico)
{
	int x;
	for(x=0;x<=6;x++){
		mapaLogico[24][x]=mapaLogico[25][x]=ESTRADA;
	}
	mapaLogico[22][5]=mapaLogico[22][6]=mapaLogico[23][5]=mapaLogico[23][6]=mapaLogico[20][8]=ESTRADA;
	for(x=18;x<=22;x++){
		mapaLogico[x][7]=ESTRADA;
	}
	for(x=8;x<=12;x++){
		mapaLogico[18][x]=mapaLogico[19][x]=ESTRADA;
	}
	mapaLogico[18][13]=ESTRADA;
	mapaLogico[16][12]=mapaLogico[17][12]=mapaLogico[16][13]=mapaLogico[17][13]=ESTRADA;
	for(x=13;x<=19;x++){
		mapaLogico[15][x]=ESTRADA;
	}
	for(x=14;x<=19;x++){
		mapaLogico[16][x]=ESTRADA;
	}
	for(x=0;x<=13;x++){
		mapaLogico[x][19]=ESTRADA;
	}

	// Torres
	for(x=1;x<=4;x++){
		mapaLogico[23][x]=TORRE;
	}
	mapaLogico[24][4]=mapaLogico[21][5]=mapaLogico[21][6]=TORRE;
	for(x=18;x<=20;x++){
		mapaLogico[x][6]=TORRE;
	}
	mapaLogico[17][10]=mapaLogico[17][11]=mapaLogico[16][11]=mapaLogico[15][12]=TORRE;
	for(x=9;x<=12;x++){
		mapaLogico[20][x]=TORRE;
	}
	mapaLogico[21][8]=mapaLogico[22][8]=mapaLogico[23][7]=mapaLogico[24][7]=mapaLogico[25][7]=TORRE;
	for(x=13;x<=18;x++){
		mapaLogico[14][x]=TORRE;
	}
	for(x=2;x<=13;x++){
		mapaLogico[x][18]=TORRE;
	}
	for(x=14;x<=19;x++){
		mapaLogico[17][x]=TORRE;
	}
	mapaLogico[18][14]=mapaLogico[19][13]=TORRE;
}
void nomesArquivos_montaMapaLogico5(char** mapaLogico)
{
	int x;
	for(x=0;x<=4;x++){
		mapaLogico[25][x]=ESTRADA;
	}
	mapaLogico[24][3]=mapaLogico[24][4]=mapaLogico[23][4]=mapaLogico[21][6]=mapaLogico[22][6]=
	mapaLogico[21][7]=ESTRADA;
	for(x=21;x<=23;x++){
		mapaLogico[x][5]=ESTRADA;
	}
	for(x=8;x<=11;x++){
		mapaLogico[20][x]=ESTRADA;
		mapaLogico[19][x]=ESTRADA;
	}
	for(x=11;x<=16;x++){
		mapaLogico[18][x]=ESTRADA;
	}
	mapaLogico[19][12]=mapaLogico[19][13]=mapaLogico[16][15]=mapaLogico[16][16]=
	mapaLogico[17][15]=mapaLogico[17][16]=mapaLogico[15][16]=mapaLogico[15][17]=
	mapaLogico[14][17]=mapaLogico[14][18]=ESTRADA;
	for(x=0;x<=14;x++){
		mapaLogico[x][18]=ESTRADA;
	}

	//Torres
	for(x=2;x<=13;x++){
		mapaLogico[x][17]=TORRE;
	}
	mapaLogico[14][16]=mapaLogico[15][15]=mapaLogico[16][14]=mapaLogico[19][7]=
	mapaLogico[20][6]=mapaLogico[20][5]=mapaLogico[21][4]=mapaLogico[22][4]=
	mapaLogico[23][3]=mapaLogico[22][2]=TORRE;
	for(x=11;x<=14;x++){
		mapaLogico[17][x]=TORRE;
	}
	for(x=8;x<=10;x++){
		mapaLogico[18][x]=TORRE;
	}
	mapaLogico[22][7]=mapaLogico[20][12]=mapaLogico[20][13]=mapaLogico[15][18]=TORRE;
	for(x=8;x<=10;x++){
		mapaLogico[21][x]=TORRE;
	}
	for(x=14;x<=16;x++){
		mapaLogico[19][x]=TORRE;
	}
	for(x=16;x<=18;x++){
		mapaLogico[x][17]=TORRE;
	}
}
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
	default:
		break;
	}
}

