#include <bits/stdc++.h>

using namespace std;
void func(int index,vector<int>& arr,vector<int>& subsequence,int n)
{
    if(index>=n)
    {
        //print all sequence
        for(auto it:subsequence)
            cout<<it<<" ";
        cout<<endl;
        return;
    }
    //taking the index element
    subsequence.push_back(arr[index]);
    func(index+1,arr,subsequence,n);

    //not taking the index element
    subsequence.pop_back();
    func(index+1,arr,subsequence,n);


}



int main()
{
    vector<int> arr= {3,1,2};
    int n = arr.size();
    vector<int> subsequence;
    func(0,arr,subsequence,n);

    return 0;
}
//output
// 3 1 2 
// 3 1 
// 3 2 
// 3 
// 1 2 
// 1 
// 2 