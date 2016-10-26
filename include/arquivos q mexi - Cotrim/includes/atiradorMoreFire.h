#ifndef ATIRADOR_MF_H
#define ATIRADOR_MF_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AtiradorMoreFire : public Torre
{
private:

public:
	void init(int posX, int posY) throw (InitException, FileNotFoundException);
	~AtiradorMoreFire();
};

#endif
