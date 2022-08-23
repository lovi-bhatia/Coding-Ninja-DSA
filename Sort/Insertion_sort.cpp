#include <bits/stdc++.h>

using namespace std;

void InsertionSort(int arr[],int n){
	for(int i=1;i<n;i++){
		int current = arr[i];

		int prev = i-1;

		// loop to find right index where the element is to be inserted
		while(prev>=0 and arr[prev]>current){
			arr[prev+1] = arr[prev];
			prev--;
		}
		arr[prev+1] = current;
		// prev+1 because loop will end with prev i.e. previous index where element is to be added
		// like if element to be added at index 2 it will return index 1
	}
}


int main(){
	int arr[] = {-1,2,-12,43,5,-10};
	int arr1[] = {10,9,8,7,6,5,4,3,1,1};
	int size = sizeof(arr)/sizeof(int);

	InsertionSort(arr,size);
	for(auto x: arr)
		cout<<x<<" ";
	// cout<<"BubbleSort";
}