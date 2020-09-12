#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node* getNewNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insertLevelOrder(int arr[], Node *root, int i, int n)
{
    if(i<n)
    {
        Node *temp = getNewNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr,root->left,i*2+1,n);
        root->right = insertLevelOrder(arr, root->right, i*2+2, n);

    }
    return root;
}
Node *concatenate(Node* leftList, Node* rightList)
{
    if(leftList == NULL)
        return rightList;
    if(rightList == NULL)
        return leftList;
    Node* leftLast = leftList->left;
    Node* rightLast = rightList->right;
    
    leftLast->right = rightLast;
    rightList->left = leftLast; 

    leftList->left = rightLast; 
  
    // Right of last node refers to the first 
    // node of the List 
    rightLast->right = leftList; 
  
    return leftList; 
}
Node* convertCDLL(Node* root)
{
    if(root == NULL)
        return NULL;
    Node* left = convertCDLL(root->left);
    Node* right = convertCDLL(root->right);
    root->left = root->right = root;
    return concatenate(concatenate(left,root),right);
}
void bTreeToDList(Node* root,Node **head)
{
    if(root == NULL)
        return;
 
    static Node* prev = NULL;
    bTreeToDList(root->left, head);
    if(prev == NULL)
    {
           static Node* first = root;
        *head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
        
    }
    prev = root;
    bTreeToDList(root->right,head);
}

void printBinaryTree(Node* head)
{
    
    
    while (head!=NULL) 
    { 
        cout << head->data << " "; 
        head = head->right; 
    } 
}
int main()
{
    Node* root;
    int arr[] = {10,12,15,25,30,36};
    int n = sizeof(arr)/sizeof(arr[0]);
    root = insertLevelOrder(arr,root, 0, n);
    Node *head = NULL;
    bTreeToDList(root,&head);
    printBinaryTree(head);
    
    return 0;
}