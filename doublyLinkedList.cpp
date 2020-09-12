#include<bits/stdc++.h>
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
Node* head;
void insert(int data)
{
    Node* temp = new Node();
    if(head == NULL)
    {
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }
    
}
void forwardPrint()
{
    Node* temp = head;
    while(head->next!=NULL)
    {   
        cout<<temp->data;

            temp = temp->next;
        }
}
void insertNode(int data)
{
    Node* temp =  getNewNode(data);
    if(head == NULL)
        head = temp;
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void insertAttail(int data)
{
    Node* temp = head;
    Node* newNode = getNewNode(int data);
    if(root == NULL)
        head = newNode;
    while(temp->next != NULL)
        temp =temp->next;
    temp->next = newNode;;    
    newNode->prev = temp;

}
int main()
{
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    return 0;
}