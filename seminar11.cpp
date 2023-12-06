#include<iostream>
#include<string>
using namespace std;
class Date {
	int day;
	int month;
	int year;

public:
	Date() : day(0), month(0), year(0) {

	}
	Date(int d, int m, int y) : day(d), month(m), year(y) {

	}
};
class Person {
	string name;
	string CNP;
	Date birthday;
	string* addresses;
	int addCount;
public:
	Person() {
		this->name = "";
		this->CNP = "";
		Date d;
		this->birthday = d;
		this->addresses = nullptr;
		this->addCount = 0;
	}
	Person(string name, string CNP, Date birthday, string* addresses, int addCount) : addCount(addCount) {
		this->name = name;
		this->CNP = CNP;
		this->birthday = birthday;
		this->addresses = new string[addCount];
		for (int i = 0; i < addCount; i++) {
			this->addresses[i] = addresses[i];
		}
	}

	//constructor de copiere, operator =, destructor
	Person(const Person& p) {
		this->name = p.name;
		this->CNP = p.CNP;
		this->birthday = p.birthday;
		this->addCount = p.addCount;
		this->addresses = new string[p.addCount];
		for (int i = 0; i < addCount; i++) {
			this->addresses[i] = p.addresses[i];
		}
	}
	Person& operator =(const Person& p) {

		if (this == &p)
			return *this;

		this->name = p.name;
		this->CNP = p.CNP;
		this->birthday = p.birthday;
		this->addCount = p.addCount;
		delete[] this->addresses;
		this->addresses = new string[p.addCount];
		for (int i = 0; i < p.addCount; i++) {
			this->addresses[i] = p.addresses[i];
		}

		return *this;
	}


	~Person() {
		delete[] addresses;
	}
};

class Student : Person{ //pt a nu mai fi nevoie de a scrie atributele care se regasesc si in clasa Person(clasa de baza)
	int regNo;
	float* grades;
	int  gradesCount;
	bool scholarship;

public:

	Student() {
		this->regNo=0;
		this->gradesCount = 0;
		this->scholarship = true;
		this->grades = nullptr;

	}
	Student(string name, string CNP, Date birthday, string* addresses, int addCount, int regNum, float* grades, int gradesCount, bool scholarship) :
		Person(name, CNP, birthday, addresses, addCount), regNo(regNo), gradesCount(gradesCount), scholarship(scholarship)
	{
		this->grades = new float[gradesCount];
		for (int i = 0; i < gradesCount; i++)
		{
			this->grades[i] = grades[i];
		}
	}

	Student(const Student& p) {
		this->regNo =p.regNo;
		this->gradesCount = p.gradesCount;
		this->scholarship = p.scholarship;
		this->grades = new float[p.gradesCount];
		for (int i = 0; i < p.gradesCount; i++)
		{
			this->grades[i] = p.grades[i];
		}

	}

	Student& operator=(Student& s) {
		if (this == &s)
			return *this;
		delete this->grades;
		this->grades = new float[s.gradesCount];
		for (int i = 0; i < s.gradesCount; i++)
		{
			this->grades[i] = s.grades[i];
		}


		return *this;
	}
	~Student() {
		delete[] grades;
	}
};

class University {

	string name = "";
	string address = "";
	Student* students = nullptr;
	int studentsCount = 0;
public:

	University(string name, string address, Student* students, int studCount)
	{
		this->name = name;
		this->address = address;
		this->studentsCount = studCount;
		this->students = new Student[studentsCount];
		for (int i = 0; i < studCount; i++)
		{
			this->students[i] = students[i];
		}
	}

	University(const University& u) {
		this->name = u.name;
		this->address = u.address;
		this->studentsCount = u.studentsCount;
		this->students = new Student[u.studentsCount];
		for (int i = 0; i < u.studentsCount; i++)
		{
			this->students[i] = u.students[i];
		}
	}
	University& operator=(University& u) {
		if (this == &u)
			return *this;
		this->name = u.name;
		this->address = u.address;
		this->studentsCount = u.studentsCount;

		delete[] students;
		this->students = new Student[u.studentsCount];
		for (int i = 0; i < u.studentsCount; i++)
		{
			this->students[i] = u.students[i];
		}
		return *this;
	}

	~University() {
		delete[] students;
	}
};
int main()
{
	Date d1;
	Date d2(5, 5, 1992);


	Person p1;
	string* addresses = new string[3];
	addresses[0] = "...Bucuresti";
	addresses[1] = "...Arad";
	addresses[2] = "...Galati";

	Person p2("Popescu Andrei", "1920505252516", d2, addresses, 3);

	Student s1;
	float* grades = new float[5];
	grades[0] = 6;
	grades[1] = 7;
	grades[2] = 8;
	grades[3] = 9;
	grades[4] = 5;

	Student s2("Popescu Andrei", "1920505252516", d2, addresses, 3, 123, grades, 5, true);
	Student s3("Andresan Andrei", "1920505252516", d2, addresses, 3, 123, grades, 5, true);

	Student* students= new Student[3];
	students[0] = s1;
	students[1] = s2;
	students[2] = s3;

	University u1("ASE", "Bucuresti", students, 3);
	
};