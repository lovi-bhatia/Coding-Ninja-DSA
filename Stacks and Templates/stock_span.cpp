#include <bits/stdc++.h>
using namespace std;


int* stockSpan(int *price, int size)  {
    stack <int>st;

    int *output = new int[size];

    // in stack we are storing the index of price
    // later we will subtract index of upper price to present price
    st.push(0);

    output[0] = 1;

    for(int i=1;i<size;i++){
        while(!st.empty() && price[st.top()]<price[i]){
            st.pop();
        }
        if(st.empty()){
            output[i] = i+1;
        }
        else{
            output[i] = i-st.top();
        }
        st.push(i);
    }
    return output;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}