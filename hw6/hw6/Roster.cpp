#include "Roster.h"
#include "Student.h"

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;


Roster::Roster(string name, string code, int creds, string instuctor)
	: courseName(name), courseCode(code), credits(creds), instructName(instuctor)
{
	size = 0;
}

Roster::Roster(string name, string code, int creds)
	: courseName(name), courseCode(code), credits(creds)
{
	size = 0;
}

Roster::Roster()
{
	size = 0;
}

void Roster::output() const
{
	cout << "Course Name: " << courseName << endl
		<< "Course Code: " << courseCode << endl
		<< "Course Credits: " << credits << endl
		<< "Instructor Name: " << instructName << endl;
	if (size > 0)
		printStudentName();
}

void Roster::setCourseName(const string& name)
{
	courseName = name;
}

void Roster::setCode(const string& code)
{
	courseCode = code;
}

void Roster::setCreds(const int& creds)
{
	credits = creds;
}

void Roster::setInstructor(const string& instructor)
{
	instructName = instructor;
}

string Roster::getCourseName() const
{
	return courseName;
}

string Roster::getCode() const
{
	return courseCode;
}

int Roster::getCreds() const
{
	return credits;
}

string Roster::getInstructor() const
{
	return instructName;
}


void Roster::addStudent()
{

	students[size].setName();
	students[size].setID();
	size++;
}

void Roster::printStudentName() const
{
	int count = 1;
	cout << "The following are the students registered for this course:\n";
	for (int i = 0; i < size; i++)
	{
		cout << count << " - " << students[i].getName() << endl;
		count++;
	}
	cout << endl;
}

void Roster::printStudentInfo() const
{
	int count = 1;
	cout << "The following are the students registered for this course:\n";
	for (int i = 0; i < size; i++)
	{
		cout << count << " - ";
		students[i].output();
		cout << endl;

		count++;
	}
	cout << endl;
}

void Roster::deleteStudent(const int& s)
{
	students[s].removeStudent();

}


void Roster::searchStudent(string f, string l) const
{
	int found = 1;
	for (int i = 0; i < size; i++)
	{

		if (f == students[i].getFirstName() && l == students[i].getLastName())
		{
			cout << "Yes, that student is registered for this course.\n";
			found = 0;
		}
	}
	if (found)
	{
		cout << "No, the student is not registered for this course.\n";
	}
}

void Roster::sort()
{
	Student temp;
	int min;

	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (students[j] < students[min])
				min = j;
		}

		if (min != i)
		{
			temp = students[i];
			students[i] = students[min];
			students[min] = temp;
		}
	}
}

ostream& operator << (ostream& output, const Roster& r)
{
	output << "Course Name: " << r.courseName << endl
		<< "Course Code: " << r.courseCode << endl
		<< "Course Credits: " << r.credits << endl
		<< "Instructor Name: " << r.instructName << endl;
	if (r.size > 0)
		r.printStudentName();

	return output;
}
istream& operator >> (istream& input, Roster& r)
{
	cout << "Enter a course name: ";
	input >> r.courseName;
	cout << "Enter a course code: ";
	input >> r.courseCode;
	cout << "Enter the number of credits for the course: ";
	input >> r.credits;
	cout << "Enter the instructor's name: ";
	input >> r.instructName;
	cout << endl;

	string add;
	cout << "Would you like to add a student to the roster?\n";
	cin >> add;
	while (add == "yes" || add == "Yes")
	{
		r.addStudent();
		cout << "Would you like to add another student?\n";
		cin >> add;
	}
	return input;
}





