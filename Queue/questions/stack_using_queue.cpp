#include <bits/stdc++.h> 
using namespace std;
class Stack {
    queue<int> q1, q2;

  public:
    Stack() {
        // Implement the Constructor.
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
          return q1.empty();
    }

    void push(int element) {
        q2.push(element);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2  = q;
    }

     int pop() {
        if(q1.empty())
            return -1;
     
        int ans = q1.front();
        q1.pop();
        return ans;
     }

     int top() {
        // Implement the top() function.
        if(q1.empty())
            return -1;
        return q1.front();
    }

};
