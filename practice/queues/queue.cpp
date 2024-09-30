#include <bits/stdc++.h>
using namespace std;
//having problems here yay
struct QNode 
{
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};
struct Queue
{
    QNode *front, *rear;
    Queue() 
    {
        front = rear = NULL;
    }

    public void enqueue(int x)
    {
        //Create new LL node
        QNode* temp = new QNode(x);
        //If queue is empty, then 
        //new node is both front and rear
        if(rear == NULL)
        {
            front = rear = temp;
            return;
        }
        //add new node at end of queue and change rear
        rear->next = temp;
        rear = temp;
    }
    public void dequeue()
    {
        //if queue is empty, return NULL
        if(front == NULL)
            return;

        //store previous front and move front 
        //one node ahead
        QNode* temp = front;
        front = front->next;

        //if front becomes NULL, change rear to NULL
        if(front == NULL)
            rear = NULL;
        
        delete (temp);
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout << "Queue Front : " << ((q.front != NULL) ? (q.front)->data : -1)<< endl;
    cout << "Queue Rear : " << ((q.rear != NULL) ? (q.rear)->data : -1);
}
