
// 61. Rotate List

// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 
// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 10^9



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        ListNode *last = head;
        ListNode *temp = head;

        int n=1;
        while(last->next)
        {
            last=last->next;
            n++;
        }
        int rotateSteps = n - (k % n);
        for(int i=0;i<rotateSteps-1;i++)
            temp=temp->next;

        last->next=head;
        head=temp->next;
        temp->next=nullptr;

        return head;

    }
};