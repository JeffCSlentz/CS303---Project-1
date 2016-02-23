#include <string>
#include <list>
#include <iostream>
#include "Polynomial.h"
#include "Term.h"
#include <cstdlib>
using namespace std;

//Prototypes -------------------------------
string inputMenu();/*Function that asks the user to input his/her polynomials.
				   Returns a string*/   
char repeatMenu();/*Function that asks the user if they would like to repeat the process of the inputMenu function.
				  Returns a char.*/
list<Term>* ConstructPolynomial(string); /*Go to Main Body for details*/
char User_Interface();

int main()
{
	//int numberOfPolys = 5;
	//list<Polynomial> function; /*List that holds all of the polynomials*/
	//Polynomial *poly; /*Pointer for polynomials*/
	//poly = new Polynomial[5];
	//string input;
	//char menu;

	//do{
	//	input = inputMenu();/*Read in the data*/
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
	
	char menu_input;
	string user_polynomial;
	list<Term> Poly1, Poly2, SumPoly;	// HEY~~!! LISTEN~~!! -Navi
										// These may need to be POINTERS to lists of terms. Later functions'll may return
										// a pointer to a list of terms. So heads up.
	
	/* ----------------------------------- Main Body ----------------------------------- */

	do{
		// menu_input = UserInterface() // UserInterface() will display the menu, collect user input, 
										// and ERROR HANDLE -> returns user's option (char) 
										// Implementation details are kept neat and hidden!
		switch (menu_input)
		{
		case 1:
			user_polynomial = inputMenu();
			// Poly1 = ConstructPolynomial(user_polynomial); 
											 // ConstructPolynomial is a backbone function:
											 // ConstructPolynomial will MOST IMPORTANTLY create the actual list of terms
											 //   -> Returns a pointer to the constructed list
			// Wanna print out the user's polynomial after it's constructed? Sounds like more work, but it'll be user friendly...
			break;

		case 2:
			user_polynomial = inputMenu();
			// Poly2 = ConstructPolynomial(user_polynomial); // Same Function as case 1; differnt variable.
			// Print out user's polynomial?... No?...Okey~~...
			break;

		case 3: 
			// SumPoly = Poly1 + Poly2;		// WE may need to override the addition operator for this...
											// Keeps the main neat AF though!!
			// PRINT OUT the user's polynomial! HA! THIS PART'S REQUIRED! SO TAKE THAT!... Team... ... dang it...
			break;

		case 'q': 
			break;					/*  And actually, this line's just fine: If the user gave 'q',     /
									/   then the switch can simply pass and end the loop naturally :3 */
		}
	} while (menu_input != 'q');

	/* So we can just leave without explicitly deleting the Lists, since  /
	/  our Term class has its own Deconstructor... Right?... (Right?)	 */
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

/*list<Term>* ConstructPolynomial(string)
{
	//BODY ME!
}
*/

/*char User_Interface()
{
	//BODY ME TOO!!
}
*/

//jeff's test
