# [Vertical Traversal of Binary Tree](https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/)

```cpp
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        //map of horizontal distance and inside one map of level and node values vector 
        map<int , map<int, vector<int> > > nodes;
        //queue containing pair of node and one pair of hd and lvl
        queue< pair<Node *, pair<int, int> > > q;
        
        q.push({root, {0,0}});
        
        while(!q.empty())
        {
            pair<Node *, pair<int, int> > temp = q.front(); q.pop();
            
            Node * front = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(front -> data);
            
            if(front -> left)
                q.push({front -> left , {hd-1, lvl+1}});
            
            if(front -> right)
                q.push({front -> right , {hd+1, lvl+1}});
        }
        
        for(auto mapItem : nodes){
            for(auto vectorItem : mapItem.second){
                for(auto vecItem : vectorItem.second)
                    ans.push_back(vecItem);
            }
        }
        
        return ans;
    }
};
```