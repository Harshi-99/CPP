#include<bits/stdc++.h>
using namespace std;
struct Node
{
    /* data */
    int data;
    Node *left;
    Node *right;
};
Node* getNewNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* Insert(Node* root, int data)
{
    if(root==NULL)
    {
        root = getNewNode(data);
        
        return root;
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
        
    }
    return root;
    
}
void preorder(Node* root)
{
    if(root == NULL) return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right); 
}
void inorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void postorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data;
    
}
/*void printGivenLevel(Node* root, int level)
{
    if(root == NULL) return;
    if(level == 1) cout<<root->data<<" ";
    else{
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}*/
/*void printLevelOrder(Node* root,int h)
{
    if(root == NULL)
        return;
    queue<Node>q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr = q.front();
        cout<<curr->data;
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);
        q.pop();
    }
}*/
void printLevelOrder(Node* root,int h)
{
    int i;
    for(i=1; i<=h; i++)
        printGivenLevel(root,i);
}
bool search(Node* root, int data)
{
    if(root == NULL) return false;
    else if(root->data == data)
        return true;
    else if(root->data >= data)
        search(root->left,data);
    else
        search(root->right, data);
    
}
int findMin(Node* root)
{
    if(root == NULL) return -1;
    Node* current = root;
    while(current->left != NULL)
        current = current->left;
    return current->data;
}
int findMax(Node* root)
{
    if(root == NULL) return -1;
    Node* current = root;
    while(current->right)
        current = current->right;
    return current->data;

}
int max(int a,int b)
{
    return (a>b)?a:b;
    
}
int findHeight(Node* root)
{
    if(root == NULL) return -1;
    return max(findHeight(root->left),findHeight(root->right))+1;
}
bool isSubtreeLesserThan(Node* root,int value);
bool isSubtreeGreaterThan(Node* root, int value);
bool isBST(Node* root)
{
    if(root == NULL) return true;
    if(isSubtreeLesserThan(root->left,root->data)&&isSubtreeGreaterThan(root->right,root->data)&&isBST(root->left)&&isBST(root->right))
        return true;
    else
    {
            return false;
    }
    
}
bool isSubtreeLesserThan(Node* root,int value)
{
    if(root == NULL) return true;
    if((root->data <= value) && isSubtreeLesserThan(root->left,value) && isSubtreeLesserThan(root->right,value))
        return true;
    else 
        return false;
    
}
bool isSubtreeGreaterThan(Node* root, int value)
{
    if(root == NULL) return true;
    if((root->data >= value)&& isSubtreeGreaterThan(root->right,value)&& isSubtreeGreaterThan(root->left,value))
        return true;
    else
    {
            return false;
    }
    
}
/*struct Node* delete(struct Node* root,int data)
{
    if(root == NULL) return root;
    else if(data < root->data)
        root->left = delete(root->left,data);
    else if(data > root->data)
        root->right = delete(root->right,data);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return root;
        }    
        else if(root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if(root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        else
        {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
            return root;
        }
    }
    
}*/
int main()
{
    Node *root = NULL;
    root =  Insert(root,15);
     Insert(root,10);
    Insert(root,20);
    Insert(root,30);
    Insert(root,5);
    Insert(root,2);
    preorder(root);
    inorder(root);
    postorder(root);
    printLevelOrder(root,6);
    if(search(root,10))
        cout<<"yeye";
    else
        cout<<"NOOO";
    cout<<findMin(root);
     cout<<findMax(root);
     cout<<findHeight(root);
     if(isBST(root))
        cout<<"yeye";
    else
        cout<<"NOOO";
    
    
    return 0;
}
