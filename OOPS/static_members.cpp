// Static functions don't have this access
// Static functions can only access static data memebers, they can't have access to non-static data members
#include <bits/stdc++.h>

using namespace std;


class Student{
private:

	static int totalStudents;
public: 
	int age;
	int rollNumber;


	Student(){
		totalStudents++;
	}

	static int getTotalStudents(){
		return totalStudents;
	}
};

int Student :: totalStudents = 0;

int main(){
	Student s1;
	// cout<<s1.rollNumber<<" "<<s1.age<<endl;
	// cout<<s1.totalStudents<<endl;

	// s1.totalStudents = 20;

	Student s2;
	// cout<<s2.totalStudents<<endl;
	// error
	// cout<<Student::totalStudents<<endl;

	cout << Student::getTotalStudents << endl;
}