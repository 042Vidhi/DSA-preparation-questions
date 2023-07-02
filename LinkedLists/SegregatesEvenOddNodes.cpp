/*


*/

#include <bits/stdc++.h>
using namespace std;
class Node {

    public:
    int data;
    Node *next;
   
    Node(int x){
        data = x;
        next = NULL;

    }
};
class Solution {
public:
    Node* divide(int N, Node* head) {
        if (!head || !head->next)
            return head;

        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;

        Node* cur = head;

        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            temp->next = NULL; // Set the next pointer of temp to NULL to avoid cyclic linked list

            if (temp->data % 2 == 0) {
                if (evenHead == NULL) {
                    evenHead = temp;
                    evenTail = temp;
                } else {
                    evenTail->next = temp;
                    evenTail = temp;
                }
            } else {
                if (oddHead == NULL) {
                    oddHead = temp;
                    oddTail = temp;
                } else {
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }
        }

        if (evenHead != NULL) {
            evenTail->next = oddHead;
            return evenHead;
        } else {
            return oddHead;
        }
    }
};
