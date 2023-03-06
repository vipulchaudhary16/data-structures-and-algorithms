### [Bellman Ford](https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1, 1e9);
    dist[src]=0;
    
    for(int i = 1; i <= n ; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if((dist[u]+wt < dist[v])  and dist[u] != 1e9){
                dist[v] = dist[u]+wt;
            }
        }
    }

    //check for negative cycle
    int flag = 0;
    for(int i = 1; i <=n ; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if((dist[u]+wt) < dist[v] and dist[u] != 1e9){
                flag = 1;
            }
        }
    }

    return dist[dest];

}