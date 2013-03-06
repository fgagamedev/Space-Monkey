#include "constantes.h"
#include "nomesArquivos.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

void nomesArquivos_montaMapaLogicoGeral(int num_fase, char** mapaLogico){

	ifstream bmpMapa;
	bmpMapa.open( (PATH+BMP_MAPAS[num_fase]).c_str() );

	if(!bmpMapa.is_open()){
		cout << "Nao foi possivel abrir arquivo" << endl;
		exit(ERRO_ABRIR_ARQUIVO);
	}

	int i,j;
	for(i=0; i<QTD_COLUNAS_ARQUIVO; i++){
		if(bmpMapa.good()){	
			string linha;
			getline(bmpMapa,linha);
			char *linhaArray = (char*) linha.c_str();	
			for(j=0; j<QTD_LINHAS_ARQUIVO; j++){
				switch (linhaArray[j]){
					case '0': 
						mapaLogico[j][i] = linhaArray[j];
						break;
					case '1': 
						mapaLogico[j][i] = linhaArray[j];
						break;
					case '2': 
						mapaLogico[j][i] = linhaArray[j];
						break;
					case '3': 
						mapaLogico[j][i] = linhaArray[j];
						break;
				}
			}
		}
	}

	bmpMapa.close();

	for(i=0; i<QTD_COLUNAS_ARQUIVO; i++){
		for(j=0; j<QTD_LINHAS_ARQUIVO; j++)
			cout << mapaLogico[j][i];
		cout << endl;
	}

}


