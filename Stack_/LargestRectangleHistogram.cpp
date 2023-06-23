// 84. Largest Rectangle in Histogram
// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:
// Input: heights = [2,4]
// Output: 4
// Constraints:
// 1 <= heights.length <= 10^5
// 0 <= heights[i] <= 10^4

// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSE(n,n) , PSE(n,-1);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                NSE[st.top()] =i;
                st.pop();
            }
            st.push(i);
        }
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                PSE[st.top()] =i;
                st.pop();
            }
            st.push(i);
        }
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxArea = max(maxArea ,  (NSE[i]-PSE[i]-1) * heights[i] );
        }

        return maxArea;
    }
};