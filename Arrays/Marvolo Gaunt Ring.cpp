// https://codeforces.com/problemset/problem/855/B
#include<bits/stdc++.h>
using namespace std;
long long a=LLONG_MIN,b=LLONG_MIN,c=LLONG_MIN,d;
int n,p,q,r;
main(){
cin>>n>>p>>q>>r;
for(int i=0;i<n;i++){
cin>>d;
a=max(a,p*d);
b=max(b,a+q*d);
c=max(c,b+r*d);
}
cout<<c;
}
