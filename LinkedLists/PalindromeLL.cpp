// 234. Palindrome Linked List
// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true
// Example 2:
// Input: head = [1,2]
// Output: false

// ------------------------------------------------------------------
// https://leetcode.com/problems/palindrome-linked-list/description/
// ------------------------------------------------------------------


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
    bool isPalindrome(ListNode* head) {
        ListNode *mid=getmid(head);
        ListNode *t=reverse(mid);
        ListNode *h=head;
        while(h && t)
        {
            if(h->val!=t->val)return false;
            h=h->next;
            t=t->next;
        }
        return true;
    }
};