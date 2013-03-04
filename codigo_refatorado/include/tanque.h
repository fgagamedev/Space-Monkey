#ifndef ATIRADOR_BOMBERMAN_H
#define ATIRADOR_BOMBERMAN_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class Tanque : public Torre
{
private:

public:
	void init(int posX, int posY) throw (InitException, FileNotFoundException);
	~Tanque();
};

#endif
