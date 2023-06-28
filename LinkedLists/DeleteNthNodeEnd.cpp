// 19. Remove Nth Node From End of List

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// -----------------------------------------------------------------------------


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* P1 = head;
        ListNode* P2 = head;
        int c=0;
        while(c<n)
        {
            P2 = P2 -> next;
            c++;
        }
        if(!P2){
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }
        while(P2->next)
        {
            P1 = P1 -> next;
            P2 = P2 -> next;
        }
        ListNode* delNode = P1 -> next;
        P1 -> next = P1 -> next -> next;
        delete(delNode);

        return head;
    }
};