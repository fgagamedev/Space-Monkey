#ifndef CHIPANZE1_H
#define CHIPANZE1_H

#include "inimigo.h"
#include "initException.h"
#include "constantes.h"
#include "fileNotFoundException.h"

class Chipanze1 : public Inimigo
{
public:
	void init() throw (InitException, FileNotFoundException);
	~Chipanze1();
	int getHp();
	int getDano();
	int getVel();
	void mover(Direcao dir);
	void mover();
};

#endif

