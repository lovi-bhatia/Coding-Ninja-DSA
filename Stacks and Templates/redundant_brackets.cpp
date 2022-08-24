#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

bool checkRedundantBrackets(string expression) {
    stack <char> st;

    for(auto &ch : expression){
        if(ch==')'){
            char top = st.top();
            st.pop();

            bool flag = true;

            while(!st.empty() and top!='('){

                if(top=='+' || top=='-' || top=='*' || top=='/'){
                    flag = false;
                }
                top = st.top();
                st.pop();
            }
            if(flag == true)
                return true;
        }
        else
            st.push(ch);
    }

    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}

