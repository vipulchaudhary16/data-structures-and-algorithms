# [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> ansAtCurrLevel(size);

            for(int i = 0; i < size; i++)
            {
                TreeNode * frontNode = q.front(); q.pop();
                ansAtCurrLevel[leftToRight ? i : size - 1 - i] = frontNode -> val;

                if(frontNode -> left)
                    q.push(frontNode -> left);

                if(frontNode -> right)
                    q.push(frontNode -> right);

            }
            leftToRight = !leftToRight;
            result.push_back(ansAtCurrLevel);
            ansAtCurrLevel.clear();
        }
        return result;
    }
};
```
