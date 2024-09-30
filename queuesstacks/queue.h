// Written by MM Clark
# pragma once
# include <iostream>
# include "request.h"
using namespace std;

const int SIZE = 45;

class queue
{
    private:
        request queue[SIZE];
        int front = -1;
        int rear = -1;

    public:
        bool isEmpty();
        void enqueue(request);
        request dequeue();
        void peek();
        void print();
};

// funct to check if quq
bool queue::isEmpty()
{
    if(front == -1 && rear == -1)
        return true;
    else
        return false;
}

// function to insert element in queue
void queue::enqueue(request val)
{
    if(rear == SIZE-1)
        cout << "Queue is full " << endl;
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = val;
    }
}

// function to remove element from queue
request queue::dequeue()
{
    request ret;
    if(isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        ret = queue[front];
        if(front == rear)
            front = rear = -1;
        else
            front++;
    }
    return ret;
}

// function to show head element
void peek()
{
    if(isEmpty())
        cout << "Queue is empty. " << endl;
    else
    {
        cout << queue[front] << endl;
    }
}

// function to print elements of queue
void queue::print()
{
    if(isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        for(int i=front; i<=rear; i++)
            cout << queue[i].toString() << " ";
        cout << "\n";
    }
}