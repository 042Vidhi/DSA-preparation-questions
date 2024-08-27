#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *que;
    int front , rear , size ;
    public:
    Queue(int n)
    {
        que = new int[n];
        front = -1;
        rear =-1;
        size = n;
    }
    void push(int element)
    {
        //overflow condition
        if((rear + 1) % size == front)
        {
            cout<<"Overflow:Queue is full\n";
            return;
        }
        //for the first element
        if(rear == -1 && front == -1)
        {
            front =0;
            rear =0;
        }
        else{
            rear = (rear+1)%size;
        }
        que[rear] = element;
        cout<<"Element:"<<element<<"inserted"<<endl;
    }
    int pop()
    {
        if(front == -1)
        {
            cout<<"Underflow\n";
            return -1;
        }
       
            int popedItem = que[front];
            //means the queue is empty
            if(front == rear)
            {
                front = -1;
                rear = -1;
            }
            else{
                front = (front+1)%size;
            }
        return popedItem;

    }

    void display()
    {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << que[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};
int main() {
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);  // Queue should be full after this

    q.display();  // Display all elements in the queue

    cout << "Popped: " << q.pop() << endl;  // Pops 10
    cout << "Popped: " << q.pop() << endl;  // Pops 20

    q.display();  // Display remaining elements

    q.push(60);  // Inserts 60 into the queue
    q.display();  // Display all elements in the queue

    q.push(70);  // Try to push when the queue is full
    q.display();  // Final state of the queue

    return 0;
}