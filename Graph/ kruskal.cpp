#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int source, dest, weight;
};

bool cmp(Edge &a, Edge &b) { return a.weight < b.weight; }

int getSet(int node , int vertexSet[]){
    if(node == vertexSet[node])
        return node;
    else 
        return getSet(vertexSet[node] , vertexSet);
}

vector<Edge> kruskal_mst(vector<Edge> graph, int n)
{
    int vertexSet[n];

    for (int i = 0; i < n; i++) 
        vertexSet[i] = i;

    sort(graph.begin(), graph.end(), cmp);

    int count = 0 , i = 0;

    vector<Edge> res;

    while(count < n-1){
        Edge currEdge = graph[i];
        
        int uset = getSet(currEdge.source , vertexSet);
        int vset = getSet(currEdge.dest , vertexSet);

        if(uset != vset){
            res.emplace_back(currEdge);
            count++;
            vertexSet[vset] = uset;
        }
        i++;
    }

    return res;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> graph(e);

    for (int i = 0; i < e; i++)
        cin >> graph[i].source >> graph[i].dest >> graph[i].weight;

    vector<Edge> res = kruskal_mst(graph, n);

    for (auto edge : res)
        cout << edge.source << " To " << edge.dest << " weight " << edge.weight << "\n";

    return 0;
}