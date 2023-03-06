# [Shortest path in an unweighted graph](https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297)

```cpp
#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    //adjList
    unordered_map<int, list<int>> adjList;
    for(auto e : edges){
        adjList[e.first].push_back(e.second);
        adjList[e.second].push_back(e.first);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        
        for(auto i : adjList[f]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = f;
                q.push(i);
            }
        }
    }
    
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);
    
    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

```