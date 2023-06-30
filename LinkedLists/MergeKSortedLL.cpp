/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
----------------------------------------------------------------------
https://leetcode.com/problems/merge-k-sorted-lists/description/
----------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
        //without recursion
        ListNode *mergeTwoLists(ListNode *h1, ListNode *h2) {
        if(!h1) return h2;
        if(!h2) return h1;

        ListNode* head, *tail, *p1 = h1 , *p2=h2;
        if(h1->val <= h2->val)
        {
            head=h1;tail=h1;p1=p1->next;
        }
        else{
             head=h2;tail=h2;p2=p2->next;
        }
        
        while (p1 && p2) {
            if (p1->val < p2->val) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        tail->next = p1 ? p1 : p2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() ==0) return NULL;
        ListNode *ans =lists[0];
        for(int i = 1;i<lists.size();i++)
        {
            ans = mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }
};