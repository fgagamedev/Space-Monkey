#ifndef GAMEOVEREXCEPTION
#define GAMEOVEREXCEPTION

#include <string>
#include "exception.h"

using namespace std;

class GameOverException : public Exception {
private:
	
public:
	GameOverException(const string& message) : Exception(message) {}
};

#endif

