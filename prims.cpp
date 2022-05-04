#include <bits/stdc++.h>
using namespace std;

#define V 5 // valid nodes will be 0 1 2 3

int extract_min(int mwt[], bool mst[])
{
    int index = -1;

    for (int i = 0; i < V; i++)
    {
        if (mst[i] == false && (index == -1 || mwt[i] < mwt[index]))
            index = i;
    }

    return index;
}

void prims(int adj[V][V])
{
    int result[V];
    for (int i = 0; i < V; i++)
    {
        result[i] = -1;
    }

    bool mst[V];
    for (int i = 0; i < V; i++)
    {
        mst[i] = false;
    }

    int mwt[V];
    for (int i = 0; i < V; i++)
    {
        mwt[i] = INT_MAX;
    }

    for (int i = 0; i < V - 1; i++)
    {
        int minV = extract_min(mwt, mst);
        mst[minV] = true;

        for (int j = 0; j < V; j++)
        {
            //checking for all adj of minV and which are not part of mst
            if (adj[minV][j] > 0 && mst[j] == false)
            {
                //if weight of minV and its adj is smaller than previous, then update
                if (adj[minV][j] < mwt[j])
                {
                    result[j] = minV;
                    mwt[j] = adj[minV][j];
                }
            }
        }
    }

    for (int i = 1; i < V; i++)
    {
        cout << result[i] << " to " << i << "\n";
    }
}

int main()
{
    int adj[V][V] = {{0, 2, 0, 6, 0},
                     {2, 0, 3, 8, 5},
                     {0, 3, 0, 0, 7},
                     {6, 8, 0, 0, 9},
                     {0, 5, 7, 9, 0}};

    prims(adj);

    return 0;
}