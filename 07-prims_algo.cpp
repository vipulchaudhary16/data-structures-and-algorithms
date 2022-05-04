#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int **adjMat;
    int nodes;

public:
    Graph(int nodes)
    {
        this->nodes = nodes;
        this->adjMat = new int *[nodes];

        for (int i = 0; i < this->nodes; i++)
        {
            adjMat[i] = new int[nodes];

            for (int j = 0; j < this->nodes; j++)
            {
                adjMat[i][j] = 0;
            }
        }
    }

    void add_edge(int u, int v, int weight)
    {
        adjMat[u][v] = weight;
        adjMat[v][u] = weight;
    }

    void print_adj()
    {
        for (int i = 0; i < this->nodes; i++)
        {

            for (int j = 0; j < this->nodes; j++)
            {
                cout << adjMat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    int minWt(int min_weight[], bool mst[])
    {
        int index = -1;

        for (int i = 0; i < this->nodes; i++)
        {
            if (mst[i] == false && (index == -1 || min_weight[index] > min_weight[i]))
                index = i;
        }

        return index;
    }

    void prims_algo()
    {
        int result[this->nodes];
        for (int i = 0; i < this->nodes; i++)
        {
            result[i] = -1;
        }

        bool mst[this->nodes];
        for (int i = 0; i < this->nodes; i++)
        {
            mst[i] = false;
        }

        int min_weight[this->nodes];
        for (int i = 0; i < this->nodes; i++)
        {
            min_weight[i] = INT_MAX;
        }

        for (int i = 0; i < this->nodes - 1; i++)
        {
            int minV = minWt(min_weight, mst);
            mst[minV] = true;

            for (int j = 0; j < this->nodes; j++)
            {

                if (adjMat[minV][j] > 0 && mst[j] == false)
                {
                    if (min_weight[j] > adjMat[minV][j])
                    {
                        result[j] = minV;
                        min_weight[j] = adjMat[minV][j];
                    }
                }
            }
        }

        int minCost = 0;
        for (int i = 1; i < this->nodes; i++)
        {
            minCost += adjMat[i][result[i]];
            cout << result[i] << " to " << i << " Weight is : " << adjMat[i][result[i]] << "\n";
        }
        cout << "Total Cost : " << minCost << "\n";
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    Graph graph(n);

    for (int i = 0; i < e; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        graph.add_edge(v, u, w);
    }

    graph.prims_algo();

    return 0;
}