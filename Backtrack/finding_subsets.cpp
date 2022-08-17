#include <bits/stdc++.h>

using namespace std;

void findSubsets(char *input, char *output, int i, int j){
	
	// base case
	
	// if we reach end, i.e. i = NULL and j is at right place and something in output array
	// for null input no more recursive call
	if(input[i]=='\0'){

		// printing null in order to avoid garbage getting printed
		output[j] = '\0';
		if(output[0]=='\0')
			cout<<"NULL"<<endl;
		
		cout<<output<<endl;
		return;
	}

	// recursive case
	
	// including the ith letter
	output[j] = input[i];
	findSubsets(input,output,i+1,j+1);


		// excluding ith letter
	// overwrite
	// we will not update j th index
	// output[j] = '\0';		//optional step... null with a, b, c
	// it will overwrite on previous array as we are not updating/incrementing index of output array
	findSubsets(input,output,i+1,j);

}

int main(){
	char input[100];
	char output[100];
	cin>>input;
	// in begining both index are 0
	findSubsets(input,output,0,0);
	// cout<<output<<endl;
}


// Short
/*
int size = strlen(input);
	
    string word = "";
    for(int i=0;i<=size;i++){
        word = input[i];
    	for(int j=i+1;j<=size;j++){
            cout<<word<<endl;
            word+=input[j];
        }    
    }
*/


// CN approach
/*
int subs(string input,string output[]){
	if(input.empty()){
		output[0] = " ";
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutSize = subs(smallString,output);

	for(int i=0;i<smallOutSize;i++){
		// i+smallOusize to add after the elements already added 
		output[i+smallOutSize] = input[0] + output[i];
	}
	return 2*smallOutSize;

}

int main(){
	string input;
	cin>>input;
	string* output = new string[1000];
	int count = subs(input,output);
	for(int i=0;i<count; i++){
		cout<<output[i]<<endl;
	}

}
*/