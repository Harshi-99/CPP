#include<bits/stdc++.h>
#define MAX 101
using namespace std;
int stack[MAX];
int top = -1;

void push(int x)
{
    if(top == MAX)
    {
        cout<<"stack full";
        return;
    }
    stack[++top] = x;
    
}
void pop()
{
    if(top == -1)
    {
        cout<<"stack empty";
        return;
    }
    top--;
}
int top()
{
    return stack[top];
}
void print()
{
    int i;
    for(i=0; i<=top; i++)
        cout<<stack[i];
}
void push(int x)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    top = temp;
}
void pop()
{
    Node* temp;
    if(top == NULL)
        return;
        temp = top;
    top = top->link;
    free(temp);
}
void top()
{
    if(top == NULL)
        returm;
    cout<<top->data;
}
struct Node* front = NULL;
struct Node* rear = NULL;
void enquue(int x)
{
    node* temp =new Node();
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void deque( int x)
{
    if(front == NULL)
        return;
    if(front == rear)
    {
        front =rear =NULL;
    }
    front = front->next;
    free(temp);
}
int main()
{
    
    return 0;
}