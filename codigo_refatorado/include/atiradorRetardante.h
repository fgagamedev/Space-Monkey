#ifndef ATIRADOR_RETARDANTE_H
#define ATIRADOR_RETARDANTE_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AtiradorRetardante : public Torre
{
private:

public:
	void init() throw (InitException, FileNotFoundException);
	static Torre* createTorre();
	~AtiradorRetardante();
};

#endif
