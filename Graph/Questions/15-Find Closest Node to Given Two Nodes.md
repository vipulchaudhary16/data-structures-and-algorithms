### [Find Closest Node to Given Two Nodes](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/)

```cpp
class Solution {
public:
    void dfs(int node, vector<int> &edges, vector<int> &distance, int currDistance, vector<bool> &visited){
        if(node != -1 and !visited[node]){ //node should be reachable and not visited previously, as this graph may contain cycle
            visited[node] = true;
            distance[node] = currDistance; //we are doing dfs so distance will be height
            dfs(edges[node], edges, distance, currDistance+1, visited); //call for dfs
        }
        
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> distanceFromNode1(n, -1), distanceFromNode2(n, -1);
        vector<bool> visited(n, false);
        dfs(node1, edges, distanceFromNode1, 0, visited);
        visited = vector<bool> (n, false);
        dfs(node2, edges, distanceFromNode2, 0, visited);
        
        int ansNode = -1;
        int minDistance = n;
        for(int i = 0; i < n; i++){
            if(distanceFromNode1[i] != -1 and distanceFromNode2[i] != -1){ //node should be reachable
                int currMax = max(distanceFromNode1[i], distanceFromNode2[i]);
                if(currMax < minDistance){
                    minDistance = currMax;
                    ansNode = i;
                }
            }
        }
        
        return ansNode;
    }
};
```