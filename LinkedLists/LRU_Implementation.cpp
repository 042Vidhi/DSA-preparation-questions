/*
146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

-------------------------------------------------------------------------
https://leetcode.com/problems/lru-cache/description/
-------------------------------------------------------------------------

*/

#include <bits/stdc++.h>
using namespace std;
class LRUCache {
    struct Node{
        int key,val;
        struct Node *prev,*next;
        Node(int k,int v)
        {
            key=k;val=v;prev=NULL;next=NULL;
        }

    };
public:
    int maxSize,curSize;
    Node *head,*tail;
    unordered_map<int,Node*>m;
    LRUCache(int capacity) {
        maxSize=capacity;
        curSize=0;
        head=NULL;tail=NULL;
    }
    Node *addToTail(int key,int val)
    {
        Node *n=new Node(key,val);
        if(!tail){
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            n->prev=tail;
            tail=n;
        }
        curSize++;
        return n;
    }
    void moveToTail(Node* node,int val)
    {
        node->val=val;
        if(node==tail)return;
        if(node==head)
        {
            head=head->next;
            head->prev=NULL;
        }
        else{
            node->prev->next=node->next;
            node->next->prev=node->prev;

        }
        node->prev=tail;
        node->next=NULL;
        tail->next=node;
        tail=node;
    }
    void deleteAtHead()
    {
        Node* temp=head;
        head=head->next;
        if(head)head->prev=NULL;
        else tail=head;
        delete(temp);
        curSize--;
    }
    int get(int key) {
        int ans;
        if(m.find(key)==m.end())ans=-1;
        else{
            Node *n=m[key];
            ans=n->val;
            moveToTail(n,n->val);
        }
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            moveToTail(m[key],value);
            return;
        }
        if(curSize<maxSize)
        { m[key]=addToTail(key,value);}
        else{
            m.erase(head->key);
            deleteAtHead();
            m[key] = addToTail(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */