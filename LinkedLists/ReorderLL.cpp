// 143. Reorder List
// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:


// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
 

// Constraints:

// The number of nodes in the list is in the range [1, 5 * 10^4].
// 1 <= Node.val <= 1000
// --------------------------------------------------------------
// https://leetcode.com/problems/reorder-list/description/
// --------------------------------------------------------------


#include<bits/stdc++.h>
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
    ListNode *getmid(ListNode *head)
    {
        ListNode *slow =head;
        ListNode *fast =head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

        }
        return slow;

    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *temp=NULL;
        while(curr)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *mid=getmid(head);
        ListNode *t=reverse(mid->next);
        mid->next = nullptr;
        ListNode *h=head;
        while(h && t)
        {
            ListNode *h1 = h->next;
            ListNode *t1 = t->next;
            
            h->next = t;
            t->next = h1;
             
            h=h1;
            t=t1;

        }
    }
};