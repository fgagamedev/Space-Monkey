#ifndef CHIPANZE2_H
#define CHIPANZE2_H

#include "inimigo.h"
#include "initException.h"
#include "constantes.h"
#include "fileNotFoundException.h"

class Chipanze2 : public Inimigo
{
public:
	void init() throw (InitException, FileNotFoundException);
	~Chipanze2();
	int getHp();
	int getDano();
	int getVel();
	void mover(Direcao dir);
	void mover();
};

#endif

