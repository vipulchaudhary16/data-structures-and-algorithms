# [ BFS in Undirected Graph ](https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include <bits/stdc++.h> 
void prepareAdjList(unordered_map <int, set<int> > &adjList , vector<pair<int, int>> &edges)
{
   for(int i = 0 ; i < edges.size() ; i++){
       int u = edges[i].first; 
       int v = edges[i].second; 
       
       adjList[u].insert(v);
       adjList[v].insert(u);        
   }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map <int, set<int> > adjList ; 
    vector <int> ans ; 
    unordered_map <int , bool> visited ;
   
    prepareAdjList(adjList , edges) ;
    for (int node = 0 ; node < vertex ; node++ )
    {
       if(!visited[node] )
       {
            queue <int> q ; 
            q.push(node);
            visited[node] = 1; 
   
            while (!q.empty()){
                int frontNode = q.front() ;
                q.pop() ;
                ans.push_back(frontNode) ;
                for (auto i : adjList[frontNode]) {
                    if (!visited[i]){
                        q.push(i) ;
                        visited[i] = 1 ; 
                    }
                }
            }
       }
   }  
    return ans ; 
}
```