#ifndef ATIRADOR_ANGULADO_H
#define ATIRADOR_ANGULADO_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AtiradorAngulado : public Torre
{
private:

public:
	void init(int posX, int posY) throw (InitException, FileNotFoundException);
	~AtiradorAngulado();
};

#endif
