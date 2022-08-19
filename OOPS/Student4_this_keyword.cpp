// this holds the address of current object
#include <bits/stdc++.h>

using namespace std;

class Student{
public:
	// Default Constructor
	// after writting constructor, inbuilt constructor will not be called 
	// Student(){
	// 	cout<<"Constructor Called"<<endl;
	// }

	int rollNumber;

private:
	int age;

public:


	// Parameterized Constructor
	Student(int rollNumber){
		// value will be added to variable which is closest to scope
		// value will be added to rollNumber passed with function i.e. to itself
		cout<<"Constructor 2 Called"<<endl;
		// Using this we will be able to add rollNumber value passed with function to Student object
		this->rollNumber = rollNumber;
	}

	Student(int a, int r){
		cout<<"this: "<<this<<endl;
		// this ka jo address aaya h, uske block me age h us, me a daal do
		this->age = a;
		// this ka jo address aaya h, uske block k rollNumber me r daal do	
		this->rollNumber = r;
	}

	void display(){
		cout<<age<<" "<<rollNumber<<endl;
	}

	// age is private, to get age we need to create a getter function
	int returnAge(){
		return age;
	}

	// To change or set the value of age, we need to create a setter function
	void setAge(int a, int password=123){
		if(password!=123)
			return;
		if(a<0)
			return;
		age = a;
	}
};

int main(){
	Student s1(10,1001);
	cout<<"Address: "<<&s1<<endl;	
}