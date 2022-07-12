# [Diagonal Traversal of Binary Tree](https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/)

```cpp
vector<int> diagonal(Node *root)
{
   queue<Node *> q;
   vector<int> ans;
   
   if(root == NULL)
    return ans;
   
   q.push(root);
   
   while(!q.empty())
   {
       Node * curr = q.front();
       
       while(curr != NULL){
            ans.push_back(curr -> data);
           
            if(curr -> left)
                q.push(curr -> left);
            curr = curr -> right;
       }
       
       q.pop();
   }
   
   return ans;
}
```