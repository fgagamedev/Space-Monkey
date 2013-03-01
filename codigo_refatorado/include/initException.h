#ifndef INIT_EXCEPTION_H
#define INIT_EXCEPTION_H

#include <string>

using namespace std;

class InitException {
private:
	string message;
public:
	InitException(const string& message) { this->message = message; }
	string getMessage() const { return message; }

};

#endif

