#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;


long getTimeinMicroSeconds(){
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec * 1000000 + start.tv_usec;
}

string getPossibleCharForKeypad(char c){
	if(c=='2')
		return "abc";
	if(c=='3')
		return "def";
	if(c=='4')
		return "ghi";
	if(c=='5')		
		return "jkl";
	if(c=='6')
		return "mno";
	if(c=='7')
		return "pqrs";
	if(c=='8')
		return "tuv";
	if(c=='9')
		return "wxyz";

	return "";
}

int keypad(string str, string output[]){
    // string str = to_string(num);
    if(str.length()==0){
    	output[0] = "";
    	return 1;
    }

    int smallOutputSize = keypad(str.substr(1),output);
    string firstDigPossiblechar = getPossibleCharForKeypad(str[0]);


    string temp[1000];
    int k = 0;
    
    for(int i=0;i<smallOutputSize;i++){
    	for(int j=0;j<firstDigPossiblechar.length();j++){
    		temp[k] = firstDigPossiblechar[j] + output[i];
    		k++;
    	}
    }

    for(int i=0;i<k;i++){
    	output[i] = temp[i];
    }
    return smallOutputSize*firstDigPossiblechar.length();
}

int main(){
    string num;
    cin >> num;

    long starttime, endtime;

    string output[10000];
    
    starttime = getTimeinMicroSeconds();
    int count = keypad(num, output);
    endtime = getTimeinMicroSeconds();
    
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }


    cout<<"time "<< endtime-starttime<<endl;

    return 0;
}

