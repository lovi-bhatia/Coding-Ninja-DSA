#include <bits/stdc++.h>

using namespace std;
#include "Student1.cpp"

int main(){
	// Create Object statically
	Student s1;
	Student s2;

	s1.age = 20;
	s1.rollNumber = 101;

	cout<<s1.age<<" "<<s1.rollNumber<<endl;

	Student s3,s4,s5;


	// Create Object Dynamically
	Student *s6 = new Student;
	(*s6).age = 23;
	(*s6).rollNumber = 201;
	cout<<(*s6).age<<" "<<(*s6).rollNumber<<endl;	


	// another way
	Student *s7 = new Student;
	s7 -> age = 25;
	s7 -> rollNumber = 301;
	cout<<s7 -> age<<" "<<s7 -> rollNumber<<endl;	

}