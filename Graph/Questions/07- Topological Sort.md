# [ Topological Sort ](https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include <bits/stdc++.h> 
void solve(int node, unordered_map<int, list<int>> &adjList,
          vector<int> &visited,
          stack<int> &s){
    visited[node] = 1;
    
    for(auto adj : adjList[node]){
        if(!visited[adj])
            solve(adj, adjList, visited, s);
    }
    
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    
    unordered_map<int, list<int>> adjList;
    for(auto e : edges) adjList[e[0]].push_back(e[1]);
    
    vector<int> visited(v, 0);
    stack<int> s;
    
    for(int i = 0; i < v; i++){
        if(!visited[i])
            solve(i, adjList, visited, s);
    }
    
    while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
    }
    return ans;
 
}
```