#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node * left;
        node * right;
    
    node(int data){
        this -> data = data;
        this -> left = this -> right = NULL;
    }
};

node * buildTree(node * root)
{
    int data;
    cout<<"Enter data to be inserted, -1 for null\n";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new node(data);

    cout<<"Enter data to be inserted on left of "<<data<<"\n";
    root -> left = buildTree(root->left);
    cout<<"Enter data to be inserted on right of "<<data<<"\n";
    root -> right = buildTree(root->right);

    return root;

}

void levelOrderTraversal(node * root)
{
    queue<node *> q;
    q.push(root);

    while(!q.empty()){
        node * curr = q.front();
        cout<<curr -> data<<" ";
        q.pop();

        if(curr -> left)
            q.push(curr->left);
        if(curr -> right)
            q.push(curr->right);
    }
}

int main()
{
    node * root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    
    return 0;
}