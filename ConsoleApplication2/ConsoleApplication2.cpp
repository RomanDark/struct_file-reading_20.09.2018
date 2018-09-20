// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*битавая фигня
struct student {
	string name;
	int m1 : 2;
	int m2 : 2;
	int m3 : 2;
	int m4 : 2;
	int m5 : 2;
	int m6 : 2;
	int m7 : 2;
	int m8 : 2;
	int m9 : 2;
	int m0 : 2;

	void enter() {
		int twar;
		cout << "enter name: ";
		cin >> name;
		
		cin >> twar;
		m1 = twar;
		cin >> twar;
		m2 = twar;
		cin >> twar;
		m3 = twar;
		cin >> twar;
		m4 = twar;
		cin >> twar;
		m5 = twar;
		cin >> twar;
		m6 = twar;
		cin >> twar;
		m7 = twar;
		cin >> twar;
		m8 = twar;
		cin >> twar;
		m9 = twar;
		cin >> twar;
		m0 = twar;
	}

	void res() {
		int sum;
		double average;

		sum = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m0;

		average =(double) sum / 10 * 100;
		cout << "Sum = " << abs(sum) << " average = " << abs(average) << "%" << endl;
	}

};

struct clothe {
	string color;
};


int main()
{
	setlocale(LC_ALL, "rus");

	student st;

	st.enter();
	st.res();




    return 0;
}*/

ifstream my_file;
int buf_size = 0, cur_size = 0;

struct Student
{
	string name;
	int m1 : 2;
	int m2 : 2;
	int m3 : 2;
	int m4 : 2;
	int m5 : 2;


	void enter()
	{
		int tvar;
		my_file >> name;
		my_file >> tvar;
		m1 = tvar;
		my_file >> tvar;
		m2 = tvar;
		my_file >> tvar;
		m3 = tvar;
		my_file >> tvar;
		m4 = tvar;
		my_file >> tvar;
		m5 = tvar;
	}
	int res() {
		int sum;
		double average;

		sum = m1 + m2 + m3 + m4 + m5;

		average = (double)sum / 5 * 100;

		return average;
	}

	void print()
	{
		cout << "Имя студента: " << name << endl;
		cout << "Оценки " << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 << endl;
	}

};

void print_d(Student *ss) {
	for (int i = 0; i < cur_size; i++)
	{
		if (ss[i].res() < 50) {
			ss[i].print();
		}
	}
}

void print_student(Student *ss) {

	string nameS;
	cin >> nameS;

	for (int i = 0; i < cur_size; i++)
	{
		if (ss[i].name == nameS) {
			ss[i].print();
			break;
		}
	}
}

void add(Student* &ss, Student s)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		ss = new Student[buf_size];
	}
	else
	{
		if (cur_size >= buf_size)
		{
			Student* tmp = new Student[buf_size * 2];
			for (int i = 0; i < buf_size; i++)
			{
				tmp[i] = ss[i];
			}
			delete[] ss;
			ss = tmp;
			buf_size *= 2;
		}
	}
	ss[cur_size++] = s;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	my_file.open("example1.txt", ios::in);
	Student s1;
	Student *ss = new Student;
	int t;
	my_file >> t;

	int nn;

	for (int i = 0; i < t; i++)
	{
		s1.enter();
		add(ss, s1);
		ss[i].print();
	}

	while (true) {

		cout << "Menu:" << endl;
		cout << "1. print student name\n2. Print dolzh\n3. print all" << endl;

		cin >> nn;
		
		switch (nn)
		{
		case 1: print_student(ss);
			break;
		case 2: print_d(ss);
			break;

		case 3: for (int i = 0; i < cur_size; i++)
		{
			ss[i].print();
		}
				break;	
		}
		
		if (nn == 0) break;
	
	}

	delete[]ss;

	//int a;
	//double b;
	//string s;

	//ifstream my_file;
	//my_file.open("int.txt", ios::in);

	////my_file  >> s;

	//getline(my_file, s);

	//cout << s;
	////cout << s;

	system("pause");
	return 0;
}

