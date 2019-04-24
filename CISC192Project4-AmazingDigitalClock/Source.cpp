//This program takes in a given time from the user and determines if that time is normal or lucky.  The program also displays if there is any meaning behind the given time
//written by Brent Kinney 4/25/19

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool normalTime(int hourDigit1, int hourDigit2, int minDigit1, int minDigit2)
{
	if ((hourDigit1 + hourDigit2) == (minDigit1 + minDigit2))
		return true;
	else
		return false;
}

int main()
{
	char choice = 'y';
	while (choice == 'y' || choice == 'Y')
	{
		string timeGiven;
		cout << "Enter a time (HH:MM): ";
		getline(cin, timeGiven);
		cout << timeGiven << " is a normal time" << endl;


		
		//see if the user wants to continue and continue if desired
		cout << "Continue? (Y/N): ";
		cin >> choice;
		cout << endl;
	}
	//display author of the program
	cout << "Programmed by Brent Kinney" << endl;

	cout << "Press [Enter] key to end..."; //prompt lets user know
	cin.ignore(256, '\n');
	cin.get();

	return 0;
}