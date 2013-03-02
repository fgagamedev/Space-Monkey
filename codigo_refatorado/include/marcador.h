 #ifndef MARCADOR_H
#define MARCADOR_H

#include"fileNotFoundException.h"
#include<SDL/SDL.h>

class Marcador{
private:
	//marcadores que aparecem na tela e acompanham o mouse
	static SDL_Surface *marcadorUsado;
	static SDL_Surface *marcadorAzul;
	static SDL_Surface *marcadorVermelho;
	static int posX, posY;
	//construtor privado para implementação do singleton (essa classe não deve ter objetos, apenas chamadas estáticas)
	Marcador();
public:
	//carrega as imagens no jogo
	static void criaMarcadores()throw(FileNotFoundException);
	//move o marcador para a posição especificada e verifica qual dos marcadores deve ser mostrado
	static void mover(int x, int y);
	//imprime o marcador após a tela ser limpada
	static void print();
	//se apaga da tela
	static void apagar();
	//libera as surfaces criadas
	static void destruirMarcadores();
};

#endif
