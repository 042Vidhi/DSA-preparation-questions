/*Linked List Pair Sum

Given a linked list, and a number, check if their exist two numbers whose sum is equal to given number. If there exist two numbers, print them. If there are multiple answer, print any of them.

https://www.geeksforgeeks.org/linked-list-pair-sum/
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class PairSumLL {
public:
    void push(ListNode** head, int data) {
        ListNode* newNode = new ListNode(data);
        newNode->next = *head;
        *head = newNode;
    }

    bool pairSum(ListNode* head, int sum) {
        unordered_set<int> m;
        ListNode* curr = head;

        while (curr != NULL) {
            if (m.find(sum - curr->val) != m.end()) {
                cout << curr->val << " " << sum - curr->val << endl;
                return true;
            }
            m.insert(curr->val);
            curr = curr->next;
        }
        return false;
    }
};

int main() {
    ListNode* head = nullptr;
    PairSumLL obj;

    /* Create following linked list
    1->12->1->4->1->6->1->8->NULL */
    
    obj.push(&head, 1);
    obj.push(&head, 4);
    obj.push(&head, 1);
    obj.push(&head, 12);
    obj.push(&head, 1);
    obj.push(&head, 18);
    obj.push(&head, 47);
    obj.push(&head, 16);
    obj.push(&head, 12);
    obj.push(&head, 14);
 
    int n = 26;
    bool res = obj.pairSum(head, n);
    if (res == false)
        cout << "NO PAIR EXISTS";
 
    return 0;
}
