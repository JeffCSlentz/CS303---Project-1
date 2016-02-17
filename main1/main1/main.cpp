string inputMenu();/*Function that asks the user to input his/her polynomials.
				   Returns a string*/
char repeatMenu();/*Function that asks the user if they would like to repeat the process of the inputMenu function.
				  Returns a char.*/
int main()
{
	list<char> function;
	string input;
	char menu;

	do{
		input = inputMenu();
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