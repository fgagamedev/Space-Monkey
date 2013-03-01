#ifndef ATIRADOR_ANGULADO_H
#define ATIRADOR_ANGULADO_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AtiradorAngulado : public Torre
{
private:

public:
	void init() throw (InitException, FileNotFoundException);
	static Torre* createTorre();
	~AtiradorAngulado();
};

#endif
