#include <bits/stdc++.h>

using namespace std;

bool CanPlace(int n, int board[][30], int x,int y){
	
	// upper row, or wrt to y-axis
	//   -
	// 	 -
	// 	 -
	// 	 q
	for(int k=0;k<x;k++){
		if(board[k][y]==1){
			return false;
		}
	}

	int i = x;
	int j = y;

	// left diagonal
	while(i>=0 and j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j--;
	}

	i = x;
	j = y;
	
	// right diagonal
	while(i>=0 && j<n){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j++;
	}

	// if queen is not present in range 
	return true;	
}

// Printing Board
void PrintBoard(int n,int board[][30]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


int SolveNQueen(int n,int board[][30],int i){
	
	int ways = 0;

	// base case
	// when board is solved
	if(i==n){
		PrintBoard(n,board);
		return 1;
	}


	// recursive case
	for(int j=0;j<n;j++){

		// if can place is true we will place queen else we increment column
		if(CanPlace(n, board, i, j)){
			
			// placing a queen
			board[i][j] = 1;
			// cout<<"place"<<i<<" "<<j<<endl;
			
			// if queen is placed we will shift to next row, we're putting queen/row
			ways += SolveNQueen(n,board,i+1);
			// if(success){
			// 	// returning true that queen is placed successfully
			// 	// PrintBoard(n,board);	
			// 	return true;
			// }

			// backtrack
			// if success is false, condition failed then we will remove queen
			board[i][j] = 0;
		}
	}
	// PrintBoard(n,board);
	// when we have checked every column and unable to place queen in that case
	// upper loop will be passed and we will return false
	return ways;

}

int main(){
	// creating a board
	
	int board[30][30] = {0};
	int n;

	// number of rows
	cin>>n;

	cout<<SolveNQueen(n,board,0);
	// PrintBoard(n,board);

	return 0;
}