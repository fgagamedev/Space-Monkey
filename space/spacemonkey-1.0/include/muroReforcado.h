#ifndef MURO_REFORCADO_H
#define MURO_REFORCADO_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class MuroReforcado : public Torre
{
private:

public:
	void init() throw (InitException, FileNotFoundException);
	static Torre* createTorre();
	~MuroReforcado();
};

#endif
