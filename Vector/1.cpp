// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

int main(){
//     vector<int>* vp = new vector<int>();
     vector <int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    v[1] = 100;
//    vectors can be treated as array as well
//    cout<<v[0]<<endl;
//    cout<<v[1]<<endl;
    
//    we don't add elements with v[4] like this, because push_back() checks whether vector is full and to be resized or not
//    if current capacity is less in vector then we add element with v[5] may add to random location which is not of array
    
    v[3] = 1002;
    v[4] = 4000;
    v.push_back(40);
    v.push_back(50);
//    here according to vector last element is v[2]
    for(auto &e: v){
        cout<<e<<endl;
    }
//    garbage value
    cout<<v[5]<<endl;
    
    
// vector size
    cout<<"size: "<<v.size()<<endl;
    
//we will use [] to get and for updates
//    at function to get element at particular index
    cout<<v.at(2)<<endl;
    
//    it will throw an error
//    cout<<v.at(5)<<endl;
    
//    delete last element
    v.pop_back();
    
    
    vector <int> vp;
    vp.push_back(10);
    int i=0;
    for(i=0; i<100; i++){
//        vp.push_back(i+1);
        v.push_back(i);
        
        cout<<"capacity: "<<v.capacity()<<endl;
        cout<<"size: "<<v.size()<<endl;
    }
//    cout<<v2.size()<<endl;
}
