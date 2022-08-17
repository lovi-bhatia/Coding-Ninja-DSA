#include <bits/stdc++.h>

using namespace std;

int gridWays(int i, int j, int m, int n){
	if(i==m-1 and j==n-1){
		return 1;
	}
	if(i>=m || j>=n){
		return 0;
	}

	return (gridWays(i,j+1,m,n) + gridWays(i+1,j,m,n));
}

int main(){

	int m,n;
	cin>>m>>n;

	cout<<gridWays(0,0,m,n)<<endl;

}

// complexity :- o(2 ^(m+n))

// Math trick
// DD RR
// (m-1+n-1)!/(m-1)!(n-1)!
// complexity :- o(m+n) linear complexity