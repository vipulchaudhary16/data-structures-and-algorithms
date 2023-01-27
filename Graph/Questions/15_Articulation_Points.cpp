#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<int> &res, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    disc[node] = low[node] = timer;
    timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
            continue;
        else if (!visited[nbr])
        {
            dfs(nbr, node, timer, disc, low, res, visited, adj);
            low[node] = min(low[node], low[nbr]);
            if (low[nbr] >= disc[node] and parent != -1)
                res.push_back(node);
        }
        else
            low[node] = min(low[node], disc[nbr]);
    }
    if (parent == -1 and adj[node].size() > 1)
        res.push_back(node);
}

vector<int> findArticulationPoints(int e, int v, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adjList;
    for (auto e : edges)
    {
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }

    vector<int> low(v, -1); // lowest discovery time
    int parent = -1;
    vector<int> disc(v, -1);      // discovery
    unordered_map<int, bool> vis; // visited or not

    int timer = 0;
    vector<int> result;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, result, vis, adjList);
        }
    }

    for (auto ap : result)
        cout << ap << " ";

    return result;
}

int main()
{
    vector<vector<int>> G{{0, 1}, {0, 3}, {0, 4}, {1, 2}, {3, 4}};
    findArticulationPoints(5, 5, G);
    return 0;
}