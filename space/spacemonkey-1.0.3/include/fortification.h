#ifndef FORTIFICATION_H
#define FORTIFICATION_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class Fortification : public Torre
{
private:

public:
	void init() throw (InitException, FileNotFoundException);
	static Torre* createTorre();
	~Fortification();
};

#endif
