#include<bits/stdc++.h>
#define MAX 999
using namespace std;
int queue[MAX]; 
int front=0,rear = 0;
void push(int x)
{
    if(rear == MAX)
    {
        cout<<"queue full";
        return;
    }
    else
    {
        queue[rear] = x;
        rear++;
    }
    return 0;
}
void pop()
{
    if(front == rear)
    {
        cout<<"stack empty";
        return;
    }
    else
    {
        front = front + 1;
    }
    
}
int main()
{

    return 0;
}
