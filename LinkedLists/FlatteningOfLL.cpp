/*


*/


#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
 
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
 
};

// ----------------------------------------------------------------------------------
 Node *mergeTwoSortedLists(Node *h1,Node *h2)
{
        if(!h1) return h2;
        if(!h2) return h1;

        Node* head, *tail, *p1 = h1 , *p2=h2;
        if(h1->data <= h2->data)
        {
            head=h1;tail=h1;p1=p1->bottom;
        }
        else{
             head=h2;tail=h2;p2=p2->bottom;
        }
        
        while (p1 && p2) {
            if (p1->data < p2->data) {
                tail->bottom = p1;
                p1 = p1->bottom;
            } else {
                tail->bottom = p2;
                p2 = p2->bottom;
            }
            tail = tail->bottom;
        }

        tail->bottom = p1 ? p1 : p2;
        return head;
}
Node *flatten(Node *root)
{
   if(!root || !root->next)return root;
   
   root->next = flatten(root->next);
   
   root = mergeTwoSortedLists(root,root->next);
   
   return root;
}

// ----------------------------------------------------------------------
void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

 
int main(void) {
 
	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
 
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
 
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);
 
				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;
 
            Node* root = flatten(head);
            printList(root);
            cout<<endl;
 
	}
	return 0;
}

