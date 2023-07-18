/*
11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
Input: height = [1,1]
Output: 1
*/

//two pointer approach
//take two pointers i and j
//i points to the first element
//j points to the last element
//calculate the area



#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1,maxArea = 0;

        while(i<=j)
        {
            int w = j-i;
            int h = min(height[i],height[j]);
            int curArea =w*h;
            maxArea = max(maxArea,curArea);

            if(height[i]<height[j])i++;
            else if(height[i]>height[j])j--;
            else{
                i++;
                j--;
            }
        }
        return maxArea;
    }
};
