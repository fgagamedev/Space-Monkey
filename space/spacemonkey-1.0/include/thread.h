#ifndef MINHA_THREAD_H
#define MINHA_THREAD_H

#include <SDL/SDL_thread.h>
#include "initException.h"
#include "exitException.h"

class Thread
{
private:
	static SDL_Thread *thread;	
public:
	static void initThread() throw (InitException, ExitException);
	static bool booleanoGlobal;
};

#endif

