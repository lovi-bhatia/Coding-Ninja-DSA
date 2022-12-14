#include <vector>
#include <iostream>

using namespace std;

class Heap{
    vector<int> v;

    public:
        Heap(int default_size = 10){
            // because we are keeping 0th index empty for sake of simplicity
            v.reserve(default_size+1);
            v.push_back(-1);
        }

        void push(int data){
            v.push_back(data);

            int idx = v.size()-1;
            int parent = idx/2;

            while(idx>1 && v[idx]<v[parent]){
                swap(v[idx],v[parent]);
                idx = parent;
                parent = parent/2;
            }
        }
};