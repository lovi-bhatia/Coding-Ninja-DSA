#include <bits/stdc++.h>

using namespace std;

void BubbleSort(int arr[],int n){
	for(int i=0;i<n-1;i++){

		bool swapped = false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){

				swap(arr[j],arr[j+1]);
				swapped = true;
			
			}
		}
		if(!swapped)
		break;
	}
}

int main(){
	int arr[] = {-1,2,-12,43,5,-10};
	int arr1[] = {10,9,8,7,6,5,4,3,1,1};
	int size = sizeof(arr1)/sizeof(int);

	BubbleSort(arr1,size);
	for(auto x: arr1) 
		cout<<x<<" ";
	// cout<<"BubbleSort";
}


// We added swapped condition, if in a whole loop any element is not swapped that means array is sorted, so we will break loop
