#include <bits/stdc++.h>

using namespace std;

bool areBracketsBalanced(string expr){
    stack <char> s;
    for(int i=0;i<expr.length();i++){
        if(s.empty()){
            s.push(expr[i]);
        }
        else if((s.top() =='(' && expr[i] == ')') || (s.top() =='{' && expr[i] == '}') || (s.top() =='[' && expr[i] == ']'))
            s.pop();
        else
            s.push(expr[i]);
    }

    return s.empty();
}
int main()
{
    string expr = "{()}[][]";
 
    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}

