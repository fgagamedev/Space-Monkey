#ifndef ORANGOTANGO_H
#define ORANGOTANGO_H

#include "inimigo.h"
#include "constantes.h"
#include "initException.h"
#include "fileNotFoundException.h"

class Orangotango : public Inimigo
{
public:
	void init() throw (InitException, FileNotFoundException);
	~Orangotango();
	int getHp();
	int getDano();
	int getVel();
	void mover(Direcao dir);
	void mover();
};

#endif

