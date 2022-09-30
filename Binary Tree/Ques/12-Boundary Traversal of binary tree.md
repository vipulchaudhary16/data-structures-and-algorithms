# [Boundary Traversal of binary tree](https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/)

```cpp
class Solution
{
public:
    void leftTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->right == NULL and root->left == NULL))
            return;

        ans.push_back(root->data);

        if (root->left)
            leftTraversal(root->left, ans);
        else
            leftTraversal(root->right, ans);
    }

    void leavesTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (root->right == NULL and root->left == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        leavesTraversal(root->left, ans);
        leavesTraversal(root->right, ans);
    }

    void rightTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->right == NULL and root->left == NULL))
            return;

        if (root->right)
            rightTraversal(root->right, ans);
        else
            rightTraversal(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        ans.push_back(root->data);

        leftTraversal(root->left, ans);

        leavesTraversal(root->left, ans);
        leavesTraversal(root->right, ans);

        rightTraversal(root->right, ans);

        return ans;
    }
};

```