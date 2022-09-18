#include <bits/stdc++.h>

using namespace std;

void PrintDes(int n){
	if(n<0)
		return;
	cout<<n<<" ";
	PrintDes(n-1);
	// going towards base case
	// printing is done before calling again
}

void PrintAsc(int i, int n){
	if(i>n)
		return;
	cout<<i<<" ";
	PrintAsc(++i,n);
}

void Inc(int n){
	if(n<0)
		return;
	Inc(n-1);
	cout<<n<<" ";
	// going towards base case
	// printing is done after execution of recursion
}

int main(){
	PrintDes(5);
	cout<<endl;
	PrintAsc(0,5);
	cout<<endl;
	Inc(5);
}