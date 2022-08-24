#include <bits/stdc++.h>

using namespace std;

class StackUsingArray{
	int *data;
	int nextIndex;
	int capacity;

public:
	// Creating stack with definitive size
	StackUsingArray(){
		data = new int[4];
		nextIndex = 0;
		capacity = 4;
	}

	// Size function
	int size(){
		return nextIndex;
	}

	// Empty function
	bool isEmpty(){
		return nextIndex == 0;
	}

	// Push Function
	void push(int element){
		if(nextIndex == capacity){
			// cout<<"Stack Full"<<endl;
			// return;
			int *newData = new int[2*capacity];
			for(int i=0;i<capacity;i++){
				newData[i] = data[i];
			}

			delete [] data;
			data = newData;
			capacity*=2;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	int pop(){
		if(isEmpty()){
			cout<<"Stack Empty"<<endl;
			return INT_MIN;
		}
		nextIndex--;
		return data[nextIndex];
	}
	int top(){
		if(isEmpty()){
			cout<<"Stack Empty"<<endl;
			return INT_MIN;
		}
		return data[nextIndex-1];
	}
};

int main(){
	StackUsingArray s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout<<s.top()<<endl;

	cout<<s.pop()<<endl;	
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;

	cout<<s.size()<<endl;

	cout<<s.top()<<endl;

}	