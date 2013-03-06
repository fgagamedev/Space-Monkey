#ifndef MURO_H
#define MURO_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class Muro : public Torre
{
private:

public:
	void init(int posX, int posY) throw (InitException, FileNotFoundException);
	~Muro();
};

#endif
