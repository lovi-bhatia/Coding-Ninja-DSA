#include <bits/stdc++.h>

using namespace std;

void sortInsert(stack<int> &s, int key){

    // base case
    // if stack is empty or key is greater than elements in stack
    if(s.empty()||key>s.top()){
        s.push(key);
        return;
    }

    // if key is not greater than top element
    int top = s.top();
    s.pop();

    // recuring on remaining elements (checking with other elements )
    sortInsert(s,top);

    // putting back top element
    s.push(top);
}

stack<int> sortStack(stack<int> &s)
{
    // base case
    // if stack is empty
    if(s.empty())
        return s;

    // if stack is not empty

    // picking top element from stack
    int top = s.top();
    s.pop();

    // recuring on remaining stack
    sortStack(s);

    // sorting remaining elements of stack
    sortInsert(s,top);

    // returning sorted stack
    return s;
}