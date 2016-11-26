#ifndef ROSTER_H
#define ROSTER_H


#include "Student.h"

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Roster
{
private:
	int size;
	string courseName;
	string courseCode;
	int credits;
	string instructName;
#define MAX_CAPACITY  10
	Student students[MAX_CAPACITY];

public:
	Roster(string name, string code, int creds, string instuctor);
	Roster(string name, string code, int creds);
	Roster();

	void output() const; //prints to cosole course name, code, credits & instructor

	void setCourseName(const string& name); //sets the course name

	void setCode(const string& code); //sets the course code

	void setCreds(const int& creds); //sets the credits for the course

	void setInstructor(const string& instructor); //sets the instructor for the course

	string getCourseName() const; //returns course name

	string getCode() const; //returns course code

	int getCreds() const; // returns credits

	string getInstructor() const; //returns instructor name

	void addStudent();
	//will ask user for a student name and add them to the course roster

	void deleteStudent(const int& s);
	//precondition: pass the arrray position of the student you wish to remove
	//postcondition: student will be removed from the course

	void searchStudent(string f, string l) const;
	//precondition: pass the array the name of the student you are searching for
	//postcondition: will print to console if the student is added to the course

	void printStudentName() const;
	//prints to console the students names added to course

	void printStudentInfo() const;
	//prints all info of the students added to course

	void sort();

	friend ostream& operator << (ostream& output, const Roster& r);
	friend istream& operator >> (istream& input, Roster& r);


};
#endif // !ROSTER_H

