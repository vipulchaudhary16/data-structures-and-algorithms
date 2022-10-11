#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // thats no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[][101],int target,int op,vector<int>& color){
        for(int i=0;i<101;i++){
            if(graph[target][i]==1){
                if(color[i]==op) return false;
            }
        }
        return true;
    }
    bool solve(bool graph[101][101],int v, int m, int n,vector<int> &color){
        if(v==n) return true;
        for(int op = 1;op<=m;op++){
            if(isSafe(graph,v,op,color)){
                color[v] = op;
                bool sol= solve(graph,v+1,m,n,color);
                if(sol) return true;
                color[v] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,0);
        return solve(graph,0,m,n,color);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
