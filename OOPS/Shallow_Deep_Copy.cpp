#include <bits/stdc++.h>

using namespace std;

class Student{
	int age;
	char *name;
public:
	Student(int age, char *name){
		this->age = age;
		// shallow copy
		// only address is passed
		// this->name = name;

		//Deep copy
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
	}	

	void display(){
		cout<<name<<" "<<age<<endl;
	}
};

int main(){
	char name[] = "lovi";
	Student s1(20,name);
	s1.display();

	name[3] = 'e';
	Student s2(21,name);
	s2.display();

	s1.display();

	// because of address array is passed both s1 and s2 have same array, if we change anything in name
	// array, change will reflect in both Student objects

}