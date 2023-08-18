/*

Check if two nodes are cousins in a Binary Tree
https://practice.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1

*/


//Approach:
//1. Find the level of both the nodes
//2. If level is same and parents are different then they are cousins
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
int findLevel(Node *root,int v,int level)
{   
    if(!root)
     return 0;
     
     if(root->data) return level;
     
     return max(findLevel(root->left , v , level + 1) ,
       findLevel(root->right , v , level + 1) );
    
}
Node *getParent(Node* root ,int v)
{
    if(!root) return root;
    if(root->left && root->left->data == v ) return root;
    if(root->right && root->right->data == v) return root;
 
    Node* ptr = getParent(root->left , v);
    if(ptr) return ptr;
 
    return getParent(root->right , v);
}


bool isCousins(Node *root, int a, int b)
{
   int levela = findLevel(root , a , 1);
   int levelb = findLevel(root , b , 1);
   
    if(levela == levelb && getParent(root , a) && getParent(root , b) &&
   getParent(root , a) != getParent(root , b)) return true;
 
    return false;
   
}