#include <bits/stdc++.h> 
using namespace std;

void helper(stack<int>&s, int count, int size){
    if(count == size/2){
        s.pop();
        return;
    }
    int top = s.top();
    s.pop();
    helper(s,count+1,size);
}
void deleteMiddle(stack<int>&inputStack, int N){
    helper(inputStack,0,N);
}