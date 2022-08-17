#include <bits/stdc++.h>

using namespace std;

int Subset(int input[], int n, int output[][20], int i){
  if(n<=0){
        output[0][0] = 0;
        return 1;
    }
    int smallSub = Subset(input+1,n-1,output,i++);
    // output[i+smallSub][0] = input[0]; 
    // cout<<output[i+smallSub][0]<<endl;
    for(int i=0;i<smallSub;i++){
        int col = output[i][0] + 1;
        output[i+smallSub][0] = col;
        // cout<<"col "<<col<<endl;
        output[i+smallSub][1] = input[0];
        for(int j=2;j<=col;j++){
            output[i+smallSub][j] = output[i][j-1];            
        }
    }
    return 2*smallSub;
}

int subset(int input[], int n, int output[][20]) {
  return Subset(input,n,output,0);
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);
  // cout<<"size ="<<size<<endl;

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
