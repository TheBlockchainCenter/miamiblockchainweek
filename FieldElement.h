#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Tools.h"
#include "Error.h"
using namespace std;

class FieldElement
{
	private:
		double number;
		double prime;
	public:
		
		FieldElement(double number, double prime);
		string toString();
		// Operator Overloads

		bool operator == (FieldElement * other);
		bool operator !=(FieldElement* other);
		FieldElement operator + (FieldElement* other);
		FieldElement operator -(FieldElement* other);
		FieldElement operator *(FieldElement* other);
		FieldElement operator /(FieldElement* other);

		// Power
		FieldElement pow(double exponent); // FieldElement's own power method, use std::pow() for C++ one


};

