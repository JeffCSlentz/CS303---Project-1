#include <string>
#include <list>
#include <iostream>
//#include "Polynomial.h"
#include "Term.h"
#include <cstdlib>
using namespace std;

//global variables

string menu = 
"1. Input first polynomial.\n"
"2. Input second polynomial.\n"
"3. Add first and second polynomial and display result.\n"
"4. Quit.\n"
"Please choose: ";

string welcome =
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
"~~~~~Welcome to the fabulous polynomial adder!~~~~~\n"
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";



//Prototypes -------------------------------
string grabPoly();/*Function that asks the user to input his/her polynomials.
				   Returns a string*/   
void sortPoly(list<Term>& poly);

bool comp(const Term& a, const Term& b);

//void sumFun(list<Term>& poly1, list<Term>& poly2, list<Term>& polySum);
void printPoly(list<Term>& poly);

void sumFun(list<Term>& poly1, list<Term>& poly2);

void cleanPoly(list<Term>& poly);

char repeatMenu();/*Function that asks the user if they would like to repeat the process of the grabPoly function.
				  Returns a char.*/
void constructPoly(string userPoly, list<Term>& poly); /*Go to Main Body for details*/
//char User_Interface();

int main()
{
	//int numberOfPolys = 5;
	//list<Polynomial> function; /*List that holds all of the polynomials*/
	//Polynomial *poly; /*Pointer for polynomials*/
	//poly = new Polynomial[5];
	//string input;
	//char menu;

	//do{
	//	input = grabPoly();/*Read in the data*/
	//	for (string::iterator it = input.begin(); it != input.end(); ++it){/*Iterate through the string data*/
	//		if((*it == '-')){ /*If the char variable is a negative sign. Then create a new polynomial*/
	//			poly = new Polynomial; //Creates a new polynomial
	//			poly->setNegative(true); //Sets that polynomials leading coefficient to negative
	//			++it; //Go to the next character in the string

	//			if ((*it == 'X') || (*it == 'x')) {
	//				poly->setVariable(*it);
	//				++it;
	//				if (*it == '^'){
	//					poly->setGreaterThan(true);
	//					++it;
	//					poly->setExponent(*it);
	//					function.push_back(poly[0]);
	//				}
	//			}
	//			else
	//			{
	//				poly->setCoefficient(*it);
	//			}
	//			numberOfPolys++;
	//		}
	//	}
	//	cout << function.front().getExponent() << endl;
	//	menu = repeatMenu();
	//} while ((menu == 'y') || (menu == 'Y'));
	//system("pause");

	/* ================================ PROGRAM Rigidbody =============================  /
	/                 Tedious work will be wrestled out within functions.                /
	/  -------------------------- Variable Declarations ------------------------------  */ 
	
	int menu_input;
	string user_poly;
	list<Term> Poly1, Poly2, SumPoly;
	
	/* ----------------------------------- Main Body ----------------------------------- */

	cout << welcome;

	do{
		// menu_input = UserInterface() // UserInterface() will display the menu, collect user input, 
										// and ERROR HANDLE -> returns user's option (char) 
										// Implementation details are kept neat and hidden!

		cout << menu;
		cin >> menu_input;				//sorry, i skipped UI, YOLO - Jeff


		switch (menu_input)
		{
		case 1:
			user_poly = grabPoly();				//Grab raw string input.
			Poly1.clear();						//Clear the list.

			constructPoly(user_poly, Poly1);	//Build the list.

			cout << "You entered: ";
			printPoly(Poly1);
			break;

		case 2:
			user_poly = grabPoly();				//Read case 1.
			Poly2.clear();

			constructPoly(user_poly, Poly2);

			cout << "You entered: ";
			printPoly(Poly2);
			break;

		case 3:
			SumPoly.clear();

			if (!Poly1.empty()) Poly1.sort();
			if (!Poly2.empty()) Poly2.sort();
			sumFun(Poly1, Poly2);

			if (!Poly2.empty()) cleanPoly(Poly2);
			
			
			if (!Poly1.empty()) SumPoly.merge(Poly1);
			if (!Poly2.empty()) SumPoly.merge(Poly2);

			if (!SumPoly.empty()){
				cleanPoly(SumPoly);

				cout << "\nFinal polynomial is: ";

				printPoly(SumPoly);		//Print it nicely.
			}
			else{
				cout << endl << "Something went wrong. =(" << endl;
			}
			break;

		case 4: 
			break;					//I switched it back to 4 because it gave me an inifite loop otherwise :O -Jeff
		}
	} while (menu_input != 4);

	/* So we can just leave without explicitly deleting the Lists, since  /
	/  our Term class has its own Deconstructor... Right?... (Right?)	 */
	//Probably? -Jeff
	return 0;	
}

string grabPoly(){
	string input;
	cout << "\nEnter your polynomial without spaces. For example: \"3x^2+x-54\"" << endl;
	cin >> input;
	cout << "\n";
	return input;
}


//DEPRACATED
char repeatMenu(){
	char menu;
	cout << "\nWould you like to enter another polynomial?" << endl;
	cout << "Enter N or n for No and Y or y for yes ";
	cin >> menu;
	cout << endl;
	return menu;
}


//This function takes in a raw string and an empty list and populates that list.
void constructPoly(string userPoly, list<Term>& poly){

	string::iterator itr = userPoly.begin();

	if (*itr != '-'){		//Add a plus to the beginning if starting term isn't negative
		userPoly = "+" + userPoly;
		itr = userPoly.begin();
	} 


	while (itr != userPoly.end()){

		bool signC; // pos = true, neg = false.   C = Coef, E =Exp
		bool signE = true;

		string tempCoef = ""; //temporary coefficient holder
		string tempExp = ""; //temporary exponent holder


		//Check first character for positive or negative
		//		-123x^-34
		//		^
		if (itr != userPoly.end() && *itr == '+'){
			signC = true;
		}
		else{
			signC = false;
		}

		itr++;

		//Check for x after the + or - . This means coef must be 1.
		//+x
		// ^
		if (itr != userPoly.end() && *itr == 'x'){
			tempCoef = '1';
		}

		//If the iterator isn't currently on x, +, or -, it's a number so add it to the coefficient string.
		//		-123x^-34
		//		 ^^^
		while (itr != userPoly.end() && *itr != 'x' && *itr != '+' && *itr != '-'){
			tempCoef += *itr;
			itr++;
		}


		//If the next iterator after the coefficients is the end, +, or -, the exponent is 0. Example below.
		//234+2x^3				234
		//   ^					   ^
		if (itr == userPoly.end() || *itr == '+' || *itr == '-'){
			tempExp = '0';
		}
		else if (itr != userPoly.end()){
			//Skip over x.
			//54x^34
			//	^
			itr++;


			if (itr == userPoly.end()){
				tempExp = '1';
			}
			//If next char is + or -, there was no carrot and the exponent is one. Example below.
			//543x+34x^3
			//	  ^
			else if (itr != userPoly.end() && *itr == '+' || *itr == '-'){
				tempExp = "1";
			}

			//If next char is a carrot, we have exponents.
			else if (itr != userPoly.end() && *itr == '^'){

				itr++; //Skip over the carrot

				//If the next character is a negative, change signE and iterate forward
				if (itr != userPoly.end() && *itr == '-'){
					signE = false;
					itr++;
				}

				// Iterate, adding onto tempExp until the end or a + or - is reached.
				//3x^342+34
				//	 ^^^
				while (itr != userPoly.end() && *itr != '+' && *itr != '-'){
					tempExp += *itr;
					itr++;
				}
			}
		}

		//Convert the strings to integers.
		int coef = stoi(tempCoef);
		int exp = stoi(tempExp);

		//Change signs if necessary
		if (!signC){
			coef *= -1;
		}

		if (!signE){
			exp *= -1;
		}

		//Create a new term and push it onto the poly list.
		Term a(coef, exp);
		poly.push_back(a);
	}
}



void sumFun(list<Term>& poly1, list<Term>& poly2){
	if (poly1.empty() || poly2.empty()){
		return;
	}
	for (list<Term>::iterator itr1 = poly1.begin(); itr1 != poly1.end(); itr1++){
		for (list<Term>::iterator itr2 = poly2.begin(); itr2 != poly2.end(); itr2++){
			if (itr1->getExp() == itr2->getExp()){
				itr1->setCoef(itr1->getCoef() + itr2->getCoef());
				itr2->setCoef(0);
			}
		}
	}
}

void printPoly(list<Term>& poly){
	bool first = true;
	for (list<Term>::iterator itr = poly.begin(); itr != poly.end(); itr++){
		itr->print(first);
		first = false;
	}
	cout << endl << endl;
}

void cleanPoly(list<Term>& poly){
	list<Term>::iterator itr = poly.begin();
	while (itr != poly.end()){
		if (itr->getCoef() == 0){
			itr = poly.erase(itr);
			if (itr == poly.end()) return;
		}
		else{
			itr++;
		}
	}
	return;
}
/*char User_Interface()
{
	//BODY ME TOO!!
	// no.
}
*/

//jeff's test
