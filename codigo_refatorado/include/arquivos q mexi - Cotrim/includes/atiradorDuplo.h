#ifndef ATIRADOR_DUPLO_H
#define ATIRADOR_DUPLO_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AtiradorDuplo : public Torre
{
private:

public:
	void init(int posX, int posY) throw (InitException, FileNotFoundException);
	~AtiradorDuplo();
};

#endif
