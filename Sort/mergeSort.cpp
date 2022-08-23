#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e){
    int i = s;
    int mid = (s+e)/2;
    int j = mid+1;
    
    vector <int> temp;
    
    while(i<=mid&&j<=e){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        	// i++;
        }
        else{
            temp.push_back(arr[j++]);
        	// j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    
    while(j<=e){
        temp.push_back(arr[j++]);
    }
    
    int idx = 0;
    for(int k =s;k<=e;k++){
        arr[k] = temp[idx++];
    }
}

void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,0,e);
}

// void mergeSort(int input[], int size){
// 	// Write your code here
// 	MergeSort(input,0,size-1);
// }

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, 0,length-1);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}