#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

void reverseStack(stack<int> &s1, stack<int> &s2) {
    int x;
    while(!s1.empty()){
        x = s1.top();
        s2.push(x);
        s1.pop();
    }
    s1 = s2;
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}