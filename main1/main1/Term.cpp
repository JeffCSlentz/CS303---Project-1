#include "term.h"
#include <iostream>

Term::Term(int coef, int exp){
	coefficient = coef;
	exponent = exp;
}

int Term::getExp(){
	return exponent;
}

int Term::getCoef(){
	return coefficient;
}

void Term::setExp(int exp){
	exponent = exp;
}
void Term::setCoef(int coef){
	coefficient = coef;
}

void Term::print(){
	if (coefficient > 0){
		cout << "+" << coefficient;
	}
	else if (coefficient == -1){
		cout << "-";
	}
	else if (coefficient != 1){
		cout << coefficient;
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