//Print all subsequence with sum K

#include <bits/stdc++.h>
using namespace std;
void func(int index,int sum,int K,vector<int>& ds,vector<int>& arr,int n)
{
    if(index>=n)
    {
        if(sum==K)
        {
            for(auto it:ds)
            cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[index]);
    sum +=arr[index];
    func(index+1,sum,K,ds,arr,n);

    ds.pop_back();
    sum -= arr[index];
    func(index+1,sum,K,ds,arr,n);


}
int main()
{
    vector<int> arr = {3,1,2};
    int n = arr.size();
    int K = 3;
    int sum =0;
    vector<int> ds;
    func(0,sum,K,ds,arr,n);
    return 0;
}