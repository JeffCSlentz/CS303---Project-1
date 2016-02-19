#pragma once
class Polynomial
{
public:
	Polynomial() { variable_greater_than_one = false; negative = false; coefficient = 0; variable = ' '; variable_exponent = 0; }
	~Polynomial() { ; }
	void setPoly(bool neg, char coeff, char var, bool greaterThan, char exponent );//Sets the Polynomial variables.
	char getCoeff() const { return coefficient; }//Returns the leading coefficient
	char getVariable() const { return variable; }//Returns the variable fo the polynomial
	char getExponent() const { return variable_exponent; }//Returns the exponent
	void setNegative(bool neg) { negative = neg; }
	void setVariable(char var) { variable = var; }
	void setCoefficient(char coeff) { coefficient = coeff; }
	void setGreaterThan(bool greaterThan) { variable_greater_than_one = greaterThan; }
	void setExponent(char exponent) { variable_exponent = exponent; }

private:
	bool negative = false; //Bool to determine if the polynomial is negative or positive
	char coefficient; //Leading coefficient of the term
	char variable; //Variable of the polynomial. X or Y or Z
	bool variable_greater_than_one; //Bool to determine if the variable is X, or X < X^2
	char variable_exponent; //Determines what the size of the exponent is. X^2, X^3, X^4
};