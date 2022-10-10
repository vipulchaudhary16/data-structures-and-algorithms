#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adj;
    int isDirected;

    Graph(int direction)
    {
        this->isDirected = direction;
    }

    void addEdge(T u, T v)
    {
        this->adj[u].push_back(v);
        if (!isDirected)
            this->adj[v].push_back(u);
    }

    void printAdj()
    {
        for (auto node : adj)
        {
            cout << node.first << " -> ";
            for (auto e : node.second)
                cout << e << " ";
            cout << "\n";
        }
    }
};

int main()
{
    int directed;
    cout << "Enter 1 for Directed Graph and 0 for Undirected Graph ";
    cin >> directed;

    Graph<char> *g = new Graph<char>(directed);

    int n;
    cout << "Enter the number of nodes ";
    cin >> n;

    int m;
    cout << "Enter the number of edges ";
    cin >> m;

    cout << "Enter all edges space seprated\n";

    for (int i = 0; i < m; i++)
    {
        char u, v;
        cin >> u >> v;
        g->addEdge(u, v);
    }

    g->printAdj();
    return 0;
}