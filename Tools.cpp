#include "Tools.h"
void Tools::write_error(Error error)
{
	ofstream message("/opt/node/log"); // direct for error to be logged in log dir

	// Check to see if text file exists, if not create it
	// Otherwise append data to it
	if (error.getType() == Error::ErrorTypes::INFO)
	{

		message.open("INFO.txt", ofstream::app);
		message << error.getMessage() << std::endl;

	}
	else if (error.getType() == Error::ErrorTypes::ERROR)
	{

		message.open("ERROR.txt", ofstream::app);
		message << error.getMessage() << std::endl;

	}
	else if (error.getType() == Error::ErrorTypes::DEBUG)
	{

		message.open("DEBUG.txt", ofstream::app);
		message << error.getMessage() << std::endl;

	}
	message.close();

}