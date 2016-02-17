#include <string>
#include <list>
#include <iostream>
#include "term.h"
using namespace std;


//global variables

string menu = "Welcome to the fabulous polynomial adder.\n"
"Please enter a choice."
"1. Input first polynomial."
"2. Input second polynomial."
"3. Add first and second polynomial and display result."
"4. Quit.";
	


//Function Prototypes

string inputMenu();/*Function that asks the user to input his/her polynomials.
				   Returns a string*/

string secondInput();/*needs comment*/

char repeatMenu();/*Function that asks the user if they would like to repeat the process of the inputMenu function.
				  Returns a char.*/
int main()
{
	//list<char> function;

	string input1;
	string input2;

	list<Term> list1;
	list<Term> list2;
	list<Term> list3;

	char repeat = 'y';
	int menu_choice;

	do{

		cout << menu;
		cin >> menu_choice;

		switch (menu_choice){
			case 1:
				input1 = input1Menu();
				break;
			case 2:
				input2 = input2Menu();
				break;
			case 3:
				//parse inputs into lists
				//merge list1 and list2 into list3.
			case 4:
				repeat = 'q';
				break;
		}


		/*
		for (string::iterator it = input.begin(); it != input.end(); ++it){
			if ((*it == 'X') || (*it == 'x')) {
				++it;
				if ((*it == '^')) {
					++it;
					function.push_back(*it);
				}
				cout << *it;
			}
		}
		*/

		//menu = repeatMenu();

	} while ((repeat == 'y') || (repeat == 'Y'));

	system("pause");
	return 0;
}
string input1Menu(){
	string input;
	cout << "Please enter your polynomial in a user-friendly fashion." << endl;
	cout << "For example: 3x^2 - 1x^2 + 1" << '\t' << "Variables do not need to be entered in order" << endl;
	cin >> input;
	return input;
}

string input2Menu(){
	string input2;
	cout << "Please enter the second Polynomial." << endl;
	cin >> input2;
	return input2;
}
char repeatMenu(){
	char menu;
	cout << "\nWould you like to enter another polynomial?" << endl;
	cout << "Enter N or n for No and Y or y for yes ";
	cin >> menu;
	cout << endl;
	return menu;
}
