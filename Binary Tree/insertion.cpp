#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
struct node{
    int data;
    node*right , *left;
    node(int val){
        data = val;
        right = left = NULL;
    }
};

void preorder(node*root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
} 

void inorder(node*root){
    if(root ==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

void postorder(node*root){
    if(root ==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}

void BFS(node*root){
    if(root == NULL)
        return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i<size;i++){
            node *temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right->left = new node(8);
    root->right->right->left = new node(9);
    root->right->right->right = new node(10);

    cout<<"PRE-order :";
    preorder(root);
    cout<<endl;

    cout<<"In-order :";
    inorder(root);
    cout<<endl;

    cout<<"post-order :";
    postorder(root);
    cout<<endl;

    cout<<"BFS : ";
    BFS(root);
    return 0; 
}