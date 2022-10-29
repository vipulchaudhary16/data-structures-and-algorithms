# [ Prim's MST ](https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //creating adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for(auto edge : g){
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }
    
    //required data structures
    vector<int> key(n+1, INT_MAX); //for min weight 
    vector<bool> mst(n+1, false); //for node is part of mst or not
    vector<int> parent(n+1, -1); //for track of parent
    
    key[1] = 0; //starting with 1
    
    //starting node is 1
    for(int i = 1; i < n; i++){
        int mini = INT_MAX; //minimum weight
        int u; //minimum weighted node index
        for(int v = 1; v<=n; v++){
            //not part of mst and having minimum weighted node will be selected
            if(mst[v] == false and key[v] < mini){
                u = v;
                mini = key[v];
            }
        }
        
        //add node into mst, mark true
        mst[u] = true;
        
        for(auto adj : adjList[u]){
            int v = adj.first;
            int w = adj.second;
            //if not part of mst and it has less weight than previous
            if(mst[v] == false and w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    //storing answer
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2;  i<= n; i++){
        ans.push_back({{parent[i], i}, key[i]});
    }
    
    return ans;
}

```