#ifndef ATIRADOR_SIMPLES_H
#define ATIRADOR_SIMPLES_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AtiradorSimples : public Torre
{
private:

public:
	void init(int posX,int posY) throw (InitException, FileNotFoundException);
	~AtiradorSimples();
};

#endif
