# [K Sum Paths](https://practice.geeksforgeeks.org/problems/k-sum-paths/)

```cpp
class Solution{
  public:
    void solve(Node * root, int k, vector<int> path, int &cnt){
        if(root == NULL)
            return;
        
        path.push_back(root -> data);
        
        solve(root -> left, k, path, cnt);
        solve(root -> right, k, path, cnt);
        
        long sum = 0;
        for(int i = path.size() - 1; i >=0 ; i--){
            sum += path[i];
            if(sum == k)
                cnt++;
        }
        
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path;
        int ans = 0;
        solve(root, k, path, ans);
        return ans;
    }
};
```