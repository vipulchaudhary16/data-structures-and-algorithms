#include <bits/stdc++.h>
using namespace std;

#define V 5
#define infinity 9999

void dijkstra(int adj[V][V], int n, int startNode)
{
    int cost[V][V];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = adj[i][j];
        }
    }

    int distance[V], pred[V];

    for (int i = 0; i < n; i++)
    {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
    }

    bool visited[V];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // start traversing from starting node
    distance[startNode] = 0;
    visited[startNode] = true;

    int count = 1;

    while (count < n - 1)
    {
        int minDistance = infinity;
        int nextNode;

        for (int i = 0; i < n; i++)
        {
            if (distance[i] < minDistance && visited[i] == false)
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = true;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                if (minDistance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }
        count++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != startNode)
        {
            cout << "\ndistance of node " << i <<" = "<< distance[i];
            cout << " : Path = " << i;
            int j = i;
            do
            {
                j = pred[j];
                cout << " <- " << j;
            } while (j != startNode);
        }
    }
}

int main()
{
    int G[V][V] = {{0, 1, 0, 3, 10}, {1, 0, 5, 0, 0}, {0, 5, 0, 2, 1}, {3, 0, 2, 0, 6}, {10, 0, 1, 6, 0}};
    dijkstra(G, 5, 0);

    return 0;
}