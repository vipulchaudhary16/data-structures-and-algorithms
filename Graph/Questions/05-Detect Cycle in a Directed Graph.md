# [ Detect Cycle in a Directed Graph ](https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_920545?leftPanelTab=0)

```cpp
#include<bits/stdc++.h>
bool detectCycle(int node, unordered_map<int, list<int>> &adjList,
                unordered_map<int, bool> &visited,
                unordered_map<int, bool> &dfsVisited){
    visited[node] = true;
    dfsVisited[node] = true;
    
    for(int adj : adjList[node]){
        if(!visited[adj]){
            if(detectCycle(adj, adjList, visited, dfsVisited))
                return true;
        } else if(dfsVisited[adj] == true)
            return true;
    }
    //backtracking
    dfsVisited[node] = false;
    return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	unordered_map<int, list<int>> adjList;
    for(auto edge : edges) adjList[edge[0]].push_back(edge[1]);
    unordered_map<int, bool> visited, dfsVisited;
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            if(detectCycle(i,adjList,visited, dfsVisited)) return true;
        }
    }
    return false;
}
```