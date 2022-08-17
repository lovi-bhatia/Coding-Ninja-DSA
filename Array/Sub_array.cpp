#include <bits/stdc++.h>

using namespace std;

int Subarrays(int arr[],int n){
	int largestSum = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum = 0;
			for(int k=i;k<=j;k++){
				// cout<<arr[k]<<" ";
				sum += arr[k];
			}
			// cout<<endl;
			// cout<<sum<<endl;
			// cout<<endl;
			largestSum = max(largestSum,sum);
		}
	}
	return largestSum;
}

int PrefixSum(int arr[],int n){
	int Prefix[n] = {0};
	Prefix[0] = arr[0];

	// to avoid segmentation fault loop is started from 1
	for(int i=1;i<n;i++){
		Prefix[i] = Prefix[i-1] + arr[i]; 
	}

	// 1 2 3 4 5 6 7 8
	// i        j
	// to get element between i and j, we subtract prefix[j] - prefix[i-1]

	int largestSum = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int subArraySum = i>0 ? Prefix[j] - Prefix[i] : Prefix[j];
			largestSum = max(largestSum,subArraySum);
		}
	}
	return largestSum;
}

int main(){
	// int arr[] = {-2,3,4,-1,5,-12,6,1,3};
	int arr[] = {1,-2,3,4,4-2};
	int n = sizeof(arr)/sizeof(int);
	cout<<Subarrays(arr,n);
}