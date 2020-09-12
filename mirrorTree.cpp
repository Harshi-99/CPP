#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* getNewNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
/*Node* Insert(Node* root, int data)
{
    if(root == NULL)
    {
        root = getNewNode(data);
        return root;
    }
    else if(data < root->data)
        root->left = Insert(root->left, data);
    else if(data > root->data)
        root->right = Insert(root->right, data);
    return root;
}*/
Node* Insert(Node* root, int data)
{
    queue<Node*> q;
    Node* temp;
    q.push(root);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->left == NULL)
        {
            temp->left = getNewNode(data);
            break;
        }
        else
            q.push(temp->left);
        if(temp->right == NULL)
        {
            temp->right = getNewNode(data);
            break;
        }
        else
            q.push(temp->right);
    }
    return root;
}
void mirrorTree(Node* root)
{
    if(root == NULL)
        return;
    mirrorTree(root->right);
    cout<<root->data;
    mirrorTree(root->left);

}
int main()
{
    Node* root = NULL;
    root = Insert(root,10);
    Insert(root,20);
    Insert(root,30);
    Insert(root,40);
    Insert(root,60);
    mirrorTree(root);
    return 0;
}