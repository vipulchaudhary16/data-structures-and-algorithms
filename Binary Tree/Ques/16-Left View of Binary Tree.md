# [Left View of Binary Tree](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree)

```cpp
vector<int> leftView(Node *root)
{
    queue<Node *> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(root);

    while (!q.empty())
    {

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == 0)
                ans.push_back(curr->data);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return ans;
}
```

## Recursive

```cpp
void solve(Node * root, vector<int> &ans, int level){
    if(root == NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root -> data);
        
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}
```