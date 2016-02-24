#include "term.h"
#include <iostream>

Term::Term(int coef, int exp){
	coefficient = coef;
	exponent = exp;
}

int Term::getExp() const{
	return exponent;
}

int Term::getCoef() const{
	return coefficient;
}

void Term::setExp(int exp){
	exponent = exp;
}
void Term::setCoef(int coef){
	coefficient = coef;
}

void Term::print(bool first){

	if (coefficient > 0 && coefficient != 1){
		if (!first){
			cout << "+";
		}
		cout << coefficient;
	}
	else if (coefficient < 0 && coefficient != -1){
		cout << coefficient;
	}
	else if (coefficient == -1 && exponent == 0){
		cout << coefficient;
	}
	else if (coefficient == 1 && exponent == 0){
		cout << "+" << coefficient;  
	}
	else if (coefficient == -1){
		cout << "-";
	}
	else if (!first){
		cout << "+";
	}
	
	if (exponent == 0){
	}
	else if (exponent == 1){
		cout << "x";
	}
	else{
		cout << "x^" << exponent;
	}
}