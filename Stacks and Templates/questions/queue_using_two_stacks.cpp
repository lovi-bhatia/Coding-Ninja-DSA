#include <bits/stdc++.h>

using namespace std;


class Queue{
    // Stacks to be used in the operations.
    
    stack<int> s1, s2;

    public:
    // Enqueues 'X' into the queue. Returns true after enqueuing.
     bool enqueue(int X){
        s1.push(X);
        return true;
     }
   /*
      Dequeues top element from queue. Returns -1 if the queue is empty, 
      otherwise returns the popped element.
    */
     int dequeue(){

        if(s1.empty() && s2.empty())
            return -1;

        if(s2.empty()){
            while(!s1.empty()){
               s2.push(s1.top());
               s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x; 
     }


};