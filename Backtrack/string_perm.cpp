#include <bits/stdc++.h>

using namespace std;

int i=0;

void perm(string input,int l, int r, string output[]){
    if(l==r){
        output[i++] = input;
    }
    
    for(int j=l;j<=r;j++){
        swap(input[l], input[j]);

        perm(input,l+1,r,output);

        swap(input[l], input[j]);
    }
}

int returnPermutations(string input, string output[]){

    perm(input,0,input.size()-1,output);
    return i;
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    // cout<<"hello"<<endl;
    return 0;
}

// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;


// void permute(string a, int l, int r)
// {
//     // Base case
//     if (l == r)
//         cout<<a<<endl;
//     else
//     {
//         // Permutations made
//         for (int i = l; i <= r; i++)
//         {

//             // Swapping done
//             swap(a[l], a[i]);

//             // Recursion called
//             permute(a, l+1, r);

//             //backtrack
//             swap(a[l], a[i]);
//         }
//     }
// }

// // Driver Code
// int main()
// {
//     string str = "ABC";
//     int n = str.size();
//     permute(str, 0, n-1);
//     return 0;
// }

// // This is code is contributed by rathbhupendra

