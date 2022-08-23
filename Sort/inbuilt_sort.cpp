#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b){

	cout<<"comapring"<<a<<" and "<<b<<endl;
	// return a>b;	//ascending
	return b>a;		//descending
}

int main(){
	int arr[] = {-1,2,-12,43,5,-10};
	int arr1[] = {10,9,8,7,6,5,4,3,1,1};
	int size = sizeof(arr)/sizeof(int);

	// we are passing a function as parameter to another function
	sort(arr,arr+size,compare);
	// inbuilt function to sort in descending order
	sort(arr,arr+size,greater<int>());
	for(auto x: arr)
		cout<<x<<" ";
}



// Time complexity o(nlogn)
