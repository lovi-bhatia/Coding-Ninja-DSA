// lexicographically and length

#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
	if(a.length()==b.length())
		return a<b; //lexicographically because length is same
	return a.length()<b.length();
}

void findSubsets(char *input, char *output, int i, int j, vector <string> &v){
	
	// base case
	
	// if we reach end, i.e. i = NULL and j is at right place and something in output array
	// for null input no more recursive call
	if(input[i]=='\0'){

		// printing null in order to avoid garbage getting printed
		output[j] = '\0';
		// if(output[0]=='\0')
		// 	cout<<"NULL"<<endl;
		// cout<<output<<endl;

		// making output array a string and pushing it in vector
		string temp(output);	
		v.push_back(temp);

		return;
	}

	// recursive case
	
	// including the ith letter
	output[j] = input[i];
	findSubsets(input,output,i+1,j+1,v);


	// excluding ith letter
	// overwrite
	// we will not update j th index
	// output[j] = '\0';		//optional step... null with a, b, c
	// it will overwrite on previous array as we are not updating/incrementing index of output array
	findSubsets(input,output,i+1,j,v);

}

int main(){
	char input[100];
	char output[100];
	vector <string> list;

	cin>>input;


	// in begining both index are 0
	findSubsets(input,output,0,0,list);
	
	// passing compare function to sort for comparing on basis of length and lexicographically
	sort(list.begin(),list.end(),compare);
	
	for(auto s: list){
		cout<<s<<",";
	}
}
