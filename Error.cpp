#include "Error.h"
Error::Error(ErrorTypes type, string message)
{
	errorType = type;
	this->message = message;
}

string Error::getMessage()
{
	return message;
}

Error::ErrorTypes Error::getType()
{
	return errorType;
}

