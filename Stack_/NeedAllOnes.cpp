// Need All Ones
// You are given a binary matrix, that is a matrix consisting of only 1s and 0s, of size m * n.

// You have to find the rectangle of maximum area in this matrix consisting of all 1s, whose coordinates are of the form (0,a), (0,b), (c,a), (c,b) where a<=b and c>=0.

// (0,0) is the bottom-left element of matrix, positive x axis is towards the right and positive y axis towards top.

// Input Format

// The first line of input contains 2 integers n and m, the dimensions of the matrix.

// The next n lines of input consists of m binary integers (0 or 1), representing one row of the binary matrix.

// Constraints

// 1 <= m,n <= 10^3

// Output Format

// Output contains a single integer, the area of the rectangle of maximum area that can be formed which consists of all 1s.

// Sample Input 0

// 3 3
// 1 0 0
// 0 1 1
// 1 1 1
// Sample Output 0

// 4
// Explanation 0

// The matrix formed by the coordinates (0,1) (0,2) (1,1) (1,2) is the required matrix with area 4.

// Sample Input 1

// 5 5
// 1 0 1 0 1
// 0 1 0 1 0
// 1 1 1 1 0
// 1 1 1 1 1
// 1 1 1 1 1
// Sample Output 1

// 12
// Explanation 1

// Coordinates (0,0) (0,4) (3,0) (3,4).
// https://www.hackerrank.com/contests/gl-bajaj-self-evaluation-contest/challenges/need-all-ones/problem

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<vector<int>> &mat)
    {   
        int n = mat.size();
        int m = mat[0].size();
        //precomputation of heights
        vector<int> heights(m,0);
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int i=n-1;i>=0;i--){
                if(mat[i][j]==0)
                {
                    break;
                }
                else
                    cnt++;
            }
            heights.push_back(cnt);
        }

        int n1 = heights.size();
        vector<int> NSE(n1,n1),PSE(n1,-1);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n1;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                NSE[st.top()] =i;
                st.pop();
            }
            st.push(i);
        }
        st.push(n1-1);
        for(int i=n1-2;i>=0;i--)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                PSE[st.top()] =i;
                st.pop();
            }
            st.push(i);
        }
        int maxArea = INT_MIN;
        for(int i=0;i<n1;i++)
        {
            maxArea = max(maxArea ,  (NSE[i]-PSE[i]-1) * heights[i] );
        }
        return maxArea;

    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<s.largestRectangleArea(mat)<<endl;
    return 0;
}