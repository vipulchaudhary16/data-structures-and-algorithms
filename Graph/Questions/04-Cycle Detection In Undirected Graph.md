# [ Cycle Detection In Undirected Graph ](https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include<bits/stdc++.h>

bool isCyclic(int node, unordered_map<int, list<int>> adj, 
              vector<int> &visited){
    unordered_map<int, int> parent;
    parent[node] = -1;
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()){
        int top = q.front();
        q.pop();
        
        for(auto adj_node : adj[top]){ 
            if(visited[adj_node] and adj_node != parent[top]){
                return true;
            } else if(!visited[adj_node]){
                q.push(adj_node);
                parent[adj_node] = top;
                visited[adj_node] = 1;
            } 
        }
    }
     return false;   
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    vector<int> visited(n+1, 0);
    
    for(int i = 0; i < n; i++){
        if(!visited[i])
        {
            if(isCyclic(i, adj, visited))
                return "Yes";
        }
    }
    return "No";
}

```