#include <bits/stdc++.h> 
using namespace std;

void recq(queue<int>&q){
    if(q.empty())
        return;
    int front = q.front();
    q.pop();
    recq(q);
    q.push(front);
}

queue<int> reverseQueue(queue<int> q)
{
    recq(q);
    return q;
}
