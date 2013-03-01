#ifndef GORILA1_H
#define GORILA1_H

#include "inimigo.h"
#include "initException.h"
#include "constantes.h"
#include "fileNotFoundException.h"

class Gorila1 : public Inimigo
{
public:
	void init() throw (InitException, FileNotFoundException);
	~Gorila1();
	int getHp();
	int getDano();
	int getVel();
	void mover(Direcao dir);
	void mover();
};

#endif

