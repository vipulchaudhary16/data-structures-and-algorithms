# [ Bridges In A Graph ](https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0)

```cpp
#include<bits/stdc++.h>

void dfs(int node, int &parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adjList){
    vis[node] = 1; //mark as visited
    disc[node] = low[node] = timer++; //initially low and disc are same for a node
    
    for(auto adj : adjList[node]){
        //if adjacent is parent then ignore it
        if(adj == parent) continue;
        //if not visited then call dfs for it's adjacent. update low and check for bridge
        else if(!vis[adj]){
            dfs(adj, node, timer, disc, low, result, vis, adjList);
            low[node] = min(low[node], low[adj]);
            //check for bridge
            if(low[adj] > disc[node]){
                result.push_back({adj, node}); 
            }
        } else {
            //back edge
            low[node] = min(low[node], disc[adj]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int, list<int> > adjList;
    for(auto e : edges){
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }
    
    vector<int> low(v,-1); //lowest discovery time
    int parent = -1;
    vector<int> disc(v, -1); //discovery
    unordered_map<int, bool> vis; //visited or not
    
    int timer = 0;
    vector<vector<int>> result;
    for(int i = 0; i <v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, result, vis, adjList);
        }
    }
    return result;
}
```