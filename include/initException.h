#ifndef INIT_EXCEPTION_H
#define INIT_EXCEPTION_H

#include <string>
#include "exception.h"

using namespace std;

class InitException : public Exception {
private:
	
public:
	InitException(const string& message) : Exception(message) {}
};

#endif

