#include <bits/stdc++.h>

using namespace std;

set<vector<int>> s;

void findSubsets(vector <int> &input, vector <int> output, int i){
	if(i==input.size()){
		sort(output.begin(),output.end());
		s.insert(output);
		return;
	}

	output.push_back(input[i]);
	findSubsets(input,output,i+1);
	output.pop_back();
	findSubsets(input,output,i+1);
}

void Print_Vector(vector<int> Vec)
{
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
	vector <int> in,out;

	for(int i=0;i<3;i++){
		int e;
		cin>>e;
		in.push_back(e);
	}

	findSubsets(in,out,0);
	// cout<<"s"<<n.size();
	for(auto it = s.begin();it!=s.end();it++){
		Print_Vector(*it);
	}
}


