#include <bits/stdc++.h>
using namespace std;
bool find(int x,int n,vector<int> &v)
{
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        if(v[i]==-x) flag = true;
    }
    return flag;
} 

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    bool flag2 = true;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(!find(v[i],n,v))
        {
            flag2 = false;
            break;
        }
        
    }
    if(flag2)cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}