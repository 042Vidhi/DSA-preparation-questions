#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={2,1,3};
    int n = 3;
    while(next_permutation(arr,arr+n))
    {
        cout<<arr[0]<<arr[1]<<arr[2]<<endl;
    }
    return 0;
}