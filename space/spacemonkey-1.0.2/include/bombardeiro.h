#ifndef ATIRADOR_BOMB_H
#define ATIRADOR_BOMB_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class Bombardeiro : public Torre
{
private:

public:
	void init() throw (InitException, FileNotFoundException);
	static Torre* createTorre();
	~Bombardeiro();
};

#endif
