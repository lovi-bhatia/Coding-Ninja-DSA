// Copy Constructor 
// Student s2(s1);
// interpretetion inside compiler => s2.Student(s1);
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
	Student s1(10,1001);
	// cout<<"Address: "<<&s1<<endl;	
	s1.display();

	// -------------------
	// Copy Constructor
	// -------------------
	Student s2(s1);
	cout<<"s2: ";
	s2.display();

	Student *s3 = new Student(20,200);
	cout<<"s2: ";
	s3->display();

	Student *s4 = new Student(*s3);
	Student s5(*s3);
	Student *s6 = new Student(s1);



	// -------------------
	// Copy Assignment Operator
	// -------------------

	Student s8(99,839);
	Student s7(79,869);

	s7.display();
	s7 = *s6;
	s7.display();

	delete s3,s4,s6;
}