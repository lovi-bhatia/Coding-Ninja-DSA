#include <bits/stdc++.h>

using namespace std;
#include "Student3.cpp"

int main(){
	// Create Object statically
	Student s1;
	
	s1.setAge(20);
	s1.rollNumber = 101;
	s1.display();

	Student *s7 = new Student;
	s7 -> setAge(21);
	s7 -> rollNumber = 301;
	cout<<s7 -> returnAge()<<" "<<s7 -> rollNumber<<endl;	
	s7 -> display();

	// Parameterized Constructor
	cout<<"Parameterized Constructor"<<endl;
	Student s2(10);
	s2.setAge(23);
	s2.display();

	// Dynamic
	Student *s8 = new Student(310);
	s8->setAge(31);
	s8->display();

	Student *s9 = new Student(30,410);
	s9->display();
}

// Why do we created property private when we can get the using public functions?