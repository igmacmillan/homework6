#include "Student.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
Student::Student()
	: lastName(""), firstName(""), standing("Lower Freshman"), credits(0), gpa(0.0), dob("1 1, 1900"), id(12345), matriculation("1 1, 2000")
{}
Student::Student(string last, string first, int creditsValue, double gpaValue, string date, int num, string mat)
	: lastName(last), firstName(first), credits(creditsValue), gpa(gpaValue), dob(date), id(num), matriculation(mat)
{
	setStanding();
}
void Student::input()
{
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << "Enter your DOB: ";
	cin >> dob;
	cout << "Enter your student ID number: ";
	cin >> id;
	cout << "Enter your matriculation date: ";
	cin >> matriculation;
	cout << "Enter the number of credits do you have: ";
	cin >> credits;
	cout << "Enter your GPA: ";
	cin >> gpa;
	setStanding();

	cout << endl;
}
void Student::output() const
{
	cout << "Name: " << firstName << " " << lastName << endl
		<< "Credits: " << credits << endl
		<< "GPA: " << gpa << endl
		<< "Standing: " << standing << endl
		<< "DOB: " << dob << endl
		<< "ID #: " << id << endl
		<< "Matriculation date: " << matriculation << endl;
}
void Student::setCredits()
{
	cout << "Enter your update number of credits: ";
	cin >> credits;
	cout << endl;
	setStanding();
}
void Student::setName()
{
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << endl;
}
void Student::setFirstName()
{
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << endl;
}
void Student::setLastName()
{
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << endl;
}
void Student::setGPA()
{
	cout << "Enter your updated GPA: ";
	cin >> gpa;
	cout << endl;
}
void Student::setDOB()
{
	cout << "Enter your DOB: ";
	cin >> dob;
	cout << endl;
}

void Student::setMatric()
{
	cout << "Enter your matriculation date: ";
	cin >> matriculation;
	cout << endl;
}

void Student::set()
{
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << "Enter your DOB: ";
	cin >> dob;
	cout << "Enter your student ID: ";
	cin >> id;
	cout << "Enter your matriculation date: ";
	cin >> matriculation;
	cout << "Enter number of credits: ";
	cin >> credits;
	cout << "Enter your GPA: ";
	cin >> gpa;
	cout << endl;
	setStanding();
}
void Student::setID()
{
	cout << "Enter your Student ID #: ";
	cin >> id;
	cout << endl;
}
string Student::getName() const
{
	return firstName + " " + lastName;
}
string Student::getFirstName() const
{
	return firstName;
}
string Student::getLastName() const
{
	return lastName;
}
int Student::getCredits() const
{
	return credits;
}
double Student::getGPA() const
{
	return gpa;
}
string Student::getDOB() const
{
	return dob;
}

string Student::getMatric() const
{
	return matriculation;
}

string Student::getStanding() const
{
	return standing;
}
int Student::getID() const
{
	return id;
}
void Student::setStanding()
{
	if (credits <= 15)
		standing = "Lower Freshman";
	else if (credits <= 30)
		standing = "Upper Freshman";
	else if (credits <= 45)
		standing = "Lower Sophmore";
	else if (credits <= 60)
		standing = "Upper Sophmore";
	else if (credits <= 75)
		standing = "Lower Junior";
	else if (credits <= 90)
		standing = "Upper Junior";
	else if (credits <= 105)
		standing = "Lower Senior";
	else
		standing = "Upper Senior";
}
void Student::removeStudent()
{
	firstName = "";
	lastName = "";
	gpa = 0.0;
	credits = 0;
	dob = "";
	matriculation = "";
}
bool Student::operator == (const Student& secondStudent) const
{
	return (lastName == secondStudent.lastName && firstName == secondStudent.firstName && id == secondStudent.id);
}
bool Student::operator != (const Student& secondStudent) const
{
	return (lastName != secondStudent.lastName || firstName != secondStudent.firstName || id != secondStudent.id);
}
bool Student::operator < (const Student& secondStudent) const
{
	return ((lastName < secondStudent.lastName)
		|| (lastName == secondStudent.lastName && firstName < secondStudent.firstName)
		|| (lastName == secondStudent.lastName && firstName == secondStudent.firstName && id < secondStudent.id));
}
bool Student::operator > (const Student& secondStudent) const
{
	return ((lastName > secondStudent.lastName)
		|| (lastName == secondStudent.lastName && firstName > secondStudent.firstName)
		|| (lastName == secondStudent.lastName && firstName == secondStudent.firstName && id > secondStudent.id));
}
bool Student::operator <= (const Student& secondStudent) const
{
	return ((lastName <= secondStudent.lastName)
		|| (lastName == secondStudent.lastName && firstName <= secondStudent.firstName)
		|| (lastName == secondStudent.lastName && firstName == secondStudent.firstName && id <= secondStudent.id));
}
bool Student::operator >= (const Student& secondStudent) const
{
	return ((lastName >= secondStudent.lastName)
		|| (lastName == secondStudent.lastName && firstName >= secondStudent.firstName)
		|| (lastName == secondStudent.lastName && firstName == secondStudent.firstName && id >= secondStudent.id));
}
ostream& operator << (ostream& output, const Student& s)
{
	output << "First Name: " << s.firstName << endl
		<< "Last Name: " << s.lastName << endl
		<< "DOB: " << s.dob << endl
		<< "Student ID: " << s.id << endl
		<< "Matriculation date: " << s.matriculation << endl
		<< "Credits: " << s.credits << endl
		<< "GPA: " << s.gpa << endl
		<< "Standing: " << s.standing << endl;
	return output;
}
istream& operator >> (istream& input, Student& s)
{
	cout << "Enter first name: ";
	input >> s.firstName;
	cout << "Enter last name: ";
	input >> s.lastName;
	cout << "Enter DOB: ";
	input >> s.dob;
	cout << "Enter student ID: ";
	input >> s.id;
	cout << "Enter matriculation date: ";
	input >> s.matriculation;
	cout << "Enter number of credits: ";
	input >> s.credits;
	cout << "Enter GPA: ";
	input >> s.gpa;
	cout << endl;
	return input;
}

