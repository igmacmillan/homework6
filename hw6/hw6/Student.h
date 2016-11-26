#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	Student();
	Student(string last, string first, int creditsValue, double gpaValue, string date, int id, string mat);
	void input();
	void output() const;
	void set();
	void setCredits();
	void setName();
	void setFirstName();
	void setLastName();
	void setGPA();
	void setDOB();
	void setMatric();
	void setID();

	string getName() const;
	string getFirstName() const;
	string getLastName() const;
	int getCredits() const;
	double getGPA() const;
	string getDOB() const;
	string getMatric() const;
	string getStanding() const;
	int getID() const;
	void setStanding();
	void removeStudent();
	bool operator == (const Student& secondStudent) const;
	bool operator != (const Student& secondStudent) const;
	bool operator < (const Student& secondStudent) const;
	bool operator > (const Student& secondStudent) const;
	bool operator <= (const Student& secondStudent) const;
	bool operator >= (const Student& secondStudent) const;
	friend ostream& operator << (ostream& output, const Student& s);
	friend istream& operator >> (istream& output, Student& s);
private:
	string lastName;
	string firstName;
	string standing;
	int credits;
	double gpa;
	string dob;
	string matriculation;
	int id;
};
#endif

