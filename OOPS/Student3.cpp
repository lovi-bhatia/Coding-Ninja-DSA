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
	Student(int r){
		cout<<"Constructor 2 Called"<<endl;
		rollNumber = r;
	}

	Student(int a, int r){
		cout<<"Constructor 3 Called"<<endl;
		age = a;
		rollNumber = r;
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

// Ans:- adding constraints like age can't be negative or use password