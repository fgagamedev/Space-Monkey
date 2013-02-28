#ifndef ATIRADOR_IRON_MAN_H
#define ATIRADOR_IRON_MAN_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class IronMan : public Torre
{
private:

public:
	void init() throw (InitException, FileNotFoundException);
	static Torre* createTorre();
	~IronMan();
};

#endif
