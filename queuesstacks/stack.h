// Written by MM Clark
# pragma once
# include <iostream>
# include "request.h"
using namespace std;

const int SIZE = 45;
class stack
{
    private:
        request stack[SIZE];
        int head = -1;

    public:
        void push(request);
        request pop();
        void peek();
        void print();
};

void stack::push(request val)
{
    if(head>=SIZE-1)
        cout << "Stack overflow. " << endl;
    else
    {
        head++;
        stack[head] = val;
    }
}

request stack::pop()
{
    request ret;
    if(top <= -1)
        cout << "Stack underflow. " << endl;
    else
    {
        ret = stack[head];
        head--;
    }
    return ret;
}

void stack::peek()
{
    if(top <= -1)
        cout << "Stack underflow. " << endl;
    else
        cout << stack[head].toString() << endl;
}

void stack::print()
{
    if(top<=0)
    {
        cout << "Stack is empty. " << endl;
        return;
    }
    for(int i=head; i>=0; i--)
        cout << stack[i].toString() << " | ";
    cout << endl;
}