
//Check for cycle in a linked list
/*
--------------------------------------------------------------
https://leetcode.com/problems/linked-list-cycle/
---------------------------------------------------------------
*/



#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //*************************Floyd's algorithm**********************
        ListNode* slow=head;
        ListNode* fast=head;
    if(head==NULL)
        return false;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
            return true;
    }
        return false;
        //*************************MAP******************************
    //      if(head==NULL)
    //     return false;
    // unordered_map<ListNode*,int> map;
    // while(head!=NULL){
    //     if(map.count(head)>0)
    //         return true;
    //     else
    //         map[head]=1;
    //     head=head->next;
    // }
    // return false;
        //********************************HACK****************************
        // if(!head) return false;
        // int count = 0;
        // while( head ){
        //     count++;
        //     if(count > 10000) break;
        //     head = head -> next;
        // }
        // return count > 10000 ? true : false;
    }
};