/*
21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

------------------------------------------------------------
https://leetcode.com/problems/merge-two-sorted-lists/
------------------------------------------------------------

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

        //using dummy node
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    //without using dummy node
     /*   ListNode *mergeTwoLists(ListNode *h1, ListNode *h2) {
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
    */

   // using recursion
   /*
   ListNode *mergeTwoLists(ListNode *h1, ListNode *h2)
    {
        if(!h1) return h2;
        if(!h2) return h1;
        ListNode *head ,*temp;
        if(h1->val<=h2->val )
        {
            head = h1;
            temp = head->next;
            head->next = NULL;
            head->next = mergeTwoLists(temp,h2);
        }
        else{
            head = h2;
            temp = head->next;
            head->next = NULL;
            head->next = mergeTwoLists(h1,temp);
        
        }
        return head;
    }
   */
};