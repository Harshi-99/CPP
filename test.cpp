// 21 24  27 20  29  26  23 30  22 28 
struct Node
{
    int data;
    struct Node* link;
    
};
Node* head = NULL;
Node* insert(int data)
{
     Node* temp = new Node();
     temp->data = data;
     temp->link = NULL;
     head = temp;
     return head;

}
int findMissingNumber(Node* head)
{
    Node* temp = head;
    int min = temp->data;
    int max = temp->data;
    while(temp->link != NULL)
    {
        if(temp->data <= min)
            min = temp->data;
        else if(temp->data >= max)
            max = temp->data;
        temp = temp->link;
    }
    
}
int main()
{
    head = insert(21);
    insert(24);
    insert(27);
    insert(20);
    insert(29);
    insert(26);
    insert(23);
    insert(30);
    insert(22);
    insert(28);
    return 0;
}