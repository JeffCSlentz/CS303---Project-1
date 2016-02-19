#include <string>
#include <list>
#include <iostream>
#include "Polynomial.h"
#include <cstdlib>
using namespace std;
string inputMenu();/*Function that asks the user to input his/her polynomials.
				   Returns a string*/   
char repeatMenu();/*Function that asks the user if they would like to repeat the process of the inputMenu function.
				  Returns a char.*/
int main()
{
	int numberOfPolys = 5;
	list<Polynomial> function; /*List that holds all of the polynomials*/
	Polynomial *poly; /*Pointer for polynomials*/
	poly = new Polynomial[5];
	string input;
	char menu;

	do{
		input = inputMenu();/*Read in the data*/
		for (string::iterator it = input.begin(); it != input.end(); ++it){/*Iterate through the string data*/
			if((*it == '-')){ /*If the char variable is a negative sign. Then create a new polynomial*/
				poly = new Polynomial; //Creates a new polynomial
				poly->setNegative(true); //Sets that polynomials leading coefficient to negative
				++it; //Go to the next character in the string

				if ((*it == 'X') || (*it == 'x')) {
					poly->setVariable(*it);
					++it;
					if (*it == '^'){
						poly->setGreaterThan(true);
						++it;
						poly->setExponent(*it);
						function.push_back(poly[0]);
					}
				}
				else
				{
					poly->setCoefficient(*it);
				}
				numberOfPolys++;
			}
		}
		cout << function.front().getExponent() << endl;
		menu = repeatMenu();
	} while ((menu == 'y') || (menu == 'Y'));

	system("pause");
	return 0;
}
string inputMenu(){
	string input;
	cout << "Please enter your polynomial in a user-friendly fashion." << endl;
	cout << "For example: 3x^2 - 1x^2 + 1" << '\t' << "Varaibles do not need to be entered in order" << endl;
	cin >> input;
	return input;
}
char repeatMenu(){
	char menu;
	cout << "\nWould you like to enter another polynomial?" << endl;
	cout << "Enter N or n for No and Y or y for yes ";
	cin >> menu;
	cout << endl;
	return menu;
}

//jeff's test
