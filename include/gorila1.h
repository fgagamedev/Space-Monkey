#ifndef GORILA1_H
#define GORILA1_H

#include "inimigo.h"
#include "initException.h"
#include "constantes.h"
#include "fileNotFoundException.h"

class Gorila1 : public Inimigo
{
public:
	void init() throw (InitException, FileNotFoundException);
	
};

#endif

