#ifndef FILENOTFOUND_EXCEPTION_H
#define FILENOTFOUND_EXCEPTION_H

#include <string>
#include "exception.h"

using namespace std;

class FileNotFoundException : public Exception {
private:
	
public:
	FileNotFoundException(const string& message) : Exception(message) {}
};

#endif

