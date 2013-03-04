#ifndef ATIRADOR_AGENTESPROTETORE_H
#define ATIRADOR_AGENTESPROTETORE_H

#include "torre.h"
#include "fileNotFoundException.h"
#include "initException.h"

class AgentesProtetores : public Torre
{
private:

public:
	void init(int posX, int posY) throw (InitException, FileNotFoundException);
	~AgentesProtetores();
};

#endif
