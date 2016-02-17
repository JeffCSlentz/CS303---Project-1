#include "term.h"

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
