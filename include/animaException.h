#ifndef ANIMA_EXCEPTION_H
#define ANIMA_EXCEPTION_H

#include <string>
#include "exception.h"

class AnimaException : public Exception {
private:
	
public:
	AnimaException(const string& message) : Exception(message) {}
};

#endif

