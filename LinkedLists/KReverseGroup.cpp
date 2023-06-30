// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
//using recursion
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *curr =head;
        while(curr && count<k)
        {
            count++;
            curr = curr ->next;
        }
        if(count<k)return head;
        curr = head;
        ListNode *prev =NULL;
        ListNode *temp;
        count =0;
        while(count<k)
        {
            temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr = temp;
            count++;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};