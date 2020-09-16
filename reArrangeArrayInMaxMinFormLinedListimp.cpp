//reArrangeArrayInMaxMinForm
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* link;
};


void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp = temp->link;
    }
}
Node* getNewNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->link = NULL;
    return temp;
 }
Node* insertNode(Node* head,int data)
{
    if (head == NULL)
    {
        head = getNewNode(data);
        return head;   
    }
    else if(data < head->data)
    {
        Node* temp = getNewNode(data);
        temp->link = head;
        head = temp;
         return head;
    }
    else if(data >= head->data)
    {
        Node* temp = head;
        while(temp->data < data && temp->link!=NULL)
        {
            temp = temp->link;
        }
        Node* temp2 = getNewNode(data);
        temp2->link = temp->link;
        temp = temp2;
        return head; 

    }
  
    

}
void printNode(Node* head)
{
    if(head == NULL) return;
    cout<<head->data;
    
    printNode(head->link); 
}

int main()
{
    Node* head = NULL;
    head = insertNode(head,2);
    insertNode(head,1);
    insertNode(head,6);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,7);
    insertNode(head,8);
    printNode(head);

    return 0;
}