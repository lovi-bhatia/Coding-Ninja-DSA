#include <bits/stdc++.h>

using namespace std;

class Student{
public:
	

	int rollNumber;

private:
	int age;

public:

	// Default Constructor
	// after writting constructor, inbuilt constructor will not be called 
	Student(){
		cout<<"Constructor Called"<<endl;
	}

	// Parameterized Constructor
	Student(int rollNumber){
		cout<<"Constructor 2 Called"<<endl;
		this->rollNumber = rollNumber;
	}

	Student(int a, int r){
		// cout<<"this: "<<this<<endl;
		cout<<"Constructor 3 Called"<<endl;	
		this->age = a;
		this->rollNumber = r;
	}

	void display(){
		cout<<age<<" "<<rollNumber<<endl;
	}

	// --------------
	// Destructor (~)
	// --------------
	// deallocates memory
	// it will not work for dynamically created objects, we need to delete them using delete keywords

	~Student(){
		cout<<"Destructor Called"<<endl;
	}
};


int main(){
	Student s1; //Default Constructor
	Student s2(120);	//Constructor 2
	Student s3(12,230);	//Constructor 3

	Student s4(s3);		//Copy Constructor

	s1 = s2;			//Copy Assignment Operator

	// Here Copy Constructor will be called instead of copy assignment operator
	// due to optimization
	Student s5 = s4;		//Copy Constructor	
	// Student s5(s4);
}	