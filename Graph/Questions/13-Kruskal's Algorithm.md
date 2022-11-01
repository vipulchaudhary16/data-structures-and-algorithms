# [Kruskal's Algorithm](https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include<bits/stdc++.h>

int findParent(int node, vector<int> &parent){
    if(parent[node] == node){
        return parent[node];
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    int parent_u = findParent(u, parent);
    int parent_v = findParent(v, parent);
    
    if(rank[parent_u] == rank[parent_v]){
        parent[u] = v;
        rank[v]++;
    } else if(rank[parent_u] < rank[parent_v]){
        parent[parent_u] = parent_v;
    } else {
        parent[parent_v] = parent_u;
    }
}

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i = 0; i <n; i++) parent[i] = i;
    
    sort(edges.begin(), edges.end(), cmp);
    
    int ans = 0;
    for(int i = 0; i < edges.size(); i++){
        int u = findParent(edges[i][0], parent);
        int v = findParent(edges[i][1], parent);
        
        if(u != v){
            ans += edges[i][2];
            unionSet(u,v,parent, rank);
        }
    }
    return ans;
}
```