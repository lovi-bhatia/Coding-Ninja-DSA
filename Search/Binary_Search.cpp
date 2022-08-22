#include <bits/stdc++.h>

using namespace std;

/*
int binarySearch(int arr[],int left, int right, int element){

	if(right>=1){
		int mid = (left+right)/2;

		if(arr[mid] == element)
			return mid;

		if(arr[mid]>element)
			return binarySearch(arr,left,mid,element);

		return binarySearch(arr,mid+1,right,element);
	}
	return -1;
}

int main(){
	int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
*/

int BS(int input[], int left,int right,int element){
    
    if(left<right){
        int mid = (left+right)/2;
        
        if(input[mid] == element)
            return mid;
        
        if(input[mid]<element)
        	return BS(input,mid+1,right,element);
        return BS(input,left,mid,element);
    }
    return -1;
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
    int B = BS(input,0,size-1,element);
    cout<<B<<endl;
	return B;
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

