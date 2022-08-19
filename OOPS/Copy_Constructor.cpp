#include <bits/stdc++.h>

using namespace std;

class Student{
public:
	int age;
	char *name;

	Student(int age, char *name){
		this->age = age;
		// shallow copy
		// only address is passed
		// this->name = name;

		//Deep copy
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
	}	

	// Copy Constructor
	// const to avoid changes in s
	Student (Student const &s){
		this->age = s.age;
		// this->name = s.name; //shallow copy
		this->name = new char[strlen(s.name)+1];
		strcpy(this->name,s.name);
	}

	void display(){
		cout<<name<<" "<<age<<endl;
	}
};

int main(){
	char name[] = "lovi";
	Student s1(20,name);
	s1.display();

	// Copy constructor do shallow copy, i.e. pass address of array
	Student s2(s1);
	s2.name[0] = 'i';
	s1.display();
	s2.display();



}