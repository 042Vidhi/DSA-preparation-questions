

//Cycle lenght in a linked list

// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1?track=Placement



#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int countNodesinLoop(struct Node *head)
{
    if(head==NULL || head->next==NULL) return 0;
        Node *slow =head;
        Node *fast =head;
        Node *pos = head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                {
                    while(slow!=pos)
                    {
                        pos = pos->next;
                        slow=slow->next;

                    }
                    int count = 1;
                    Node* temp =pos->next;
                    while(temp!=pos)
                    {
                        temp=temp->next;
                        count++;
                    }
                    return count;
                }
        }
    return 0;
}