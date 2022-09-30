# [Bottom View of Binary Tree](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/)

```cpp
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        map<int, int> topNodes;
        queue<pair<Node *, int> > q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto temp = q.front(); q.pop();
            Node * frontNode = temp.first;
            int hd = temp.second;
            
            topNodes[hd] = frontNode -> data;
                
            if(frontNode -> left)
                q.push({frontNode -> left, hd - 1});
            if(frontNode -> right)
                q.push({frontNode -> right, hd + 1});
        }
        
        for(auto ele : topNodes)
            ans.push_back(ele.second);
        return ans;
    }
};
```