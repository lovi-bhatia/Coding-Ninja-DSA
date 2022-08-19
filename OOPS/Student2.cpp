// We can access private members within the class
class Student{
public:
	int rollNumber;

private:
	int age;

public:
	void display(){
		cout<<age<<" "<<rollNumber<<endl;
	}

	// age is private, to get age we need to create a getter function
	int returnAge(){
		return age;
	}

	// To change or set the value of age, we need to create a setter function
	void setAge(int a, int password){
		if(password!=123)
			return;
		if(a<0)
			return;
		age = a;
	}
};

// Ans:- adding constraints like age can't be negative or use password