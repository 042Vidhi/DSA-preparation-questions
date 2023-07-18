/*
881. Boats to Save People
You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight of limit.
 Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

https://leetcode.com/problems/boats-to-save-people/description/
*/

//two pointer approach
//sort the array
//take two pointers i and j
//i points to the lightest person
//j points to the heaviest person
//since each boat can carry atmost two people
//if the sum of the weights of the two people is less than or equal to the limit
//then we can take them in the same boat
//else we can take only the heaviest person in the boat



#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int i=0,j=n-1,bcount=0;
        while(i<=j)
        {
            int cur=people[i]+people[j];
            if(cur<=limit)
            {
                
                i++;j--;
            }
            else{
                
                j--;
            }
            bcount++;
        }
        return bcount;
    }
};