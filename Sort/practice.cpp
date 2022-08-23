#include<bits/stdc++.h>
using namespace std;
  
// // Driver function to sort the vector elements
// // by second element of pairs
// bool sortbysec(const pair<int,int> &a,
//               const pair<int,int> &b)
// {
//     if(a.first == b.first)
//         return (a.second < b.second);
//     return (a.first<b.first);
// }
  
// int main()
// {
//     // declaring vector of pairs
//     vector< pair <int, int> > vect;
  
//     // Initialising 1st and 2nd element of pairs
//     // with array values
//     int arr[] = {10, 20, 5, 5 };
//     int arr1[] = {30, 60, 20, 50};
//     int n = sizeof(arr)/sizeof(arr[0]);
  
//     // Entering values in vector of pairs
//     for (int i=0; i<n; i++)
//         vect.push_back( make_pair(arr[i],arr1[i]) );
  
//     // Printing the original vector(before sort())
//     cout << "The vector before sort operation is:\n" ;
//     for (int i=0; i<n; i++)
//     {
//         // "first" and "second" are used to access
//         // 1st and 2nd element of pair respectively
//         cout << vect[i].first << " "
//              << vect[i].second << endl;
  
//     }
  
//     // Using sort() function to sort by 2nd element
//     // of pair
//     sort(vect.begin(), vect.end(), sortbysec);
  
//     // Printing the sorted vector(after using sort())
//     cout << "The vector after sort operation is:\n" ;
//     for (int i=0; i<n; i++)
//     {
//         // "first" and "second" are used to access
//         // 1st and 2nd element of pair respectively
//         cout << vect[i].first << " "
//              << vect[i].second << endl;
//     }
//     return 0;
// }

// 1
// 23
// 345
// 4567

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int a=1,b;
        if(y%x==0)
            cout<<a<<" "<<y/x<<endl;
        else
            cout<<0<<" "<<0<<endl;
    }
}


// . . . . . 
// . . + . .
// . . . . .
// . . . . .

// int n,x,y,a,b,c,d,e;
//         cin>>n>>x>>y;
//         a = 2*(n-1);
//         b = min(x-1,y-1);
//         c = min(x-1,n-y);
//         d = min(n-x,y-1);
//         e = min(n-x,n-y);
//         a += b+c+d+e;
//         cout<<a<<endl;  