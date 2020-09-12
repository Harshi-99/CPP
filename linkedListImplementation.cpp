#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* link;
};
Node* head;

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp = temp->link;
    }
}
void recursiveReversePrint(Node* p)
{
    if(p->link == NULL) return;
    cout<<p->data;
    recursiveReversePrint(p->link);
}
void reverseLinkedList()
{
    Node* current, *next, *prev;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void deleteNodeAtNthPosition(int pos)
{
    Node* temp = head;
    if(pos == 1)
    {
        head = temp->link;
        free(temp);
        return;
    }
    for(int i=0; i<pos-2; i++)
        temp = temp->link;
    Node* temp1 = temp->link;
    temp->link = temp1->link;
    free(temp1);
    
}
void insertAtNthPosition(int data, int pos)
{
    Node* temp2 = new Node();
    temp2->data = data;
    temp2->link = NULL;
    Node* temp = head;
    if(pos == 1)
    {
        temp2->link = head;
        head = temp2; 
        return;
    }
    for(int i = 0; i<pos-2; i++)
        temp = temp->link;
    temp2->link = temp->link;
    temp->link = temp2;

} 



int main()
{
    head = NULL;
    insertNode(2);
    insertNode(4);
    insertNode(6);
    insertAtNthPosition(9,1);
    print(head);
    //deleteNodeAtNthPosition(2);
    //reverseLinkedList();
    //cout<<"\n";
    //recursiveReversePrint(head);
    //print(head);
    return  0;

}
