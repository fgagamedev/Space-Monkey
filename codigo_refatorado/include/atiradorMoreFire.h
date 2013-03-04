#ifndef ATIRADOR_MF_H
#define ATIRADOR_MF_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AtiradorMoreFire : public Torre
{
private:

public:
	void init() throw (InitException, FileNotFoundException);
	static Torre* createTorre();
	~AtiradorMoreFire();
};

#endif
