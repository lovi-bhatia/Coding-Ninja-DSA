#include <bits/stdc++.h>

using namespace std;

template <typename T>
class StackUsingArray{
	T *data;
	int nextIndex;
	int capacity;

public:
	// Creating stack with definitive size
	StackUsingArray(){
		data = new T[4];
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
	void push(T element){
		if(nextIndex == capacity){
			// cout<<"Stack Full"<<endl;
			// return;
			T *newData = new T[2*capacity];
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

	T pop(){
		if(isEmpty()){
			cout<<"Stack Empty"<<endl;
			return 0;
		}
		nextIndex--;
		return data[nextIndex];
	}
	T top(){
		if(isEmpty()){
			cout<<"Stack Empty"<<endl;
			return 0;
		}
		return data[nextIndex-1];
	}
};

int main(){
	StackUsingArray<char> s;
	s.push(100);
	s.push(210);
	s.push(130);
	s.push(240);
	s.push(150);

	cout<<s.top()<<endl;

	cout<<s.pop()<<endl;	
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;

	cout<<s.size()<<endl;

	cout<<s.top()<<endl;

}	