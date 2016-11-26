#include "Student.h"
#include "Roster.h"


#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	//student test
	cout << "Let's test the student insertion and extraction overload\n";
	Student s;
	cin >> s;
	cout << s;

	//roster test
	cout << "For my next trick we will do the same for rosters\n";
	Roster r1;
	cin >> r1;
	cout << r1;
	r1.sort();
	cout << endl << "Below you will find the course info with the roster sorted by last name, then first name and finally by student ID\n";
	cout << r1;
	cout << "Tada!\n";


	/*date overload test
	cout << "Finally the overloads for Date\n";
	Date d1;
	cin >> d1;
	cout << d1;
	*/

	return 0;

}

