#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <climits>
using namespace std;


class dynamicArray{
    int *data;
    int nextIndex;
    int capacity;
    
public:
    dynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    
//    Copy consturctor
//    shallow copy
//    dynamicArray(dynamicArray const &d1){
//        this->data = d1.data;
//        this->nextIndex = d1.nextIndex;
//        this->capacity = d1.capacity;
//    }
    
//    deep copy
    dynamicArray(dynamicArray const &d1){
        this->data = new int[d1.capacity];
        for(int i=0;i<d1.nextIndex;i++){
            this->data[i] = d1.data[i];
        }
                this->nextIndex = d1.nextIndex;
                this->capacity = d1.capacity;
    }
    
    
//    copy assignment operator
    void operator=(dynamicArray const &d1){
            this->data = new int[d1.capacity];
            for(int i=0;i<d1.nextIndex;i++){
                this->data[i] = d1.data[i];
            }
                    this->nextIndex = d1.nextIndex;
                    this->capacity = d1.capacity;
    }
    
    void add(int element){
//        we will double the capacity when initial array becomes full
        if(nextIndex==capacity){
            int *newData = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            capacity*=2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    
    void add(int i,int element){
        if(i<nextIndex)
            data[i]=element;
        if(i==nextIndex)
            add(element);
        else
            return;
    }
    
    const int get(int i){
        if(i<nextIndex){
            return  data[i];
        }
        else
            return  INT_MIN;
    }
    
    const void print(){
        for(int i=0;i<nextIndex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    dynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    
    d1.print();
    
//    shallow copy
    dynamicArray d2(d1);
    d1.add(2,100);
    d2.print();
    
//    shallow copy assignment operator
    dynamicArray d3;
    d3 = d1;
    d3.add(3,300);
    d3.print();
}
