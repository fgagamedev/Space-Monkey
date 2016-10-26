#ifndef EXIT_EXCEPTION_H
#define EXIT_EXCEPTION_H

#include <string>
#include "exception.h"

using namespace std;

class ExitException : public Exception {
private:
	
public:
	ExitException(const string& message) : Exception(message) {}
};

#endif

