#include "FieldElement.h"
FieldElement::FieldElement(double number, double prime)
{
	
	if (number >= prime || number < 0)
	{

		string message = "Num " + std::to_string(number) + " not in field range 0 to " + std::to_string(prime -1);
		Error error(Error::ErrorTypes::ERROR, message);
		Tools::write_error(error);
		throw error;
	}
	this->number = number;
	this->prime = prime;
}

string FieldElement::toString()
{
	return "FieldElement_" + std::to_string(prime) + "(" + to_string(number) + ")";
}

 bool FieldElement::operator ==(FieldElement * other)
{
	bool check;
	if (other == NULL)
	{
		check = false;
	}

	else if (number == other->number && prime == other->prime)
	{
		check = true;
	}
	else
	{
		check = false;
	}
	return check;

}

bool FieldElement::operator !=(FieldElement* other)
{
	bool check;
	if (other == NULL)
	{
		check = true;
	}

	else if (number != other->number || prime != other->prime)
	{
		check = true;
	}
	else
	{
		check = false;
	}

	return check;
}

FieldElement FieldElement::operator +(FieldElement* other)
{
	if (prime != other->prime)
	{
		string message = "Cannot add two numbers in different Fields";
		Error error(Error::ErrorTypes::ERROR, message);

		Tools::write_error(error);
		throw error;
	}
	
	double n = fmod((number + other->number), prime);

	FieldElement field_element(n, prime);

	return field_element;
}

FieldElement FieldElement::operator -(FieldElement* other)
{
	if (prime != other->prime)
	{
		string message = "Cannot subtract two numbers in different Fields";
		Error error(Error::ErrorTypes::ERROR, message);

		Tools::write_error(error);
		throw error;
	}

	double n = fmod((number - other->number), prime);

	FieldElement field_element(n, prime);

	return field_element;
}

FieldElement FieldElement::operator *(FieldElement* other)
{
	if (prime != other->prime)
	{
		string message = "Cannot multiply two numbers in different Fields";
		Error error(Error::ErrorTypes::ERROR, message);

		Tools::write_error(error);
		throw error;
	}

	double n = fmod((number  * other->number), prime);

	FieldElement field_element(n, prime);

	return field_element;
}

FieldElement FieldElement::pow(double exponent)
{
	double n = fmod(exponent, prime - 1);
	double num = fmod(std::pow(number, n), prime);

	FieldElement field_element(num, prime);

	return field_element;
}

FieldElement FieldElement::operator /(FieldElement* other)
{
	if (prime != other->prime)
	{
		string message = "Cannot divide two numbers in different Fields";
		Error error(Error::ErrorTypes::ERROR, message);
		Tools::write_error(error);
		throw error;
	}

	double n = fmod((number * fmod(std::pow(other->number, prime - 2), prime)), prime);

	FieldElement field_element(n, prime);
	return field_element;
}

