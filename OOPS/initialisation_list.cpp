// if we directly try to initialise value to const parameter, compiler will not allow it will produce error
// to overcome this we have concept called initialisation list
#include <bits/stdc++.h>

using namespace std;


class Student{

public: 
	int age;
	const int rollNumber;
	// constructor name of data member with argument we want to pass
	// this is how value will be allocated to const member
	// this way memory allocation k time rollNumber ko value allocate ho jaegi
	// Student(int r) : rollNumber(r){

	// }


	int &x; //reference variable
	// we have to initialise reference variable at time of creation
	// this can only be done with the help of list initialisation
	// here no need to write this

	// Student(int r,int age) : rollNumber(r), age(age){

	// }
	Student(int r) : rollNumber(r),x(this->age){

	}
	Student(int r,int age) : rollNumber(r),age(age),x(this->age){

	}
};

int main(){
	Student s1(231,23); 
}