#ifndef ATIRADOR_AGENTESPROTETORE_H
#define ATIRADOR_AGENTESPROTETORE_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AgentesProtetores : public Torre
{
private:

public:
	void init() throw (InitException, FileNotFoundException);
	static Torre* createTorre();
	~AgentesProtetores();
};

#endif
