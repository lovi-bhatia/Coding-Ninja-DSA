#include <bits/stdc++.h> 
using namespace std;

void recq(queue<int>&q, int k){
    if(q.empty()||k>q.size())
        return;
    if(k<=0)
        return;

        stack<int>s;

        for(int i=0;i<k;i++){
            s.push(q.front());
            q.pop();
        }

        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }

        for(int i=0;i<q.size()-k;i++){
            q.push(q.front());
            q.pop();
        }
}
queue<int> reverseElements(queue<int> q, int k)
{
    recq(q,k);
    return q;
}