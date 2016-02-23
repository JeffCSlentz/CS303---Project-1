#include "Polynomial.h"
void Polynomial::setPoly(bool neg, char coeff, char var, bool greaterThan, char exponent) {
	negative = neg;
	coefficient = coeff;
	variable = var;
	variable_greater_than_one = greaterThan;
	variable_exponent = exponent;
}

