#include <bits/stdc++.h>

using namespace std;

// 1 4 5 3 2
// pos = min_pos
// next time we will update min_pos i.e. position of minimum element
// and will swap pos and min_pos

void SelectionSort(int arr[],int n){
	
	for(int pos=0;pos<n-1;pos++){
		int current = arr[pos];
		int min_pos = pos;

		for(int j=pos;j<n-1;j++){
			if(arr[j] < arr[min_pos])
				min_pos = j;
		}

		swap(arr[min_pos],arr[pos]);
	}
}

int main(){
	int arr1[] = {-1,2,-12,43,5,-10};
	int arr[] = {10,9,8,7,6,5,4,3,1,1};
	int size = sizeof(arr1)/sizeof(int);

	SelectionSort(arr1,size);
	for(auto x: arr1)
		cout<<x<<" ";
	// cout<<"BubbleSort";
}