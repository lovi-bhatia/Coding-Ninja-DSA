#include <bits/stdc++.h> 
using namespace std;

void generateParenthesis(int left, int right, string& s, vector<string>& ans){
    if(left==0 && right == 0)
        ans.push_back(s);
    
            if (left > right || left < 0 || right < 0) {
            // wrong
            return;
        }
 
        s.push_back('(');
        generateParenthesis(left - 1, right, s, ans);
        s.pop_back();
 
        s.push_back(')');
        generateParenthesis(left, right - 1, s, ans);
        s.pop_back();
}
vector<string> balancedParantheses(int n)
{
    // Write Your Code here.
    string s;
    vector<string> ans;
    generateParenthesis(n,n,s,ans);
    return ans;
}

