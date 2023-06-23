// 85. Maximal Rectangle
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:
// Input: matrix = [["0"]]
// Output: 0
// Example 3:
// Input: matrix = [["1"]]
// Output: 1
// Constraints:
// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.

// https://leetcode.com/problems/maximal-rectangle/description/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxRec = 0;
        //precomputation of heights
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                    heights[j]=0;
                else
                    heights[j]+=1;
            }
            maxRec = max(maxRec , largestRectangleHistogram(heights));
        }

        return maxRec;
    }
    int largestRectangleHistogram(vector<int> &heights)
    {
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