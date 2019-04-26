//This program takes in a given time from the user and determines if that time is normal or lucky.  The program also displays if there is any meaning behind the given time
//written by Brent Kinney 4/25/19

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//this function tests if the given time is a lucky time
bool luckyTime(int hourDigit1, int hourDigit2, int minDigit1, int minDigit2)
{
	if ((hourDigit1 + hourDigit2) == (minDigit1 + minDigit2))
		return true;
	else
		return false;
}

//this function tests if the given time has digits that are in ascending order
bool ascendingOrder(int hourDigit1, int hourDigit2, int minDigit1, int minDigit2)
{
	if ((hourDigit2 - hourDigit1 == 1 && minDigit1 - hourDigit2 == 1 && minDigit2 - minDigit1 == 1) || (minDigit1 - hourDigit2 == 1 && minDigit2 - minDigit1 == 1))
		return true;
	else
		return false;
}

//this function tests if the given time has digits that are in descending order
bool decendingOrder(int hourDigit1, int hourDigit2, int minDigit1, int minDigit2)
{
	if (hourDigit2 - minDigit1 == 1 && minDigit1 - minDigit2 == 1)
		return true;
	else
		return false;
}

//this function tests if the given time contains all the same digits
bool sameDigits(int hourDigit1, int hourDigit2, int minDigit1, int minDigit2)
{
	if ((hourDigit1 == hourDigit2 && hourDigit2 == minDigit1 && minDigit1 == minDigit2) || (hourDigit2 == minDigit1 && minDigit1 == minDigit2))
		return true;
	else
		return false;
}



int main()
{
	string timeGiven, timeType, messageType;
	int h1 = 0;
	int h2 = 0;
	int m1 = 0;
	int m2 = 0;
	char choice = 'y';
	while (choice == 'y' || choice == 'Y')
	{
		//ask for time from users
		cout << "Enter a time (HH:MM): ";
		cin >> timeGiven;

		//determine if hours have one or two digits and set values accordingly
		if (timeGiven.size() == 5)
		{
			h1 = timeGiven[0] - '0';
			h2 = timeGiven[1] - '0';
			m1 = timeGiven[3] - '0';
			m2 = timeGiven[4] - '0';
		}
		else if (timeGiven.size() == 4)
		{
			h1 = 0;
			h2 = timeGiven[0] - '0';
			m1 = timeGiven[2] - '0';
			m2 = timeGiven[3] - '0';
		}

		//check to see if timeGiven is an acceptable time
		if ((timeGiven.size() != 5 && timeGiven.size() != 4) || (timeGiven[2] != ':' && timeGiven[1] != ':') || h1 > 1 || m1 > 5 || (h1 == 1 && h2 > 2))
		{
			cout << "Sorry, that is not a valid time.  Please try again using the (HH:MM) format.\n\n";
		}
		else
		{
			//check if lucky time
			if (luckyTime(h1, h2, m1, m2) == true)
			{
				timeType = " is a lucky time.  ";
			}
			else
			{
				timeType = " is a normal time.  ";
			}

			//check if ascending time
			if (ascendingOrder(h1, h2, m1, m2) == true)
			{
				messageType = "UP! All dreams will come true.\n";
			}
			//check if decending time
			else if (decendingOrder(h1, h2, m1, m2) == true)
			{
				messageType = "DOWN! The challenging road is ahead.\n";
			}
			//check if all the digits are the same
			else if (sameDigits(h1, h2, m1, m2) == true)
			{
				messageType = "BINGO! Go buy a lottery ticket.\n";
			}
			else
			{
				messageType = "";
			}

			//display the message to the user about what type of time they gave
			cout << timeGiven << timeType << messageType << endl;

			//see if the user wants to continue and continue if desired
			cout << "Would you like to check another time? (Y/N): ";
			cin >> choice;
			cout << endl << endl;
		}

	}


	//display author of the program
	cout << "Programmed by Brent Kinney" << endl;

	cout << "Press [Enter] key to end..."; //prompt lets user know
	cin.ignore(256, '\n');
	cin.get();

	return(0);
}