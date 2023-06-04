
// Making Teams

// There are N boys and M girls attending a class.
// The teacher needs to choose a group containing exactly X students containing no less than 4
//  boys and no less than one girl for an project.

// How many ways are there to choose a group?

// Input Format
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// For each test case contains three numbers N,M and X.

// Output Format
// For each test case, print the number of ways to form a group on seperate line.


#include <iostream>
using namespace std;
int main() {
    //precomputing the pascal triangle
    long long pas[61][61];
    pas[0][0] =1;
    for(int i =1; i<=60; i++){
        for(int j =0; j<=i; j++){
            if(j==0 || j==i){
                pas[i][j] =1;
            }
            else{
                pas[i][j] = pas[i-1][j] + pas[i-1][j-1];
            }
        }
    }
//taking input
    int t;
    cin >> t;
    while(t--){
        long long n,m,x;
        cin >> n >> m >> x;
        long long ans =0;
        for(int i =4; i<=n; i++){
            int j = x-i;
            if(j>=1 && j<=m)
            ans+= pas[n][i]*pas[m][j];
        }
        cout << ans << endl;
    }
return 0;
}