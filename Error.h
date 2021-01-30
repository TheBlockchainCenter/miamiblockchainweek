#pragma once
#include <string>
using namespace std;
class Error
{
	public:
		enum class ErrorTypes { INFO, ERROR, DEBUG };

		Error(ErrorTypes type, string message);
		string getMessage();
		ErrorTypes getType();

	private:
		string message;
		ErrorTypes errorType;
	
};

