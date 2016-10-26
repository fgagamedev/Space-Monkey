#ifndef ATIRADOR_RETARDANTE_H
#define ATIRADOR_RETARDANTE_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AtiradorRetardante : public Torre
{
private:

public:
	void init(int posX, int posY) throw (InitException, FileNotFoundException);
	~AtiradorRetardante();
};

#endif
