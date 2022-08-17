#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

long getTimeinMicroSeconds(){
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec * 1000000 + start.tv_usec;
}


void intersection(int *input1, int *input2, int size1, int size2) 
{
	sort(input1,input1+size1);
    sort(input2,input2+size2);
     for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
           if(input1[i]==input2[j]){
            cout<<input1[i]<<" ";
            // input2[j] = -1;
           	break;
           }     
        }
    }
}

int func(int n){
	return func(n-1);
}

int main()
{
 //    long starttime, endtime;		
	// int t;
	// cin >> t;
	// while (t--)
	// {

	// 	int size1, size2;

	// 	cin >> size1;
	// 	int *input1 = new int[size1];

	// 	for (int i = 0; i < size1; i++)
	// 	{
	// 		cin >> input1[i];
	// 	}

	// 	cin >> size2;
	// 	int *input2 = new int[size2];

	// 	for (int i = 0; i < size2; i++)
	// 	{
	// 		cin >> input2[i];
	// 	}


	// 	starttime = getTimeinMicroSeconds();
 //    	intersection(input1, input2, size1, size2);
 //    	endtime = getTimeinMicroSeconds();

	//     cout<<"time "<< endtime-starttime<<endl;

	// 	delete[] input1;
	// 	delete[] input2;
		
	// 	cout << endl;
	// }

	// int num = 5;
	// int ans = func(num-1);

	// int a = 50;
	// int *ptr = &a;
	// cout<<(*ptr)++<<endl;
	// cout<<a;
	// // cout<<d<<endl;
	// return 0;
	double a = 55.5;
	int b = 55;

	double c = a+b;
	b = b%10;
	cout<<c<<endl;
}