#include "Roster.h"
#include "Student.h"

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;


Roster::Roster(string name, string code, int creds, string instuctor)
	: courseName(name), courseCode(code), credits(creds), instructName(instuctor), size(0), capacity(10)
{
	students = new Student*[capacity];
}

Roster::Roster(string name, string code, int creds)
	: courseName(name), courseCode(code), credits(creds), instructName("TBD"), size(0), capacity(10)
{
	students = new Student*[capacity];
}

Roster::Roster() 
	: courseName("TBD"), courseCode("TBD"), credits(0), instructName("TBD"), size(0), capacity(10)
{
	students = new Student*[capacity];
}

Roster::Roster(const Roster& other)
	:size(other.size), capacity(other.capacity), courseName(other.courseName), courseCode(other.courseCode),credits(other.credits),
	instructName(other.instructName)
{
	students = new Student*[capacity];
	for (int i = 0; i < size; i++)
	{
		students[i] = new Student(*(other.students[i]));
		//students[i] = new Student;
		//*students[i] = *other.students[i];

	}
}

Roster::~Roster()
{
	for (int i = 0; i < size; i++)
	{
		delete students[i];
	}

	delete[] students;
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

int Roster::getSize() const
{
	return size;
}

void Roster::addStudent()
{
	if (size == capacity)
		grow();
	students[size] = new Student;
	students[size]->setName();
	students[size]->setID();
	size++;
}

void Roster::printStudentName() const
{
	int count = 1;
	cout << "The following are the students registered for this course:\n";
	for (int i = 0; i < size; i++)
	{
		cout << count << " - " << students[i]->getName() << endl;
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
		students[i]->output();
		cout << endl;

		count++;
	}
	cout << endl;
}

void Roster::deleteStudent(int s)
{
	delete students[s - 1];
	students[s-1] = students[size - 1];
	students[size - 1] = NULL;
	size--;
}


void Roster::searchStudent(string f, string l) const
{
	int found = 1;
	for (int i = 0; i < size; i++)
	{

		if (f == students[i]->getFirstName() && l == students[i]->getLastName())
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
	Student* temp = new Student;
	int min;

	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (*(students[j]) < *(students[min]))
				min = j;
		}

		if (min != i)
		{
			temp = students[i];
			students[i] = students[min];
			students[min] = temp;
		}
	}
	delete temp;
}

void Roster::grow()
{
	capacity = capacity + 10;
	Student** s = new Student*[capacity];
	for (int i = 0; i < size; i++)
	{
		s[i] = students[i];
	}
	delete[] students;
	students = s;

}

Roster& Roster::operator = (const Roster& other)
{
	if (this == &other)
		return *this;
	else
	{
		for (int i = 0; i < size; i++)
		{
			delete students[i];
		}
		delete[] students;
		size = other.size;
		capacity = other.capacity;
		courseName = other.courseName;;
		courseCode = other.courseCode;
		credits = other.credits;
		instructName = other. instructName;
			
		students = new Student*[capacity];
		for (int i = 0; i < size; i++)
		{
			students[i] = new Student(*(other.students[i]));
		}
		return *this;
	}
}

const Student& Roster::operator [] (int index)
{
	return *students[index];
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





