#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int w){
        adjList[u].push_back({v, w});
    }

    void printAdjList()
    {
        for (auto item : adjList)
        {
            cout << item.first << " -> ";
            for (auto pairr : item.second)
                cout << "(" << pairr.first << "," << pairr.second << "), ";
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[node] = true;

        for (auto adj : adjList[node])
        {
            if (!visited[adj.first])
                this->dfs(adj.first, visited, st);
        }

        st.push(node);
    }

    void printTopologicalSort(stack<int> st)
    {
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }

    void getShortestPaths(int src, int n, stack<int> topologicalSort)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!topologicalSort.empty())
        {
            int top = topologicalSort.top();
            topologicalSort.pop();

            if (dist[top] != INT_MAX)
            {
                for (auto i : adjList[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                        dist[i.first] = dist[top] + i.second;
                }
            }
        }

        for (int i = 0; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                cout << src << " -> " << i << " = "
                     << "infinity\n";
            else
                cout << src << " -> " << i << " = " << dist[i] << "\n";
        }
        cout << "\n";
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 5, 12);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 8);
    g.addEdge(4, 5, 5);
    // g.printAdjList();

    int n = 5;
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            g.dfs(i, visited, st);
    }
    g.printTopologicalSort(st);

    int source = 4;
    g.getShortestPaths(source, n, st);
    return 0;
}