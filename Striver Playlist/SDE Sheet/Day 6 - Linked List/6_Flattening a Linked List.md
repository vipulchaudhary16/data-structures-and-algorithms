### [Flattening a Linked List](https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1)

```cpp
Node * merge2_LL(Node *a, Node *b){
    Node * temp = new Node(0);
    Node * res = temp;
    
    while(a and b){
        if(a -> data < b -> data){
            temp -> bottom = a;
            a = a -> bottom;
        } else {
            temp -> bottom = b;
            b = b -> bottom; 
        }
        temp = temp -> bottom;
    }
    
    if(a) temp -> bottom = a;
    else temp -> bottom = b;
    return res -> bottom;
}

Node *flatten(Node *root)
{
   if(!root or !root->next) return root;
   root -> next = flatten(root->next);
   root  = merge2_LL(root, root->next);
   return root;
}
