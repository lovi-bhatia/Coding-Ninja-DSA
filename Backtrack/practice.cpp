// #include <bits/stdc++.h>

// using namespace std;

// bool CanPlace(int n, int board[][20],int x, int y){
// 	for(int k=0;k<x;k++){
// 		if(board[k][y]==1){
// 			return false;
// 		}
// 	}

// 	int i = x;
// 	int j = y;

// 	// left diagonal
// 	while(i>=0 and j>=0){
// 		if(board[i][j]==1){
// 			return false;
// 		}
// 		i--;
// 		j--;
// 	}

// 	i = x;
// 	j = y;
	
// 	// right diagonal
// 	while(i>=0 && j<n){
// 		if(board[i][j]==1){
// 			return false;
// 		}
// 		i--;
// 		j++;
// 	}

// 	// if queen is not present in range 
// 	return true;	
// }

// int SolveNQueen(int n, int board[][20], int i){
	
// 	if(i==n){
// 		return 1;
// 	}

// 	int ways = 0;
// 	for(int j=0;j<n;j++){
// 		if(CanPlace(n,board,i,j)){
// 			board[i][j] = 1;
// 			ways+=SolveNQueen(n,board,i+1);
// 			board[i][j] = 0;	
// 		}

// 	}
// 	return ways;

// }

// int main(){
// 	int board[20][20] = {0};
// 	int n;
// 	cin>>n;

// 	cout<<SolveNQueen(n,board,0);
// }

