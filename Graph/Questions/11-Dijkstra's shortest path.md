# [ Dijkstra's shortest path ](https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create adj list
    unordered_map<int, list<pair<int, int> > >adjList;
    for(auto edge : vec){
        adjList[edge[0]].push_back({edge[1], edge[2]});
        adjList[edge[1]].push_back({edge[0], edge[2]});
    }
    
    //find answer vector
    vector<int> dist(vertices, INT_MAX);
    
    set<pair<int, int> > st; //{distance, node};
    dist[source] = 0;
    st.insert({0,source});
    
    while(!st.empty()){
        //find the node with min distance
        auto top = * (st.begin());
        int nodeDist = top.first;
        int topNode = top.second;
        
        //remove the node from set
        st.erase(st.begin());
        
        //neighbours
        for(auto neighbour : adjList[topNode]){
            //neighbour = {node, weight}
            if(nodeDist + neighbour.second < dist[neighbour.first]){
                //remove the old pair if present
                auto record = st.find({dist[neighbour.first], neighbour.first});
                if(record != st.end()){
                    st.erase(record);
                }
                //update the distance
                dist[neighbour.first] = nodeDist + neighbour.second;
                //insert the new pair
                st.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }
    return dist;
}
```