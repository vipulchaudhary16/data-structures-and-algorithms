#include <bits/stdc++.h>
using namespace std;

struct item
{
    int value;
    int weight;
};

bool cmp(item a, item b)
{
    return ( (double) a.value / (double) a.weight) > ( (double) b.value / (double) b.weight);
}

double fractional_knapsack(item arr[], int cap, int n)
{
    sort(arr, arr + n, cmp);
    double profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= cap)
        {
            profit += arr[i].value;
            cap -= arr[i].weight;
        }
        else
        {
            profit += arr[i].value * ((double) cap / (double) arr[i].weight);
            break;
        }
    }

    return profit;
}

int main()
{
    int n;
    cout << "How many items are there ?\n";
    cin >> n;

    item available[n];

    int cap;
    cout << "What is capasity of knapsack?\n";
    cin >> cap;

    int input;

    cout << "Now enter value of all items :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        available[i].value = input;
    }

    cout << "Now enter weight of all items :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        available[i].weight = input;
    }

    cout << "The max profit You can make is : " << fractional_knapsack(available, cap, n);

    return 0;
}