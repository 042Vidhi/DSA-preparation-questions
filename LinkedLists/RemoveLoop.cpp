
// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?page=2&category%5B%5D=Linked%20List&query=page2category%5B%5DLinked%20List

// Remove loop in Linked List


#include <bits/stdc++.h>
using namespace std;
  struct Node {
      int val;
      Node *next;

        Node(int x) {
            val = x;
            next = NULL;
        }
    
  };
  class Solution {
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        
        Node* slow = head;
        Node* fast = head;
        
        // Detecting the loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        
        // No loop found
        if (slow != fast)
            return;
        
        slow = head;
        
        // Finding the start of the loop
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Moving to the last node of the loop
        while (fast->next != slow) {
            fast = fast->next;
        }
        
        // Removing the loop
        fast->next = nullptr;
    }
};