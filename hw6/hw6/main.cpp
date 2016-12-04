#include "Student.h"
#include "Roster.h"


#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	Roster r1, r2;
	cout << "Let's create our first roster.\n";
	cin >> r1;
	cout << r1 << endl;
	
	r2 = r1;
	cout << "We have created a second roster equal to the first.\n";
	cout << r2 <<"Now let's add another student.\n";
	r2.addStudent();
	cout << endl;
	
	Roster r3(r2);
	cout << "We now have a third roster created by copying the second. Lets print out the second student in the thrird roster\n";
	cout << r3[1] << endl;

	cout << "Does roster one have a student named luke cage?\n";
	r1.searchStudent("luke", "cage");

	int choice;
	cout << endl << "Below are the students registered for roster 2. "
		<< "Please enter the number of the student you wish to remove\n";
	r2.printStudentName();
	cin >> choice;
	r2.deleteStudent(choice);
	cout << endl << "Below is the updated second roster\n";
	cout << r2;
	return 0;

}

