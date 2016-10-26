#ifndef EXCEPTION_PAI_H
#define EXCEPTION_PAI_H

#include <string>

using namespace std;

class Exception {
private:
	string message;
public:
	Exception(const string& message) { this->message = message; }
	string getMessage() const { return message; }

};

#endif

